#include <stdio.h>

#define CAPACITY 4

void apple(int lemon[], int num);
void printArray(int array[], int size);

int main(void) {
    int curr = 1;
    int orange[CAPACITY] = {4, 2, 1, 3};
    printArray(orange, CAPACITY);

    while (curr != 0) {
        apple(orange, curr);
        curr = (curr + 4) % 3;
        printf("curr: %d\n", curr);
        printArray(orange, CAPACITY);
    }

    return 0;
}

void apple(int lemon[], int num) {
    int i;
    for (i = 0; i < CAPACITY; i++) {
        lemon[i] += num;
    }
}

// prints an array with space separating each
// value of array
void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}