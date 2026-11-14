using LearningCms.Api.Configuration;
using LearningCms.Api.Models;
using Microsoft.Extensions.Options;
using MongoDB.Bson;
using MongoDB.Driver;

namespace LearningCms.Api.Data;

public class MongoDbContext
{
    private readonly IMongoCollection<NoteDocument> _notes;

    public MongoDbContext(IOptions<MongoDbSettings> settings)
    {
        var mongoSettings = settings.Value;
        var client = new MongoClient(mongoSettings.ConnectionString);
        var database = client.GetDatabase(mongoSettings.DatabaseName);
        _notes = database.GetCollection<NoteDocument>(mongoSettings.NotesCollectionName);
    }

    public IMongoCollection<NoteDocument> Notes => _notes;

    public async Task EnsureIndexesAsync(CancellationToken cancellationToken = default)
    {
        var topicIndex = new CreateIndexModel<NoteDocument>(
            Builders<NoteDocument>.IndexKeys.Ascending(n => n.Topic));

        var textIndex = new CreateIndexModel<NoteDocument>(
            Builders<NoteDocument>.IndexKeys.Text(n => n.Topic).Text(n => n.SearchableText));

        await _notes.Indexes.CreateManyAsync([topicIndex, textIndex], cancellationToken);
    }
}

public class NoteDocument
{
    public ObjectId Id { get; set; }
    public string Topic { get; set; } = string.Empty;
    public List<string> Groups { get; set; } = [];
    public List<string> Tags { get; set; } = [];
    public List<ContentBlock> Blocks { get; set; } = [];
    public string SearchableText { get; set; } = string.Empty;
    public string? RawMarkdown { get; set; }
    public DateTime CreatedAt { get; set; }
    public DateTime UpdatedAt { get; set; }

    public Note ToNote() => new()
    {
        Id = Id.ToString(),
        Topic = Topic,
        Groups = Groups,
        Tags = Tags,
        Blocks = Blocks,
        SearchableText = SearchableText,
        RawMarkdown = RawMarkdown,
        CreatedAt = CreatedAt,
        UpdatedAt = UpdatedAt
    };

    public static NoteDocument FromNote(Note note)
    {
        var doc = new NoteDocument
        {
            Topic = note.Topic,
            Groups = note.Groups,
            Tags = note.Tags,
            Blocks = note.Blocks,
            SearchableText = note.SearchableText,
            RawMarkdown = note.RawMarkdown,
            CreatedAt = note.CreatedAt,
            UpdatedAt = note.UpdatedAt
        };

        if (!string.IsNullOrWhiteSpace(note.Id) && ObjectId.TryParse(note.Id, out var objectId))
        {
            doc.Id = objectId;
        }

        return doc;
    }
}
