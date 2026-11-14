namespace LearningCms.Api.Models;

// notes/*.md YAML: title, groups, topic, tags
public class Note
{
    public string? Id { get; set; }
    public string Topic { get; set; } = string.Empty;
    public List<string> Groups { get; set; } = [];
    public List<string> Tags { get; set; } = [];
    public List<ContentBlock> Blocks { get; set; } = [];
    public string SearchableText { get; set; } = string.Empty;
    public string? RawMarkdown { get; set; }
    public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
    public DateTime UpdatedAt { get; set; } = DateTime.UtcNow;
}
