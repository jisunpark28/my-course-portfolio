import { useEffect, useMemo, useState } from 'react';
import './App.css';

const WEEK_DAYS = ['Sun', 'Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat'];

function toIsoDate(date) {
  return date.toISOString().slice(0, 10);
}

function toMonthKey(date) {
  return date.toISOString().slice(0, 7);
}

function formatReadableDate(value) {
  if (!value) return 'No date selected';
  const parsed = new Date(value);
  if (Number.isNaN(parsed.getTime())) return value;
  return parsed.toLocaleDateString('en-US', {
    month: 'long',
    day: 'numeric',
    year: 'numeric',
  });
}

function formatMonthLabel(value) {
  return value.toLocaleDateString('en-US', {
    month: 'long',
    year: 'numeric',
  });
}

function getOrdinalNumber(value) {
  const number = Number(value);
  if (!Number.isFinite(number) || number <= 0) {
    return '1st';
  }
  const mod100 = number % 100;
  if (mod100 >= 11 && mod100 <= 13) return `${number}th`;

  switch (number % 10) {
    case 1:
      return `${number}st`;
    case 2:
      return `${number}nd`;
    case 3:
      return `${number}rd`;
    default:
      return `${number}th`;
  }
}

function buildMonthGrid(currentMonth) {
  const monthStart = new Date(
    currentMonth.getFullYear(),
    currentMonth.getMonth(),
    1,
  );
  const monthEnd = new Date(
    currentMonth.getFullYear(),
    currentMonth.getMonth() + 1,
    0,
  );

  const gridStart = new Date(monthStart);
  gridStart.setDate(gridStart.getDate() - gridStart.getDay());

  const gridEnd = new Date(monthEnd);
  gridEnd.setDate(gridEnd.getDate() + (6 - gridEnd.getDay()));

  const days = [];
  const cursor = new Date(gridStart);
  while (cursor <= gridEnd) {
    days.push({
      iso: toIsoDate(cursor),
      dayNumber: cursor.getDate(),
      isCurrentMonth: cursor.getMonth() === currentMonth.getMonth(),
    });
    cursor.setDate(cursor.getDate() + 1);
  }
  return days;
}

function createInitialForm(selectedDate) {
  return {
    chronicleTitle: "My Child's Wealth Chronicle",
    volumeNumber: 1,
    entryNumber: 1,
    entryTitle: 'The beginning of financial independence',
    date: selectedDate,
    photoDescription:
      'A first snapshot of four piggy banks (Save, Spend, Give, Invest).',
    activity: '',
    factStatus: '',
    process: '',
    childReaction: '',
    childQuote: '',
    analystComment: '',
    tags: 'allowance,save,spend,give,invest',
    photoFile: null,
    photoUrl: '',
    removePhoto: false,
    instagramImageUrl: '',
  };
}

function mapLogToForm(log) {
  return {
    chronicleTitle: log.chronicleTitle ?? "My Child's Wealth Chronicle",
    volumeNumber: log.volumeNumber ?? 1,
    entryNumber: log.entryNumber ?? 1,
    entryTitle: log.entryTitle ?? '',
    date: log.date ?? '',
    photoDescription: log.photoDescription ?? '',
    activity: log.activity ?? '',
    factStatus: log.factStatus ?? '',
    process: log.process ?? '',
    childReaction: log.childReaction ?? '',
    childQuote: log.childQuote ?? '',
    analystComment: log.analystComment ?? '',
    tags: (log.tags ?? []).join(','),
    photoFile: null,
    photoUrl: log.photoUrl ?? '',
    removePhoto: false,
    instagramImageUrl: '',
  };
}

async function parseError(response) {
  let message = 'Request failed.';
  try {
    const payload = await response.json();
    if (payload?.message) {
      message = payload.message;
    }
  } catch {
    // Keep generic fallback message.
  }
  return message;
}

function App() {
  const [displayMonth, setDisplayMonth] = useState(() => {
    const now = new Date();
    return new Date(now.getFullYear(), now.getMonth(), 1);
  });
  const [selectedDate, setSelectedDate] = useState(() => toIsoDate(new Date()));
  const [logs, setLogs] = useState([]);
  const [selectedLogId, setSelectedLogId] = useState(null);
  const [formState, setFormState] = useState(() => createInitialForm(toIsoDate(new Date())));
  const [isSaving, setIsSaving] = useState(false);
  const [isPublishingId, setIsPublishingId] = useState(null);
  const [statusMessage, setStatusMessage] = useState('Select a date and start your first record.');
  const [errorMessage, setErrorMessage] = useState('');

  useEffect(() => {
    const nextMonthKey = toMonthKey(displayMonth);
    const controller = new AbortController();

    async function loadLogs() {
      try {
        const response = await fetch(`/api/logs?month=${nextMonthKey}`, {
          signal: controller.signal,
        });
        if (!response.ok) {
          const message = await parseError(response);
          throw new Error(message);
        }

        const payload = await response.json();
        setLogs(payload);
      } catch (error) {
        if (error.name === 'AbortError') return;
        setErrorMessage(error.message ?? 'Unable to load logs.');
      }
    }

    loadLogs();
    return () => controller.abort();
  }, [displayMonth]);

  const logsByDate = useMemo(() => {
    return logs.reduce((accumulator, log) => {
      if (!log.date) return accumulator;
      if (!accumulator[log.date]) {
        accumulator[log.date] = [];
      }
      accumulator[log.date].push(log);
      return accumulator;
    }, {});
  }, [logs]);

  const selectedDateLogs = useMemo(() => {
    return logsByDate[selectedDate] ?? [];
  }, [logsByDate, selectedDate]);

  const monthGrid = useMemo(() => buildMonthGrid(displayMonth), [displayMonth]);

  const previewTags = useMemo(() => {
    return formState.tags
      .split(',')
      .map((tag) => tag.trim())
      .filter(Boolean)
      .map((tag) => tag.replace(/^#/, ''));
  }, [formState.tags]);

  const previewPhotoUrl = useMemo(() => {
    if (formState.photoFile) {
      return URL.createObjectURL(formState.photoFile);
    }
    if (formState.removePhoto) {
      return '';
    }
    return formState.photoUrl;
  }, [formState.photoFile, formState.photoUrl, formState.removePhoto]);

  useEffect(() => {
    if (!previewPhotoUrl || !previewPhotoUrl.startsWith('blob:')) return undefined;
    return () => URL.revokeObjectURL(previewPhotoUrl);
  }, [previewPhotoUrl]);

  function updateField(field, value) {
    setFormState((previous) => ({
      ...previous,
      [field]: value,
    }));
  }

  function resetFormForDate(nextDate, entryNumber = 1) {
    setSelectedLogId(null);
    setFormState((previous) => ({
      ...createInitialForm(nextDate),
      chronicleTitle: previous.chronicleTitle,
      volumeNumber: previous.volumeNumber,
      entryNumber,
    }));
  }

  function handleDateSelection(nextDate) {
    setSelectedDate(nextDate);
    const entries = logsByDate[nextDate] ?? [];
    resetFormForDate(nextDate, entries.length + 1);
  }

  function handleMonthMove(offset) {
    const nextMonth = new Date(
      displayMonth.getFullYear(),
      displayMonth.getMonth() + offset,
      1,
    );
    setDisplayMonth(nextMonth);
    const firstDateInMonth = toIsoDate(nextMonth);
    setSelectedDate(firstDateInMonth);
    resetFormForDate(firstDateInMonth, 1);
  }

  function handleFileChange(event) {
    const [nextFile] = event.target.files ?? [];
    if (!nextFile) return;
    setFormState((previous) => ({
      ...previous,
      photoFile: nextFile,
      removePhoto: false,
    }));
  }

  async function handleSaveLog(event) {
    event.preventDefault();
    setErrorMessage('');
    setStatusMessage('');
    setIsSaving(true);

    const payload = new FormData();
    payload.append('chronicleTitle', formState.chronicleTitle);
    payload.append('volumeNumber', String(formState.volumeNumber));
    payload.append('entryNumber', String(formState.entryNumber));
    payload.append('entryTitle', formState.entryTitle);
    payload.append('date', formState.date || selectedDate);
    payload.append('photoDescription', formState.photoDescription);
    payload.append('activity', formState.activity);
    payload.append('factStatus', formState.factStatus);
    payload.append('process', formState.process);
    payload.append('childReaction', formState.childReaction);
    payload.append('childQuote', formState.childQuote);
    payload.append('analystComment', formState.analystComment);
    payload.append('tags', formState.tags);
    payload.append('removePhoto', String(formState.removePhoto));

    if (formState.photoFile) {
      payload.append('photo', formState.photoFile);
    }

    const isEditing = Boolean(selectedLogId);
    const endpoint = isEditing ? `/api/logs/${selectedLogId}` : '/api/logs';
    const method = isEditing ? 'PUT' : 'POST';

    try {
      const response = await fetch(endpoint, {
        method,
        body: payload,
      });
      if (!response.ok) {
        const message = await parseError(response);
        throw new Error(message);
      }

      const savedLog = await response.json();
      setLogs((previousLogs) => {
        const withoutCurrent = previousLogs.filter((log) => log.id !== savedLog.id);
        return [...withoutCurrent, savedLog].sort(
          (left, right) => new Date(right.date) - new Date(left.date),
        );
      });
      setSelectedDate(savedLog.date);
      setSelectedLogId(savedLog.id);
      setFormState(mapLogToForm(savedLog));
      setStatusMessage('Saved to your personal calendar.');
    } catch (error) {
      setErrorMessage(error.message ?? 'Failed to save log.');
    } finally {
      setIsSaving(false);
    }
  }

  async function handleDeleteLog(logId) {
    const shouldDelete = window.confirm('Delete this log from your personal calendar?');
    if (!shouldDelete) return;

    setErrorMessage('');
    setStatusMessage('');
    try {
      const response = await fetch(`/api/logs/${logId}`, { method: 'DELETE' });
      if (!response.ok) {
        const message = await parseError(response);
        throw new Error(message);
      }

      const nextDailyCount = Math.max(1, (logsByDate[selectedDate]?.length ?? 1) - 1);
      setLogs((previousLogs) => previousLogs.filter((log) => log.id !== logId));
      resetFormForDate(selectedDate, nextDailyCount);
      setStatusMessage('Log deleted.');
    } catch (error) {
      setErrorMessage(error.message ?? 'Failed to delete log.');
    }
  }

  async function handleInstagramPublish(log) {
    setErrorMessage('');
    setStatusMessage('');
    setIsPublishingId(log.id);
    try {
      const response = await fetch(`/api/logs/${log.id}/upload-instagram`, {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({
          imageUrl: formState.instagramImageUrl.trim() || undefined,
        }),
      });
      if (!response.ok) {
        const message = await parseError(response);
        throw new Error(message);
      }

      setStatusMessage('Uploaded to connected Instagram account.');

      const refreshed = await fetch(`/api/logs?month=${toMonthKey(displayMonth)}`);
      if (refreshed.ok) {
        const payload = await refreshed.json();
        setLogs(payload);
      }
    } catch (error) {
      setErrorMessage(error.message ?? 'Instagram upload failed.');
    } finally {
      setIsPublishingId(null);
    }
  }

  function startEditingLog(log) {
    setSelectedLogId(log.id);
    setSelectedDate(log.date);
    setFormState(mapLogToForm(log));
    setStatusMessage(`Editing entry ${log.entryNumber}.`);
    setErrorMessage('');
  }

  return (
    <main className="app-shell">
      <header className="hero-panel">
        <p className="eyebrow">Family Finance Journal</p>
        <h1>Wealth Chronicle Calendar</h1>
        <p>
          Capture your child&apos;s money habits as structured logs, save each entry in a personal
          calendar, and publish to Instagram with one button.
        </p>
      </header>

      <section className="layout-grid">
        <article className="card calendar-card">
          <div className="calendar-head">
            <button type="button" onClick={() => handleMonthMove(-1)}>
              ← Previous
            </button>
            <h2>{formatMonthLabel(displayMonth)}</h2>
            <button type="button" onClick={() => handleMonthMove(1)}>
              Next →
            </button>
          </div>

          <div className="weekday-row">
            {WEEK_DAYS.map((day) => (
              <span key={day}>{day}</span>
            ))}
          </div>

          <div className="month-grid">
            {monthGrid.map((day) => {
              const dailyCount = logsByDate[day.iso]?.length ?? 0;
              const isSelected = day.iso === selectedDate;
              return (
                <button
                  key={day.iso}
                  type="button"
                  className={`day-cell ${day.isCurrentMonth ? '' : 'outside'} ${
                    isSelected ? 'selected' : ''
                  }`}
                  onClick={() => handleDateSelection(day.iso)}
                >
                  <span>{day.dayNumber}</span>
                  {dailyCount > 0 ? <small>{dailyCount} log</small> : null}
                </button>
              );
            })}
          </div>

          <div className="daily-logs">
            <h3>Logs on {formatReadableDate(selectedDate)}</h3>
            {selectedDateLogs.length === 0 ? (
              <p className="muted">No log yet. Add your first entry below.</p>
            ) : (
              <ul>
                {selectedDateLogs.map((log) => (
                  <li key={log.id}>
                    <div>
                      <strong>
                        Entry {log.entryNumber}: {log.entryTitle}
                      </strong>
                      <p>{log.photoDescription}</p>
                      {log.instagram?.lastPublishedAt ? (
                        <p className="published">
                          Instagram: {formatReadableDate(log.instagram.lastPublishedAt)}
                        </p>
                      ) : null}
                    </div>
                    <div className="actions">
                      <button type="button" onClick={() => startEditingLog(log)}>
                        Edit
                      </button>
                      <button type="button" onClick={() => handleDeleteLog(log.id)}>
                        Delete
                      </button>
                      <button
                        type="button"
                        onClick={() => handleInstagramPublish(log)}
                        disabled={isPublishingId === log.id}
                      >
                        {isPublishingId === log.id
                          ? 'Uploading...'
                          : 'Upload to Instagram'}
                      </button>
                    </div>
                  </li>
                ))}
              </ul>
            )}
          </div>
        </article>

        <article className="card form-card">
          <div className="form-head">
            <h2>{selectedLogId ? 'Edit Wealth Log' : 'Create Wealth Log'}</h2>
            <button type="button" onClick={() => resetFormForDate(selectedDate, selectedDateLogs.length + 1)}>
              New entry
            </button>
          </div>

          <form onSubmit={handleSaveLog}>
            <div className="two-columns">
              <label>
                Chronicle title
                <input
                  value={formState.chronicleTitle}
                  onChange={(event) => updateField('chronicleTitle', event.target.value)}
                  required
                />
              </label>
              <label>
                Volume
                <input
                  type="number"
                  min="1"
                  value={formState.volumeNumber}
                  onChange={(event) => updateField('volumeNumber', event.target.value)}
                  required
                />
              </label>
              <label>
                Entry number
                <input
                  type="number"
                  min="1"
                  value={formState.entryNumber}
                  onChange={(event) => updateField('entryNumber', event.target.value)}
                  required
                />
              </label>
              <label>
                Entry title
                <input
                  value={formState.entryTitle}
                  onChange={(event) => updateField('entryTitle', event.target.value)}
                  required
                />
              </label>
              <label>
                Date
                <input
                  type="date"
                  value={formState.date}
                  onChange={(event) => updateField('date', event.target.value)}
                  required
                />
              </label>
              <label>
                Tags (comma separated)
                <input
                  value={formState.tags}
                  onChange={(event) => updateField('tags', event.target.value)}
                  placeholder="save,invest,allowance"
                />
              </label>
            </div>

            <label>
              Photo description
              <input
                value={formState.photoDescription}
                onChange={(event) => updateField('photoDescription', event.target.value)}
                required
              />
            </label>

            <label>
              Upload photo
              <input type="file" accept="image/*" onChange={handleFileChange} />
            </label>

            {formState.photoUrl && !formState.photoFile ? (
              <label className="checkbox-row">
                <input
                  type="checkbox"
                  checked={formState.removePhoto}
                  onChange={(event) => updateField('removePhoto', event.target.checked)}
                />
                Remove current photo on save
              </label>
            ) : null}

            <label>
              Activity
              <textarea
                value={formState.activity}
                onChange={(event) => updateField('activity', event.target.value)}
                rows={3}
                required
              />
            </label>

            <label>
              Fact / Status
              <textarea
                value={formState.factStatus}
                onChange={(event) => updateField('factStatus', event.target.value)}
                rows={2}
              />
            </label>

            <label>
              Process
              <textarea
                value={formState.process}
                onChange={(event) => updateField('process', event.target.value)}
                rows={2}
              />
            </label>

            <label>
              Child reaction
              <textarea
                value={formState.childReaction}
                onChange={(event) => updateField('childReaction', event.target.value)}
                rows={3}
                required
              />
            </label>

            <label>
              Child quote (optional)
              <input
                value={formState.childQuote}
                onChange={(event) => updateField('childQuote', event.target.value)}
              />
            </label>

            <label>
              Analyst comment
              <textarea
                value={formState.analystComment}
                onChange={(event) => updateField('analystComment', event.target.value)}
                rows={4}
                required
              />
            </label>

            <label>
              Public image URL for Instagram (optional override)
              <input
                value={formState.instagramImageUrl}
                onChange={(event) => updateField('instagramImageUrl', event.target.value)}
                placeholder="https://your-domain.com/uploads/photo.jpg"
              />
            </label>

            <div className="form-buttons">
              <button type="submit" disabled={isSaving}>
                {isSaving ? 'Saving...' : 'Save to personal calendar'}
              </button>
            </div>
          </form>
        </article>

        <article className="card preview-card">
          <h2>Chronicle Format Preview</h2>
          <p className="muted">Matches your requested log style for records and Instagram caption.</p>

          <div className="preview-paper">
            <p className="preview-title">
              [{formState.chronicleTitle || "My Child's Wealth Chronicle"}: Vol.{' '}
              {formState.volumeNumber || 1}]
            </p>
            <p className="preview-subtitle">
              {getOrdinalNumber(formState.entryNumber || 1)} record: {formState.entryTitle || 'Untitled'}
            </p>

            <p>
              <strong>Photo:</strong> {formState.photoDescription || 'No photo description yet'}
            </p>
            {previewPhotoUrl ? <img src={previewPhotoUrl} alt="Log preview" className="preview-image" /> : null}

            <p>
              <strong>Date:</strong> {formatReadableDate(formState.date)}
            </p>

            <p>
              <strong>Log Details:</strong>
            </p>
            <p>
              <strong>Activity:</strong> {formState.activity || 'Not provided'}
            </p>
            {formState.factStatus ? (
              <p>
                <strong>Fact:</strong> {formState.factStatus}
              </p>
            ) : null}
            {formState.process ? (
              <p>
                <strong>Process:</strong> {formState.process}
              </p>
            ) : null}
            <p>
              <strong>Child reaction:</strong> {formState.childReaction || 'Not provided'}
            </p>
            {formState.childQuote ? (
              <p>
                <strong>Child quote:</strong> &quot;{formState.childQuote}&quot;
              </p>
            ) : null}
            <p>
              <strong>Analyst comment:</strong> {formState.analystComment || 'Not provided'}
            </p>
            <p>
              <strong>Tags:</strong>{' '}
              {previewTags.length > 0 ? previewTags.map((tag) => `#${tag}`).join(' ') : 'No tags'}
            </p>
          </div>

          {statusMessage ? <p className="status success">{statusMessage}</p> : null}
          {errorMessage ? <p className="status error">{errorMessage}</p> : null}
        </article>
      </section>
    </main>
  );
}

export default App;
