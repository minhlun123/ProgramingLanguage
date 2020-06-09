#include <stdio.h>
#include <conio.h>

#include "windows.h"
void gotoxy(int x, int y)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {x, y};
    SetConsoleCursorPosition(hStdout, position);
}

int main(void)
{
    int x, y;
    x = 15;
    y = 10;
    gotoxy(x, y);
    clrscr();

    printf("gotoxy jumps to cursor position x42 y42.");

    getch();
    return 0;
}
