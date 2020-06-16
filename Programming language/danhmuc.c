#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "danhmuc.h"
int chonTu(char *tuDuocChon)
{
    FILE* danhmuc = NULL; // Con tro tap tin de chua cac tap tin cua chung ta
    int soThuTuCuaTu = 0, soThuTuCuaTuDuocChon = 0, i = 0;
    int luuKytu = 0;
    danhmuc = fopen("danhmuc.txt", "r"); // Tap tin duoc mo trong che do "read-only"
    // Chung ta kiem tra xem thao tac mo tap tin co thanh cong khong
    if (danhmuc == NULL) // Neu ban khong the mo tap tin
    {
        printf ("\n Khong the mo danh muc tu bi mat");
        return 0; // Tra ve gia tri 0 cho biet thao tac mo tap tin that bai
    // Sau khi nhan duoc gia tri tra ve cua return, ham ket thuc.
    }// Dem cac tu duoc chua trong tap tin (chi viec dem co bao nhieu ky tu \n thoi)
    do
    {
        luuKytu = fgetc(danhmuc);
        if (luuKytu == '\n')
        soThuTuCuaTu++;
    } while(luuKytu != EOF);
    soThuTuCuaTuDuocChon = tuNgauNhien(soThuTuCuaTu); // Chon mot tu ngau nhien
    // Chuong trinh doc lai tu dau tap tin va ngung lai khi tim thay tu ngau nhien duoc chon
    rewind(danhmuc);
    while (soThuTuCuaTuDuocChon > 0)
    {
        luuKytu = fgetc(danhmuc);
        if (luuKytu == '\n')
        soThuTuCuaTuDuocChon--;
    }
    /* Con tro tap tin danhmuc duoc dat dung vi tri cua no.
    Chung ta su dung ham fgets va quy dinh ham khong doc qua so luong ky tu cho phep*/
    fgets(tuDuocChon, 100, danhmuc);
    // Chung ta se thay the ky tu \n
    tuDuocChon[strlen(tuDuocChon) - 1] = '\0';
    fclose(danhmuc);
    return 1; // Gia tri tra ve = 1, tat ca deu hoat dong tot
}
int tuNgauNhien(int sothutuLonNhat)
{
    srand(time(NULL));
    return (rand( ) % sothutuLonNhat);
}