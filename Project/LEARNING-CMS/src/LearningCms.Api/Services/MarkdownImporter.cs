using System.Text;
using System.Text.RegularExpressions;
using LearningCms.Api.Models;
using YamlDotNet.Serialization;
using YamlDotNet.Serialization.NamingConventions;

namespace LearningCms.Api.Services;

public partial class MarkdownImporter
{
    private static readonly Regex FencedCodeRegex = FencedCodePattern();
    private static readonly Regex HeadingRegex = HeadingPattern();

    public Note Parse(string markdown)
    {
        var (frontMatter, body) = SplitFrontMatter(markdown);
        var meta = ParseFrontMatter(frontMatter);

        var topic = FirstMeta(meta, "title", "topic")
            ?? ExtractTitle(body)
            ?? "Untitled";

        var groups = ParseGroups(meta);
        var tags = ParseStringList(meta, "tags");

        var blocks = new List<ContentBlock>();
        var searchable = new StringBuilder(topic);
        AppendTags(searchable, groups);
        AppendTags(searchable, tags);

        var remaining = body.Trim();
        foreach (Match match in FencedCodeRegex.Matches(remaining))
        {
            var index = match.Index;
            if (index > 0)
            {
                var textChunk = remaining[..index].Trim();
                AddTextBlocks(blocks, searchable, textChunk);
            }

            var language = match.Groups["lang"].Value;
            var code = match.Groups["code"].Value.Trim();
            blocks.Add(new ContentBlock
            {
                Type = "code",
                Language = string.IsNullOrWhiteSpace(language) ? null : language,
                Body = code
            });
            searchable.Append(' ').Append(code);

            remaining = remaining[(index + match.Length)..];
        }

        if (!string.IsNullOrWhiteSpace(remaining))
        {
            AddTextBlocks(blocks, searchable, remaining.Trim());
        }

        if (blocks.Count == 0)
        {
            blocks.Add(new ContentBlock { Type = "text", Body = body.Trim() });
            searchable.Append(' ').Append(body);
        }

        return new Note
        {
            Topic = topic,
            Groups = groups,
            Tags = tags,
            Blocks = blocks,
            SearchableText = searchable.ToString().Trim(),
            RawMarkdown = markdown,
            CreatedAt = DateTime.UtcNow,
            UpdatedAt = DateTime.UtcNow
        };
    }

    private static (string frontMatter, string body) SplitFrontMatter(string markdown)
    {
        if (!markdown.StartsWith("---"))
        {
            return (string.Empty, markdown);
        }

        var end = markdown.IndexOf("\n---", 3, StringComparison.Ordinal);
        if (end < 0)
        {
            return (string.Empty, markdown);
        }

        var frontMatter = markdown[3..end].Trim();
        var body = markdown[(end + 4)..].TrimStart('\r', '\n');
        return (frontMatter, body);
    }

    private static Dictionary<string, object?> ParseFrontMatter(string frontMatter)
    {
        if (string.IsNullOrWhiteSpace(frontMatter))
        {
            return [];
        }

        var deserializer = new DeserializerBuilder()
            .WithNamingConvention(CamelCaseNamingConvention.Instance)
            .Build();

        var parsed = deserializer.Deserialize<Dictionary<string, object?>>(frontMatter);
        return parsed ?? [];
    }

    private static string? FirstMeta(Dictionary<string, object?> meta, params string[] keys)
    {
        foreach (var key in keys)
        {
            if (meta.TryGetValue(key, out var value) && value is not null)
            {
                var text = value.ToString();
                if (!string.IsNullOrWhiteSpace(text))
                {
                    return text;
                }
            }
        }

        return null;
    }

    private static List<string> ParseGroups(Dictionary<string, object?> meta)
    {
        var groups = ParseStringList(meta, "groups");
        if (groups.Count > 0)
        {
            return groups;
        }

        foreach (var key in new[] { "course", "project" })
        {
            groups.AddRange(ParseStringList(meta, key));
        }

        return groups.Distinct(StringComparer.OrdinalIgnoreCase).ToList();
    }

    private static List<string> ParseStringList(Dictionary<string, object?> meta, string key)
    {
        if (!meta.TryGetValue(key, out var raw) || raw is null)
        {
            return [];
        }

        return raw switch
        {
            string text => text.Split(',', StringSplitOptions.RemoveEmptyEntries | StringSplitOptions.TrimEntries).ToList(),
            IEnumerable<object> list => list.Select(item => item?.ToString() ?? string.Empty).Where(s => s.Length > 0).ToList(),
            _ => []
        };
    }

    private static string? ExtractTitle(string body)
    {
        var match = HeadingRegex.Match(body);
        return match.Success ? match.Groups["title"].Value.Trim() : null;
    }

    private static void AddTextBlocks(List<ContentBlock> blocks, StringBuilder searchable, string textChunk)
    {
        if (string.IsNullOrWhiteSpace(textChunk))
        {
            return;
        }

        blocks.Add(new ContentBlock { Type = "text", Body = textChunk.Trim() });
        searchable.Append(' ').Append(textChunk);
    }

    private static void AppendTags(StringBuilder searchable, IEnumerable<string> tags)
    {
        foreach (var tag in tags)
        {
            searchable.Append(' ').Append(tag);
        }
    }

    [GeneratedRegex(@"```(?<lang>[a-zA-Z0-9+#-]*)\s*\n(?<code>[\s\S]*?)```", RegexOptions.Multiline)]
    private static partial Regex FencedCodePattern();

    [GeneratedRegex(@"^#\s+(?<title>.+)$", RegexOptions.Multiline)]
    private static partial Regex HeadingPattern();
}
