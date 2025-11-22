#include <stdio.h>

void apple(char text[]);
int orange(char text[]);
void pear(int loc, char text[]);

int main(void)
{
    char word[6] = "cnf";
    int value;

    printf("Start: %s\n", word);

    apple(word);
    printf("After apple: %s\n", word);

    value = orange(word);
    printf("Count value: %d\n", value);

    pear(value, word);
    printf("Final: %s\n", word);

    return 0;
}

void apple(char text[])
{
    int i;
    for (i = 0; text[i] != '\0'; i++)
    {
        text[i] += 1;
    }
    text[i++] = 's';
    text[i] = '\0';
}

int orange(char text[])
{
    int total = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == 'g')
        {
            total++;
        }
    }
    return total;
}

void pear(int loc, char text[])
{
    int i;
    for (i = 4; i >= loc; i--)
    {
        text[i + 1] = text[i];
    }
    text[loc] = 'r';
    loc++;
    text[0] += loc;
}