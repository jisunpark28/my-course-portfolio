#include "hangman.h"
#include <ctype.h>
#include <unistd.h>
#include <ctype.h>
#include <unistd.h>
#define API_KEY "API_KEY"

struct Memory{
    char *memory;
    size_t size;
};


void instruction() {
    system("clear");
    FILE* fp;
    char ch;

    fp = fopen("instruction.txt", "r");

    if (fp != NULL){
        printf("\n");
        while((ch = fgetc(fp)) != EOF){
            printf("%c", ch);
        }
        printf("\n");
        fclose(fp);
    }else{
        printf("\nError: Could not open instruction.txt.\n");
    }

    printf("\nPress Enter to return to menu...");
    while(getchar() != '\n'); getchar();
}

void printHangman(int pictureIndex){
    FILE *fp; 
    char buffer[256];
    int currentLine = 0;
    const int linesPerImage =8;
    const int imageHeight = 7;

    int startLine = pictureIndex * linesPerImage;
    int endLine = startLine + imageHeight;

    fp = fopen("picture.txt", "r");

    if (fp != NULL){
        printf("\n");
        while(currentLine < endLine && fgets(buffer, sizeof(buffer), fp) != NULL){
            if(currentLine >= startLine && currentLine < endLine){
                printf("%s", buffer);
            } 
            currentLine++;
        }
        printf("\n");
        fclose(fp);
    }else{
        printf("\nError: Could not open picture.txt.\n");
    }
}


size_t writeMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp){
    size_t realsize = size * nmemb;
    struct Memory *mem = (struct Memory *)userp;
    char *ptr = realloc(mem->memory, mem->size + realsize + 1);
    if(!ptr) return 0;
    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;
    return realsize;
}

void extractWord(char *jsonText, char *buffer) {
    char *start = strstr(jsonText, "\"text\": \"");
    if (start) {
        start += 9; 
        int i = 0;
        while (*start != '\0' && *start != '"' && *start != '\\' && *start != '\n') {
            buffer[i++] = *start;
            start++;
        }
        buffer[i] = '\0';
        if(i > 0 && buffer[i-1] == ' ') buffer[i-1] = '\0';
    } else {
        strcpy(buffer, "ERROR");
    }
}

char* fetchWordFromGemini(char* userInput) {
    CURL *curl;
    CURLcode res;
    struct Memory chunk;
    chunk.memory = malloc(1);
    chunk.size = 0;
    
    static char responseBuffer[512]; 
    char jsonBody[2048];         
    char url[512];
    
    char prompt[1024];

    sprintf(prompt, 
        "The user will provide a topic. "
        "Select ONE word related to it. "
        "Output format: WORD|HINT. "
        "Example output: APPLE|A red fruit. "
        "Use simple English for the hint. "
        "Input Topic: '%s'. "
        "Constraint: Output ONLY the 'Word|Hint' string. No markdown.", userInput); 

    sprintf(jsonBody, "{\"contents\": [{\"parts\": [{\"text\": \"%s\"}]}]}", prompt);
    sprintf(url, "https://generativelanguage.googleapis.com/v1beta/models/gemini-flash-latest:generateContent?key=%s", API_KEY);

    curl_easy_init();
    curl = curl_easy_init();
    if(curl) {
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonBody);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        
        res = curl_easy_perform(curl);
        
        if(res != CURLE_OK) strcpy(responseBuffer, "CONNECTION_FAIL");
        else extractWord(chunk.memory, responseBuffer); 

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
        free(chunk.memory);
    }
    return responseBuffer; 
}

void hangman() {
    char inputBuffer[200]; 
    char playAgain;       

    system("clear");
    printf("\n============================================\n");
    printf("  [ AI HANGMAN: Context-Based Mode ]\n");
    printf("  Enter a context/topic (e.g., 'Fruits', 'Marvel Movies')\n");
    printf("============================================\n");
    printf("  Input > ");
    
    if (fgets(inputBuffer, sizeof(inputBuffer), stdin) != NULL) {
        inputBuffer[strcspn(inputBuffer, "\n")] = 0; 
    }

    do {
        system("clear");
        printf("\n  [System] AI is generating a NEW word for '%s'...\n", inputBuffer);
        
        char* fullResponse = fetchWordFromGemini(inputBuffer);

        if(strlen(fullResponse) < 2 || strcmp(fullResponse, "ERROR") == 0) {
            printf("  [Error] Failed to get data. Check internet/Key.\n");
            printf("  Press Enter to return...");
            getchar();
            return;
        }

        char secretWord[100];
        char hint[256];
        
        char *separator = strchr(fullResponse, '|');
        if (separator != NULL) {
            *separator = '\0'; 
            strcpy(secretWord, fullResponse); 
            strcpy(hint, separator + 1);      
        } else {
            strcpy(secretWord, fullResponse);
            strcpy(hint, "No hint available.");
        }

        int wordLength = strlen(secretWord);
        char guessedView[100];
        char wrongGuesses[26] = "";
        int wrongCount = 0;
        int matchedCount = 0;
        int maxLives = 6;
        
        for(int i=0; i<wordLength; i++) {
            if(secretWord[i] == ' ' || secretWord[i] == '-') guessedView[i] = secretWord[i];
            else guessedView[i] = '_';
        }
        guessedView[wordLength] = '\0';

        while (wrongCount < maxLives && matchedCount < wordLength) {
            system("clear");

            printf("\n============================================\n");
            printf("       AI  H A N G M A N  GAME\n");
            printf("============================================\n");

            printHangman(wrongCount);

            printf("  Topic:   %s\n", inputBuffer); 
            printf("  Hint:    %s\n", hint);        
            printf("  Word:    ");
            for(int i=0; i<wordLength; i++) printf("%c ", guessedView[i]);
            printf("\n\n");
            printf("  Wrongs:  %s\n", wrongGuesses);
            printf("  Lives:   %d / %d\n", maxLives - wrongCount, maxLives);
            printf("============================================\n");
            printf("  Guess > ");

            char guess;
            if (scanf(" %c", &guess) != 1) continue;
            while(getchar() != '\n'); 
            guess = toupper(guess);

            if (guess < 'A' || guess > 'Z') continue;

            int already = 0;
            for(int i=0; i<wordLength; i++) if(guessedView[i] == guess) already = 1;
            if(strchr(wrongGuesses, guess)) already = 1;
            
            if (already) {
                printf("  [!] Already guessed '%c'. Press Enter...", guess);
                getchar();
                continue;
            }

            int isCorrect = 0;
            for (int i = 0; i < wordLength; i++) {
                if (toupper(secretWord[i]) == guess) {
                    guessedView[i] = secretWord[i];
                    isCorrect = 1;
                }
            }

            if (isCorrect) {
                matchedCount = 0;
                for(int i=0; i<wordLength; i++) if(guessedView[i] != '_') matchedCount++;
            } else {
                wrongCount++;
                int len = strlen(wrongGuesses);
                wrongGuesses[len] = guess;
                wrongGuesses[len+1] = ' '; 
                wrongGuesses[len+2] = '\0';
            }
        }

        system("clear");
        printf("\n============================================\n");

        if (matchedCount == wordLength) {
            for(int i=0; i<3; i++) { 
                system("clear");
                printf("\n  🎉  YOU WON!  🎉\n");
                printHangman(7); 
                usleep(300000); 
                system("clear");
                printf("\n  🎉  YOU WON!  🎉\n");
                printHangman(8); 
                usleep(300000);
            }
            printf("\n  The word was: %s\n", secretWord);
        } else {
            printHangman(6);
            printf("\n  💀 GAME OVER... 💀\n");
            printf("  The word was: %s\n", secretWord);
        }
        
        printf("============================================\n");

        printf("\nPlay again with same topic '%s'? (y/n) > ", inputBuffer);
        scanf(" %c", &playAgain);
        while(getchar() != '\n'); 

    } while (playAgain == 'y' || playAgain == 'Y'); 

    printf("\nReturning to menu...\n");
}
