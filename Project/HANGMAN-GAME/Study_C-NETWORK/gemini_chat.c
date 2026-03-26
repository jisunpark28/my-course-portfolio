#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>

struct MemoryStruct {
    char* memory;
    size_t size;
};

static size_t WriteMemoryCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct* mem = (struct MemoryStruct*)userp;

    char* ptr = realloc(mem->memory, mem->size + realsize + 1);
    if (!ptr) {
        printf("Memory Error\n");
        return 0;
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

void extract_answer(char* json_text) {
    char* start = strstr(json_text, "\"text\": \"");
    if (start) {
        start += 9;
        while (*start != '\0') {
            if (*start == '"' && *(start - 1) != '\\') break;

            if (*start == '\\' && *(start + 1) == 'n') {
                printf("\n");
                start++;
            }
            else if (*start != '\\') {
                printf("%c", *start);
            }
            start++;
        }
        printf("\n");
    }
    else {
        printf("No Answer found. Full Response: %s\n", json_text);
    }
}

int main() {
    
    char* api_key = getenv("GEMINI_API_KEY");
    if (!api_key) {
        fprintf(stderr, "Error: GEMINI_API_KEY environment variable is not set.\n");
        return 1;
    }

    CURL* curl;
    CURLcode res;
    struct curl_slist* headers = NULL;
    struct MemoryStruct chunk;

    chunk.memory = malloc(1);
    if (!chunk.memory) return 1;
    chunk.size = 0;

    char question[100];
    char json_body[1024];
    char url[512];

    printf("Enter your question: ");
    if (!fgets(question, sizeof(question), stdin)) return 1;
    question[strcspn(question, "\n")] = 0;

    snprintf(json_body, sizeof(json_body),
        "{\"contents\": [{\"parts\": [{\"text\": \"%s\"}]}]}", question);

    snprintf(url, sizeof(url),
        "https://generativelanguage.googleapis.com/v1beta/models/gemini-flash-latest:generateContent?key=%s", api_key);

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_body);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&chunk);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "Connection Error: %s\n", curl_easy_strerror(res));
        }
        else {
            extract_answer(chunk.memory);
        }

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }
    free(chunk.memory);
    return 0;
}