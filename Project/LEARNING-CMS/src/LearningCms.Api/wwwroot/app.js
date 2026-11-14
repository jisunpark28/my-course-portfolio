const api = "/api/notes";

const searchForm = document.getElementById("search-form");
const searchInput = document.getElementById("search-input");
const resetSearch = document.getElementById("reset-search");
const results = document.getElementById("results");
const importForm = document.getElementById("import-form");
const markdownInput = document.getElementById("markdown-input");
const fileInput = document.getElementById("file-input");
const detailPanel = document.getElementById("detail-panel");
const detailTopic = document.getElementById("detail-topic");
const detailTags = document.getElementById("detail-tags");
const detailBlocks = document.getElementById("detail-blocks");
const editForm = document.getElementById("edit-form");
const editTopic = document.getElementById("edit-topic");
const editGroups = document.getElementById("edit-groups");
const editTags = document.getElementById("edit-tags");
const editMarkdown = document.getElementById("edit-markdown");
const editBtn = document.getElementById("edit-btn");
const deleteBtn = document.getElementById("delete-btn");
const closeDetail = document.getElementById("close-detail");
const resultTemplate = document.getElementById("result-template");

let selectedNote = null;

searchForm.addEventListener("submit", async (event) => {
  event.preventDefault();
  await loadResults(searchInput.value.trim());
});

resetSearch.addEventListener("click", async () => {
  searchInput.value = "";
  await loadResults();
});

importForm.addEventListener("submit", async (event) => {
  event.preventDefault();
  const markdown = markdownInput.value.trim();
  if (!markdown) return;

  const response = await fetch(`${api}/import`, {
    method: "POST",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify({ markdown }),
  });

  if (!response.ok) {
    alert("Import failed");
    return;
  }

  markdownInput.value = "";
  await loadResults();
});

fileInput.addEventListener("change", async () => {
  const file = fileInput.files?.[0];
  if (!file) return;

  const formData = new FormData();
  formData.append("file", file);

  const response = await fetch(`${api}/import-file`, {
    method: "POST",
    body: formData,
  });

  fileInput.value = "";
  if (!response.ok) {
    alert("File import failed");
    return;
  }

  await loadResults();
});

editBtn.addEventListener("click", () => {
  if (!selectedNote) return;
  editTopic.value = selectedNote.topic;
  editGroups.value = (selectedNote.groups || []).join(", ");
  editTags.value = (selectedNote.tags || []).join(", ");
  editMarkdown.value = selectedNote.rawMarkdown || blocksToMarkdown(selectedNote.blocks);
  editForm.classList.remove("hidden");
});

editForm.addEventListener("submit", async (event) => {
  event.preventDefault();
  if (!selectedNote?.id) return;

  const payload = {
    topic: editTopic.value.trim(),
    groups: editGroups.value
      .split(",")
      .map((group) => group.trim())
      .filter(Boolean),
    tags: editTags.value
      .split(",")
      .map((tag) => tag.trim())
      .filter(Boolean),
    rawMarkdown: editMarkdown.value,
    blocks: selectedNote.blocks,
  };

  const response = await fetch(`${api}/${selectedNote.id}`, {
    method: "PUT",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify(payload),
  });

  if (!response.ok) {
    alert("Update failed");
    return;
  }

  const updated = await response.json();
  selectedNote = updated;
  renderDetail(updated);
  editForm.classList.add("hidden");
  await loadResults(searchInput.value.trim());
});

deleteBtn.addEventListener("click", async () => {
  if (!selectedNote?.id) return;
  if (!confirm(`"${selectedNote.topic}" 삭제할까요?`)) return;

  const response = await fetch(`${api}/${selectedNote.id}`, { method: "DELETE" });
  if (!response.ok) {
    alert("Delete failed");
    return;
  }

  selectedNote = null;
  detailPanel.classList.add("hidden");
  await loadResults(searchInput.value.trim());
});

closeDetail.addEventListener("click", () => {
  detailPanel.classList.add("hidden");
  selectedNote = null;
});

async function loadResults(query = "") {
  const url = query ? `${api}?q=${encodeURIComponent(query)}` : api;
  const response = await fetch(url);
  const notes = await response.json();
  renderResults(notes);
}

function renderResults(notes) {
  results.replaceChildren();

  if (!notes.length) {
    const empty = document.createElement("li");
    empty.textContent = "결과 없음";
    empty.className = "empty";
    results.appendChild(empty);
    return;
  }

  for (const note of notes) {
    const node = resultTemplate.content.cloneNode(true);
    node.querySelector(".result-topic").textContent = note.topic;
    node.querySelector(".result-groups").textContent = contextLabel(note);
    node.querySelector(".result-preview").textContent = preview(note);
    node.querySelector(".result-item").addEventListener("click", () => openDetail(note.id));
    results.appendChild(node);
  }
}

async function openDetail(id) {
  const response = await fetch(`${api}/${id}`);
  if (!response.ok) return;
  const note = await response.json();
  selectedNote = note;
  renderDetail(note);
  detailPanel.classList.remove("hidden");
  editForm.classList.add("hidden");
}

function renderDetail(note) {
  const context = contextLabel(note);
  detailTopic.textContent = context ? `${note.topic}  ·  ${context}` : note.topic;
  detailTags.replaceChildren();

  for (const tag of note.tags || []) {
    const chip = document.createElement("span");
    chip.className = "tag";
    chip.textContent = tag;
    detailTags.appendChild(chip);
  }

  detailBlocks.replaceChildren();
  for (const block of note.blocks || []) {
    detailBlocks.appendChild(renderBlock(block));
  }
}

function renderBlock(block) {
  const wrapper = document.createElement("article");
  wrapper.className = `block block-${block.type}`;

  if (block.title) {
    const title = document.createElement("h3");
    title.textContent = block.title;
    wrapper.appendChild(title);
  }

  if (block.type === "code") {
    const pre = document.createElement("pre");
    const code = document.createElement("code");
    code.textContent = block.body || "";
    if (block.language) code.className = `language-${block.language}`;
    pre.appendChild(code);
    wrapper.appendChild(pre);
    return wrapper;
  }

  if (block.type === "list" && block.items?.length) {
    const ul = document.createElement("ul");
    for (const item of block.items) {
      const li = document.createElement("li");
      li.textContent = item;
      ul.appendChild(li);
    }
    wrapper.appendChild(ul);
    return wrapper;
  }

  const body = document.createElement("div");
  body.className = "text-body";
  body.textContent = block.body || "";
  wrapper.appendChild(body);
  return wrapper;
}

function contextLabel(note) {
  return (note.groups || []).filter(Boolean).join(" · ");
}

function preview(note) {
  const first = note.blocks?.find((block) => block.body)?.body || note.searchableText || "";
  return first.length > 100 ? `${first.slice(0, 100)}...` : first;
}

function blocksToMarkdown(blocks = []) {
  return blocks
    .map((block) => {
      if (block.type === "code") {
        return `\`\`\`${block.language || ""}\n${block.body || ""}\n\`\`\``;
      }
      return block.body || "";
    })
    .join("\n\n");
}

loadResults();
