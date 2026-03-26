#include <stdio.h>
#include <stdlib.h>
#include "hangman.h"

int main(){

    int menuChoice = 0;

    while(1) {
        system("clear");

        printf("\n==============================\n");
        printf("       H A N G M A N \n");
        printf("==============================\n");
        printf("    1. Start Game\n");
        printf("    2. Instructions\n");
        printf("    3. Exit\n");
        printf("==============================\n\n");
        printf("Select an option [1-3]: ");

        if (scanf("%d", &menuChoice)!=1){
            while(getchar() != '\n');
            menuChoice = 0;
        } else {
            while(getchar() != '\n');
        }

        switch(menuChoice){
            case 1:
                hangman();
                break;
            case 2:
                instruction();
                break;
            case 3:
                printf("\nExiting the game. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid selection! Please enter 1-3.\n");
                printf("Press Enter to continue...");
                getchar();
                menuChoice = 0;
        }
    }
    return 0;
}