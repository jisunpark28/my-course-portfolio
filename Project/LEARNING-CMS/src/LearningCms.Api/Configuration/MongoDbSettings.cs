namespace LearningCms.Api.Configuration;

public class MongoDbSettings
{
    public const string SectionName = "MongoDb";

    public string ConnectionString { get; set; } = "mongodb://localhost:27017";
    public string DatabaseName { get; set; } = "learning_cms";
    public string NotesCollectionName { get; set; } = "notes";
}
