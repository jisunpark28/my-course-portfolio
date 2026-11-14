using System.Text;
using LearningCms.Api.Data;
using LearningCms.Api.Models;
using MongoDB.Bson;
using MongoDB.Driver;

namespace LearningCms.Api.Services;

public interface INoteService
{
    Task<List<Note>> GetAllAsync(CancellationToken cancellationToken = default);
    Task<Note?> GetByIdAsync(string id, CancellationToken cancellationToken = default);
    Task<List<Note>> SearchAsync(string? query, CancellationToken cancellationToken = default);
    Task<Note> ImportMarkdownAsync(string markdown, CancellationToken cancellationToken = default);
    Task<Note?> UpdateAsync(string id, NoteUpdateRequest request, CancellationToken cancellationToken = default);
    Task<bool> DeleteAsync(string id, CancellationToken cancellationToken = default);
}

public class NoteService : INoteService
{
    private readonly MongoDbContext _db;
    private readonly MarkdownImporter _importer;

    public NoteService(MongoDbContext db, MarkdownImporter importer)
    {
        _db = db;
        _importer = importer;
    }

    public async Task<List<Note>> GetAllAsync(CancellationToken cancellationToken = default)
    {
        var docs = await _db.Notes
            .Find(FilterDefinition<NoteDocument>.Empty)
            .SortByDescending(n => n.UpdatedAt)
            .ToListAsync(cancellationToken);

        return docs.Select(d => d.ToNote()).ToList();
    }

    public async Task<Note?> GetByIdAsync(string id, CancellationToken cancellationToken = default)
    {
        if (!ObjectId.TryParse(id, out var objectId))
        {
            return null;
        }

        var doc = await _db.Notes
            .Find(n => n.Id == objectId)
            .FirstOrDefaultAsync(cancellationToken);

        return doc?.ToNote();
    }

    public async Task<List<Note>> SearchAsync(string? query, CancellationToken cancellationToken = default)
    {
        if (string.IsNullOrWhiteSpace(query))
        {
            return await GetAllAsync(cancellationToken);
        }

        var filter = Builders<NoteDocument>.Filter.Text(query);
        var docs = await _db.Notes
            .Find(filter)
            .SortByDescending(n => n.UpdatedAt)
            .ToListAsync(cancellationToken);

        if (docs.Count > 0)
        {
            return docs.Select(d => d.ToNote()).ToList();
        }

        var regex = new BsonRegularExpression(query, "i");
        var fallbackFilter = Builders<NoteDocument>.Filter.Or(
            Builders<NoteDocument>.Filter.Regex(n => n.Topic, regex),
            Builders<NoteDocument>.Filter.Regex(n => n.SearchableText, regex),
            Builders<NoteDocument>.Filter.AnyIn(n => n.Tags, [query]));

        docs = await _db.Notes
            .Find(fallbackFilter)
            .SortByDescending(n => n.UpdatedAt)
            .ToListAsync(cancellationToken);

        return docs.Select(d => d.ToNote()).ToList();
    }

    public async Task<Note> ImportMarkdownAsync(string markdown, CancellationToken cancellationToken = default)
    {
        var note = _importer.Parse(markdown);
        note.SearchableText = BuildSearchableText(note);
        var doc = NoteDocument.FromNote(note);
        await _db.Notes.InsertOneAsync(doc, cancellationToken: cancellationToken);
        return doc.ToNote();
    }

    public async Task<Note?> UpdateAsync(string id, NoteUpdateRequest request, CancellationToken cancellationToken = default)
    {
        if (!ObjectId.TryParse(id, out var objectId))
        {
            return null;
        }

        var existing = await _db.Notes.Find(n => n.Id == objectId).FirstOrDefaultAsync(cancellationToken);
        if (existing is null)
        {
            return null;
        }

        existing.Topic = request.Topic;
        existing.Groups = request.Groups ?? existing.Groups;
        existing.Tags = request.Tags ?? existing.Tags;
        existing.Blocks = request.Blocks ?? existing.Blocks;
        existing.RawMarkdown = request.RawMarkdown ?? existing.RawMarkdown;
        existing.UpdatedAt = DateTime.UtcNow;
        existing.SearchableText = BuildSearchableText(existing.ToNote());

        await _db.Notes.ReplaceOneAsync(n => n.Id == objectId, existing, cancellationToken: cancellationToken);
        return existing.ToNote();
    }

    public async Task<bool> DeleteAsync(string id, CancellationToken cancellationToken = default)
    {
        if (!ObjectId.TryParse(id, out var objectId))
        {
            return false;
        }

        var result = await _db.Notes.DeleteOneAsync(n => n.Id == objectId, cancellationToken);
        return result.DeletedCount > 0;
    }

    private static string BuildSearchableText(Note note)
    {
        var builder = new StringBuilder(note.Topic);
        foreach (var group in note.Groups)
        {
            builder.Append(' ').Append(group);
        }

        foreach (var tag in note.Tags)
        {
            builder.Append(' ').Append(tag);
        }

        foreach (var block in note.Blocks)
        {
            if (!string.IsNullOrWhiteSpace(block.Title))
            {
                builder.Append(' ').Append(block.Title);
            }

            if (!string.IsNullOrWhiteSpace(block.Body))
            {
                builder.Append(' ').Append(block.Body);
            }

            if (block.Items is not null)
            {
                foreach (var item in block.Items)
                {
                    builder.Append(' ').Append(item);
                }
            }

            if (block.Rows is not null)
            {
                foreach (var row in block.Rows)
                {
                    builder.Append(' ').Append(row.Label).Append(' ').Append(row.Left).Append(' ').Append(row.Right);
                }
            }
        }

        if (!string.IsNullOrWhiteSpace(note.RawMarkdown))
        {
            builder.Append(' ').Append(note.RawMarkdown);
        }

        return builder.ToString().Trim();
    }
}
