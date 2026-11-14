using LearningCms.Api.Configuration;
using LearningCms.Api.Data;
using LearningCms.Api.Services;

// .NET 웹 앱의 시작점.
// 브라우저 → wwwroot HTML → /api/notes → Controller → Service → MongoDB
var builder = WebApplication.CreateBuilder(args);

builder.Services.Configure<MongoDbSettings>(builder.Configuration.GetSection(MongoDbSettings.SectionName));
builder.Services.AddSingleton<MongoDbContext>();
builder.Services.AddSingleton<MarkdownImporter>();
builder.Services.AddScoped<INoteService, NoteService>();

builder.Services.AddControllers();
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

var app = builder.Build();

using (var scope = app.Services.CreateScope())
{
    var db = scope.ServiceProvider.GetRequiredService<MongoDbContext>();
    await db.EnsureIndexesAsync();
}

if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

// wwwroot/index.html 을 http://localhost:5000 에서 보여 줌
app.UseDefaultFiles();
app.UseStaticFiles();

app.MapControllers();
app.MapFallbackToFile("index.html");

app.Run();
