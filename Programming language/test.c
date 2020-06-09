#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

char *randomWord();
int main()
{
    char *hidWord = randomWord();
    printf("%s", hidWord);
    printf("%d", strlen(hidWord));
}

char *randomWord()
{
    srand(time(NULL));
    int line = rand() % 14;
    int i = 0;

    FILE *word = fopen("WordList.txt", "r");
    static char hidWord[50];

    while (1)
    {
        i++;
        fgets(hidWord, 20, word);
        if (i == line)
        {
            break;
        }
    }
    return hidWord;
}