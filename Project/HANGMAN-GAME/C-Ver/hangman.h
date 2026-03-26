#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

void hangman();
void instruction();
void printHangman(int pictureIndex);
static size_t writeMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp);
void extractWord(char *json_text, char *buffer);
char* fetchWordFromGemini(char* user_input);
