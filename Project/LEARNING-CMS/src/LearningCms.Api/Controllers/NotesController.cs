using LearningCms.Api.Models;
using LearningCms.Api.Services;
using Microsoft.AspNetCore.Mvc;

namespace LearningCms.Api.Controllers;

// HTML의 fetch()가 호출하는 CRUD 주소.
// Create = POST, Read = GET, Update = PUT, Delete = DELETE
[ApiController]
[Route("api/notes")]
public class NotesController : ControllerBase
{
    private readonly INoteService _notes;

    public NotesController(INoteService notes)
    {
        _notes = notes;
    }

    // Read: 검색 또는 전체 목록
    [HttpGet]
    public async Task<ActionResult<List<Note>>> Search([FromQuery] string? q, CancellationToken cancellationToken)
    {
        var results = await _notes.SearchAsync(q, cancellationToken);
        return Ok(results);
    }

    // Read: 노트 하나
    [HttpGet("{id}")]
    public async Task<ActionResult<Note>> GetById(string id, CancellationToken cancellationToken)
    {
        var note = await _notes.GetByIdAsync(id, cancellationToken);
        return note is null ? NotFound() : Ok(note);
    }

    // Create: textarea Markdown 저장
    [HttpPost("import")]
    public async Task<ActionResult<Note>> ImportMarkdown([FromBody] ImportMarkdownRequest request, CancellationToken cancellationToken)
    {
        if (string.IsNullOrWhiteSpace(request.Markdown))
        {
            return BadRequest(new { message = "Markdown body is required." });
        }

        var note = await _notes.ImportMarkdownAsync(request.Markdown, cancellationToken);
        return CreatedAtAction(nameof(GetById), new { id = note.Id }, note);
    }

    // Create: notes/*.md 파일 upload
    [HttpPost("import-file")]
    public async Task<ActionResult<Note>> ImportMarkdownFile(IFormFile file, CancellationToken cancellationToken)
    {
        if (file.Length == 0)
        {
            return BadRequest(new { message = "Empty file." });
        }

        await using var stream = file.OpenReadStream();
        using var reader = new StreamReader(stream);
        var markdown = await reader.ReadToEndAsync(cancellationToken);
        var note = await _notes.ImportMarkdownAsync(markdown, cancellationToken);
        return CreatedAtAction(nameof(GetById), new { id = note.Id }, note);
    }

    // Update
    [HttpPut("{id}")]
    public async Task<ActionResult<Note>> Update(string id, [FromBody] NoteUpdateRequest request, CancellationToken cancellationToken)
    {
        var note = await _notes.UpdateAsync(id, request, cancellationToken);
        return note is null ? NotFound() : Ok(note);
    }

    // Delete
    [HttpDelete("{id}")]
    public async Task<IActionResult> Delete(string id, CancellationToken cancellationToken)
    {
        var deleted = await _notes.DeleteAsync(id, cancellationToken);
        return deleted ? NoContent() : NotFound();
    }
}
