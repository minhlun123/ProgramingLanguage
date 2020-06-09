#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include  <time.h>
#include <string.h>

char getChar ( );
int main()
{
    //char chuCaiBiMat = getChar();
    //printf("%c",chuCaiBiMat);
    
    //Word Random
    srand(time(NULL));
    int line = rand() % 14;
    int i=0, j=0;

    FILE *word = fopen("WordList.txt","r");
    char hidWord[255];
    char wordShow[255];

    while (1)
    {
        i++;
        fgets(hidWord,255,word);
        if (i == line)
        {
            break;
        }
    }
    fclose(word);
    
    //Hien thi chu bi mat
    for(i=0; hidWord[i] != '\0'; i++)
    {
        wordShow[i-1] = '*';
    }
    printf("%s",wordShow);
    //printf("%s",hidWord);

    char temp[255];
    strcpy(temp,wordShow);

    while(1)
    {
        //get char
        printf("\nGuess a character: ");
        char secretChar = getChar();
        for(j=0; j < i-1; j++)
        {
                if(secretChar == hidWord[j])
                {
                    wordShow[j]=secretChar;
                } 
        }
        if(strcmp(temp,wordShow) != 0)
        {
            printf("%s\n",wordShow);
        }
        else
        {
            printf("Wrong character\n");
            printf("%s\n",wordShow);
        }
        //printf("%d and %d",strlen(hidWord),strlen(wordShow));   
    }
    printf("Congrats, the hidden word is %s",hidWord);

    return 0;
}

char getChar()
{
    char inputChar = 0;
    inputChar = getchar ( );                  // Doc ky tu duoc nhap dau tien
    inputChar = toupper (inputChar);        // Viet hoa ky tu do
                                                // Lan luot doc tiep cac ky tu khac cho den khi gap \n
    while (getchar ( ) != '\n') ;
    return inputChar;                         // Tra ve ky tu dau tien doc duoc
}
