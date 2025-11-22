#include <stdio.h>

#define MAX 5

void printArray(int array[], int size);
int apple(int array[], int size);
void orange(int peel, int leaf, int array[], int size);
void lemon(int peel, int leaf, int array[], int size);

int main() {
    int i, j, total;
    int fruits[MAX] = {1, 2, 3, 5, 6};
    int deco[MAX] = {5, 13, 12, 16, 14};
    total = apple(fruits, MAX);
    printf("total: %d\n", total);
    printArray(fruits, MAX);

    for (i = 0, j=MAX-1; i < MAX/2; i++, j--) {
        orange(deco[i], deco[j], fruits, MAX);
        total += apple(fruits, MAX);
        printf("Total: %d\n", total);
        printArray(fruits, MAX);
    }
    
    return 0;
}

void orange(int peel, int leaf, int box[], int size) {
    peel = peel % MAX;
    leaf = leaf % MAX;
    printf("orange peel: %d, leaf: %d\n", peel, leaf);
    if (peel == 0 && leaf == MAX - 1) {
        lemon(peel, leaf, box, size);
    } else {
        box[peel] = leaf;
        box[leaf] += peel;
    }
}

void lemon(int peel, int leaf, int box[], int size) {
    int stem;
    printf("lemon\n");
    stem = box[peel];
    box[peel] = box[leaf];
    box[leaf] = stem;
}

int apple(int box[], int size) {
    int rc = 0;
    int i;
    printf("apple\n");
    for (i = 0; i < size; i++) {
        rc += box[i];
    }
    return rc;
}

// prints each number in array separated by a space,
// followed by a newline at the end
void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}