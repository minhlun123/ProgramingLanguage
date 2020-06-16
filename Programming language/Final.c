#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

char getChar();
int chooseLevel();
char *randomWord(int level);
int win(int decode[], int wordLen);
int compareArr(int array1[], int array2[], int size);

int main()
{
    while(1)
    {
        printf("Welcome to HANGMAN game\n");
        int level = chooseLevel();
        printf("A random secret word has been generated for you!\n");
        char *hidWord = randomWord(level);
        int wordLen = strlen(hidWord);
        //char scrWord[] = "TELEVISION";  //Tu can duoc tim
        char character = 0;             //Bien chu cai
        int *scrDecode = malloc(wordLen*sizeof(int));
        for(int i=0; i<wordLen;i++)
        {
            scrDecode[i] = 0;
        }        //Chu cai dang 0010011 
        
        int turns=10;
        int i = 0;
        char wordShow[20]={0};
        //char wordShow[wordLen];
        for(i=0; i<wordLen; i++)               //Tao string ***** de an tu can tim di
        {
            wordShow[i] = '*';
        }
        
        printf("%s", wordShow);

        while(turns > 0 && !win(scrDecode,wordLen))
        {
            printf("\nYou have %d chances left", turns);
            int *temp=malloc(wordLen*sizeof(int));
            for(i=0;i<wordLen;i++)
                temp[i] = scrDecode[i];
            printf("\n\nGuess a character:");
            character = getChar();
            for(i=0; i<wordLen; i++)
            {
                if(character == hidWord[i])
                {
                    scrDecode[i] = 1;
                    wordShow[i] = character;
                }               
            }
            printf("%s",wordShow);
            if(compareArr(temp,scrDecode,wordLen) == 1)
            {
                turns--;
            }

            win(scrDecode,wordLen);
        }
        if(turns > 0)
        {
            printf("\n\nCongratulations! The secret word is: %s", wordShow);
        }
        else
        {
            printf("\n\nGame Over! You lost! The secret word is: %s", hidWord);
        }

        
        printf("\nDo you want to play again?\n");
        printf("(YES: 1     |       NO: 2):");
        char playAgain;
        scanf("%d",&playAgain);
        if(playAgain == 2)
        {
            printf("\nGoodbye!\n");
            break;
        }
        else
        {
            printf("\n----------------------------------------------------\n");
        }   
    }
}

int win(int decode[], int wordLen)               //Kiem tra dieu kien chien thang
{
    int i = 0;
    int won = 1;
    for(i=0; i < wordLen; i++)
    {
        if(decode[i] == 0)
        {
            won = 0;
        }
    }
    return won;
}

int compareArr(int array1[], int array2[], int size)        //Kiem tra 2 array xem co bang giong nhau khong
{
    int check=1;
    for(int i=0; i<size; i++)
    {
        if(array1[i] != array2[i])
            check = 0;
    }
    return check;
}

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
int chooseLevel()
{
    printf("Choose a Level:\n");
    printf("1.  Easy\n");
    printf("2.  Medium\n");
    printf("3.  Hard\n");
    int number;
    printf("Your choice is: ");
    scanf("%d",&number);
    return number;
}
//Nhap chu cai de kiem tra
char getChar()
{
    char inputChar = 0;
    inputChar = getchar();
    inputChar = toupper(inputChar);

    while (getchar() != '\n');
    return inputChar;
}
