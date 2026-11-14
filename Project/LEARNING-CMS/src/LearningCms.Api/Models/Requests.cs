namespace LearningCms.Api.Models;

public class NoteUpdateRequest
{
    public string Topic { get; set; } = string.Empty;
    public List<string>? Groups { get; set; }
    public List<string>? Tags { get; set; }
    public List<ContentBlock>? Blocks { get; set; }
    public string? RawMarkdown { get; set; }
}

public class ImportMarkdownRequest
{
    public string Markdown { get; set; } = string.Empty;
}
