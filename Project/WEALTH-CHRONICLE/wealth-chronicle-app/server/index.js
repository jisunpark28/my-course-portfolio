import cors from 'cors';
import crypto from 'node:crypto';
import express from 'express';
import fs from 'node:fs/promises';
import { existsSync } from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import multer from 'multer';
import 'dotenv/config';

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);
const rootDir = path.resolve(__dirname, '..');
const dataDir = path.join(rootDir, 'data');
const uploadsDir = path.join(rootDir, 'uploads');
const logsFilePath = path.join(dataDir, 'logs.json');

const PORT = Number(process.env.PORT ?? 4000);
const CLIENT_ORIGIN = process.env.CLIENT_ORIGIN ?? 'http://localhost:5173';
const INSTAGRAM_API_BASE =
  process.env.INSTAGRAM_API_BASE ?? 'https://graph.facebook.com/v22.0';
const PUBLIC_BASE_URL = process.env.PUBLIC_BASE_URL ?? `http://localhost:${PORT}`;

const app = express();

const uploadStorage = multer.diskStorage({
  destination: (_req, _file, callback) => {
    callback(null, uploadsDir);
  },
  filename: (_req, file, callback) => {
    const ext = path.extname(file.originalname) || '.jpg';
    callback(null, `${Date.now()}-${crypto.randomUUID()}${ext}`);
  },
});

const upload = multer({
  storage: uploadStorage,
  fileFilter: (_req, file, callback) => {
    if (!file.mimetype.startsWith('image/')) {
      callback(new Error('Only image files are supported.'));
      return;
    }
    callback(null, true);
  },
  limits: {
    fileSize: 10 * 1024 * 1024,
  },
});

app.use(cors({ origin: CLIENT_ORIGIN }));
app.use(express.json({ limit: '5mb' }));
app.use('/uploads', express.static(uploadsDir));

function toIsoDateString(value) {
  if (!value) return '';
  const parsed = new Date(value);
  if (Number.isNaN(parsed.getTime())) return '';
  return parsed.toISOString().slice(0, 10);
}

function dateToReadable(value) {
  if (!value) return 'No date selected';
  const parsed = new Date(value);
  if (Number.isNaN(parsed.getTime())) return value;
  return parsed.toLocaleDateString('en-US', {
    month: 'long',
    day: 'numeric',
    year: 'numeric',
  });
}

function parseTags(rawTags) {
  if (!rawTags) return [];
  if (Array.isArray(rawTags)) {
    return rawTags
      .map((tag) => String(tag).trim())
      .filter(Boolean)
      .map((tag) => tag.replace(/^#/, ''));
  }

  const parsed = String(rawTags);
  if (parsed.startsWith('[') && parsed.endsWith(']')) {
    try {
      const fromJson = JSON.parse(parsed);
      if (Array.isArray(fromJson)) {
        return fromJson
          .map((tag) => String(tag).trim())
          .filter(Boolean)
          .map((tag) => tag.replace(/^#/, ''));
      }
    } catch (_error) {
      // Fall back to comma-based parsing.
    }
  }

  return parsed
    .split(',')
    .map((tag) => tag.trim())
    .filter(Boolean)
    .map((tag) => tag.replace(/^#/, ''));
}

function createCaption(log) {
  const tagText = (log.tags ?? []).map((tag) => `#${tag}`).join(' ');

  return [
    `[${log.chronicleTitle}: Vol. ${log.volumeNumber}]`,
    `Entry ${log.entryNumber}: ${log.entryTitle}`,
    '',
    `Date: ${dateToReadable(log.date)}`,
    '',
    'Log Details:',
    `Activity: ${log.activity || 'Not provided'}`,
    log.factStatus ? `Fact: ${log.factStatus}` : null,
    log.process ? `Process: ${log.process}` : null,
    `Child Reaction: ${log.childReaction || 'Not provided'}`,
    log.childQuote ? `Child Quote: "${log.childQuote}"` : null,
    `Analyst Comment: ${log.analystComment || 'Not provided'}`,
    tagText || null,
  ]
    .filter(Boolean)
    .join('\n');
}

function mapPayloadToLog(payload, existingLog = {}) {
  const nowIso = new Date().toISOString();
  const nextEntryNumber = Number(payload.entryNumber ?? existingLog.entryNumber ?? 1);
  const nextVolumeNumber = Number(payload.volumeNumber ?? existingLog.volumeNumber ?? 1);

  return {
    id: existingLog.id ?? crypto.randomUUID(),
    chronicleTitle:
      payload.chronicleTitle?.trim() ||
      existingLog.chronicleTitle ||
      "My Child's Wealth Chronicle",
    volumeNumber: Number.isFinite(nextVolumeNumber) ? nextVolumeNumber : 1,
    entryNumber: Number.isFinite(nextEntryNumber) ? nextEntryNumber : 1,
    entryTitle: payload.entryTitle?.trim() || existingLog.entryTitle || 'New Milestone',
    date: toIsoDateString(payload.date) || existingLog.date || '',
    photoDescription:
      payload.photoDescription?.trim() || existingLog.photoDescription || 'Chronicle image',
    activity: payload.activity?.trim() || existingLog.activity || '',
    factStatus: payload.factStatus?.trim() || existingLog.factStatus || '',
    process: payload.process?.trim() || existingLog.process || '',
    childReaction: payload.childReaction?.trim() || existingLog.childReaction || '',
    childQuote: payload.childQuote?.trim() || existingLog.childQuote || '',
    analystComment: payload.analystComment?.trim() || existingLog.analystComment || '',
    tags: parseTags(payload.tags ?? existingLog.tags ?? []),
    photoUrl: payload.photoUrl ?? existingLog.photoUrl ?? '',
    instagram: existingLog.instagram ?? null,
    createdAt: existingLog.createdAt ?? nowIso,
    updatedAt: nowIso,
  };
}

async function ensureStorage() {
  if (!existsSync(dataDir)) {
    await fs.mkdir(dataDir, { recursive: true });
  }
  if (!existsSync(uploadsDir)) {
    await fs.mkdir(uploadsDir, { recursive: true });
  }
  if (!existsSync(logsFilePath)) {
    await fs.writeFile(logsFilePath, '[]\n', 'utf-8');
  }
}

async function readLogs() {
  const raw = await fs.readFile(logsFilePath, 'utf-8');
  const parsed = JSON.parse(raw);
  if (!Array.isArray(parsed)) {
    return [];
  }
  return parsed.sort((a, b) => new Date(b.date) - new Date(a.date));
}

async function writeLogs(logs) {
  await fs.writeFile(logsFilePath, `${JSON.stringify(logs, null, 2)}\n`, 'utf-8');
}

async function removeFileByUrl(fileUrl) {
  if (!fileUrl || !fileUrl.startsWith('/uploads/')) {
    return;
  }
  const normalizedPath = fileUrl.replace(/^\/+/, '');
  const target = path.join(rootDir, normalizedPath);
  try {
    await fs.unlink(target);
  } catch (_error) {
    // If the file was already removed, we can continue safely.
  }
}

async function callGraphApi(endpoint, body) {
  const response = await fetch(endpoint, {
    method: 'POST',
    headers: {
      'Content-Type': 'application/x-www-form-urlencoded',
    },
    body: new URLSearchParams(body),
  });

  const payload = await response.json();
  if (!response.ok) {
    throw new Error(payload?.error?.message ?? 'Instagram API request failed.');
  }
  return payload;
}

app.get('/api/health', (_req, res) => {
  res.json({ ok: true });
});

app.get('/api/logs', async (req, res) => {
  const logs = await readLogs();
  const month = req.query.month ? String(req.query.month) : '';
  if (!month) {
    res.json(logs);
    return;
  }
  const filtered = logs.filter((log) => log.date?.startsWith(month));
  res.json(filtered);
});

app.post('/api/logs', upload.single('photo'), async (req, res) => {
  const logs = await readLogs();
  const photoUrl = req.file ? `/uploads/${req.file.filename}` : '';
  const draft = mapPayloadToLog({ ...req.body, photoUrl });

  if (!draft.date) {
    res.status(400).json({ message: 'A valid date is required.' });
    return;
  }

  logs.push(draft);
  await writeLogs(logs);
  res.status(201).json(draft);
});

app.put('/api/logs/:id', upload.single('photo'), async (req, res) => {
  const logs = await readLogs();
  const targetIndex = logs.findIndex((log) => log.id === req.params.id);

  if (targetIndex === -1) {
    res.status(404).json({ message: 'Log not found.' });
    return;
  }

  const previousLog = logs[targetIndex];
  const shouldRemovePhoto = req.body.removePhoto === 'true';
  const uploadedPhotoUrl = req.file ? `/uploads/${req.file.filename}` : null;

  let nextPhotoUrl = previousLog.photoUrl;
  if (uploadedPhotoUrl) {
    await removeFileByUrl(previousLog.photoUrl);
    nextPhotoUrl = uploadedPhotoUrl;
  } else if (shouldRemovePhoto) {
    await removeFileByUrl(previousLog.photoUrl);
    nextPhotoUrl = '';
  }

  const updatedLog = mapPayloadToLog(
    {
      ...req.body,
      photoUrl: nextPhotoUrl,
    },
    previousLog,
  );

  if (!updatedLog.date) {
    res.status(400).json({ message: 'A valid date is required.' });
    return;
  }

  logs[targetIndex] = updatedLog;
  await writeLogs(logs);
  res.json(updatedLog);
});

app.delete('/api/logs/:id', async (req, res) => {
  const logs = await readLogs();
  const targetIndex = logs.findIndex((log) => log.id === req.params.id);

  if (targetIndex === -1) {
    res.status(404).json({ message: 'Log not found.' });
    return;
  }

  const [removed] = logs.splice(targetIndex, 1);
  await removeFileByUrl(removed.photoUrl);
  await writeLogs(logs);

  res.json({ ok: true });
});

app.post('/api/logs/:id/upload-instagram', async (req, res) => {
  const logs = await readLogs();
  const targetIndex = logs.findIndex((log) => log.id === req.params.id);

  if (targetIndex === -1) {
    res.status(404).json({ message: 'Log not found.' });
    return;
  }

  const igUserId = process.env.IG_USER_ID;
  const igAccessToken = process.env.IG_ACCESS_TOKEN;

  if (!igUserId || !igAccessToken) {
    res.status(400).json({
      message:
        'Instagram is not configured. Please set IG_USER_ID and IG_ACCESS_TOKEN in your environment.',
    });
    return;
  }

  const selectedLog = logs[targetIndex];
  const imageUrl =
    req.body?.imageUrl ||
    (selectedLog.photoUrl ? `${PUBLIC_BASE_URL}${selectedLog.photoUrl}` : '');

  if (!imageUrl) {
    res.status(400).json({
      message:
        'No image URL found. Add a photo first or provide a public image URL for Instagram publishing.',
    });
    return;
  }

  try {
    const caption = createCaption(selectedLog);
    const createMediaResponse = await callGraphApi(
      `${INSTAGRAM_API_BASE}/${igUserId}/media`,
      {
        image_url: imageUrl,
        caption,
        access_token: igAccessToken,
      },
    );

    const publishResponse = await callGraphApi(
      `${INSTAGRAM_API_BASE}/${igUserId}/media_publish`,
      {
        creation_id: createMediaResponse.id,
        access_token: igAccessToken,
      },
    );

    logs[targetIndex] = {
      ...selectedLog,
      instagram: {
        mediaId: publishResponse.id,
        imageUrl,
        lastPublishedAt: new Date().toISOString(),
      },
      updatedAt: new Date().toISOString(),
    };
    await writeLogs(logs);

    res.json({
      ok: true,
      mediaId: publishResponse.id,
      imageUrl,
    });
  } catch (error) {
    res.status(502).json({
      message: error instanceof Error ? error.message : 'Failed to publish on Instagram.',
    });
  }
});

app.use((error, _req, res, _next) => {
  if (error instanceof multer.MulterError) {
    res.status(400).json({ message: error.message });
    return;
  }
  if (error instanceof Error) {
    res.status(500).json({ message: error.message });
    return;
  }
  res.status(500).json({ message: 'Unexpected server error.' });
});

await ensureStorage();
app.listen(PORT, () => {
  console.log(`Wealth Chronicle API listening on port ${PORT}`);
});
