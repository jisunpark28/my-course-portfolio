namespace LearningCms.Api.Models;

public class ContentBlock
{
    public string Type { get; set; } = "text";
    public string? Title { get; set; }
    public string? Body { get; set; }
    public string? Language { get; set; }
    public List<string>? Items { get; set; }
    public List<ComparisonRow>? Rows { get; set; }
}

public class ComparisonRow
{
    public string? Label { get; set; }
    public string? Left { get; set; }
    public string? Right { get; set; }
}
