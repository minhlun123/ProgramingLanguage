#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

char *randomWord(int level)
{
    srand(time(NULL));
    int line = rand() % 14;
    int i = 0;
    FILE *word;
    if (level == 1)
    {
        word = fopen("Easy.txt", "r");
    }
    else if (level == 2)
    {
        word = fopen("Medium.txt", "r");
    }
    else if (level == 3)
    {
        word = fopen("Hard.txt", "r");
    }
    else
    {
        printf("Wrong choice!");
    }
    
    
    static char hidWord[20];

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
int main()
{
    char *hidWord;
    hidWord = randomWord(1);
    printf("%s",hidWord);
    int lenWord = strlen(hidWord)-1;
    
    char wordShow[20] = {0};

    for(int i=0; i<lenWord;i++)
    {
        wordShow[i]='*';
    }

    printf("%s",wordShow);
    printf("\n%d",strlen(wordShow));
    return 0;
}