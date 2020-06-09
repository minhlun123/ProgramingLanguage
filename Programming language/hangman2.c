#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

int win(int decode[]);
int compareArr(int array1[], int array2[], int size);
//Nhap chu cai de kiem tra
char getChar()
{
    char inputChar = 0;
    inputChar = getchar();
    inputChar = toupper(inputChar);

    while (getchar() != '\n');
    return inputChar;
}

int main()
{
    char scrWord[] = "TELEVISION";  //Tu can duoc tim
    char character = 0;             //Bien chu cai
    int scrDecode[10] = {0};        //Chu cai dang 0010011 (Doc trong file Khung ppt)
    int turns=10;
    int i = 0;
    char wordShow[10];
    for(i; i<10; i++)               //Tao string ***** de an tu can tim di
    {
        wordShow[i] = '*';
    }

    printf("Welcome to HANGMAN game\n");
    printf("A random secret word has been generated for you!\n");
    printf("%s", wordShow);

    while(turns > 0 && !win(scrDecode))
    {
        printf("\nYou have %d chances left", turns);
        int temp[10];
        for(i=0;i<10;i++)
            temp[i] = scrDecode[i];
        printf("\n\nGuess a character:");
        character = getChar();
        for(i=0; i<10; i++)
        {
            if(character == scrWord[i])
            {
                scrDecode[i] = 1;
                wordShow[i] = character;
            }
        }
        printf("%s",wordShow);
        if(compareArr(temp,scrDecode,10) == 1)
        {
            turns--;
        }

        win(scrDecode);
    }
    if(turns > 0)
    {
        printf("\n\nCongratulations! The secret word is: %s", wordShow);
    }
    else
    {
        printf("\n\nGame Over! You lost! The secret word is: %s", scrWord);
    }

}

int win(int decode[])               //Kiem tra dieu kien chien thang
{
    int i = 0;
    int won = 1;
    for(i=0; i < 10; i++)
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
