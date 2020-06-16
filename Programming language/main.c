
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "danhmuc.h"

int win(int sokytuBimat[ ], long dodaiTu);
int kiemtraKytu(char kytu, char tuBimat[ ], int sokytuBimat[ ]);
char docKytu( );
int main(int argc, char* argv[ ])
{
    char kytu = 0; // Bien nay se luu tru ky tu cua nguoi choi (duoc tra ve boi ham scanf)
    char tuBimat[100] = {0}; // Day la tu bi mat can tim ra
    int *sokytuBimat = NULL; /* Mot mang co chua cac thanh phan dang Bolean. Moi o trong
    mang se tuong ung voi mot ky tu nguoi choi se doan. Neu doan dung thi gia tri = 1, va neu sai thi
    gia tri = 0 */
    long soluotDoan = 10; // So luot doan con lai cua nguoi choi (0 = thua)
    long i = 0; // Bien ho tro
    long dodaiTu = 0;
    printf ("Chao mung den voi tro choi Nguoi treo co !\n\n ");
    if (!chonTu(tuBimat))
        exit(0);dodaiTu = strlen(tuBimat);
    sokytuBimat = malloc(dodaiTu * sizeof (int)); /* mang sokytuBimat se duoc cap phat dong bo
    nho (luc dau chung ta khong biet duoc kich thuoc cua mang nay) */
    if (sokytuBimat == NULL)
        exit(0);
    for (i = 0 ; i < dodaiTu ; i++)
        sokytuBimat[i] = 0;
    /* Chung ta se tiep tuc tro choi neu con it nhat mot luot doan
    Va van chua tim duoc tu bi mat*/
    while (soluotDoan > 0 && !win(sokytuBimat, dodaiTu))
    {
        printf ("\n\n Ban co %d luot doan de choi ", soluotDoan);
        printf ("\n Tu bi mat la gi ?");
    /* Hien thi nhung ky tu bi mat va an di nhung ky tu chua duoc tim thay
    Vi du: *A***OO*/
        for (i = 0 ; i < dodaiTu ; i++)
        {
        if (sokytuBimat[i]) // Neu nguoi choi tim duoc ky tu thu i
        printf ("%c", tuBimat[i]); // Hien thi ky tu thu i duoc tim thay
        else
        printf ("*");// Hien thi dau * doi voi nhung ky tu chua duoc tim thay
        }
    printf ("\n Xin moi ban doan mot ky tu: ");
    kytu = docKytu( );
    // Neu ky tu nhap vao khong dung
    if (!kiemtraKytu(kytu, tuBimat, sokytuBimat))
    {
        soluotDoan--; // Giam bot mot lan doan cua nguoi choi
    }
    }
    if (win(sokytuBimat, dodaiTu))
        printf ("\n\n Chuc mung, ban da chien thang ! Tu bi mat la : %s", tuBimat);else
        printf ("\n\n Xin chia buon, ban da thua !\n\n Tu bi mat la : %s", tuBimat);
    free (sokytuBimat); // Giai phong bo nho da duoc phan bo (boi ham malloc)
    return 0;
}
char docKytu( )
{
    char kytuNhapVao = 0;
    kytuNhapVao = getchar( ); // Doc ky tu duoc nhap dau tien
    kytuNhapVao = toupper(kytuNhapVao); // Viet hoa ky tu do
    // Lan luot doc tiep cac ky tu khac cho den khi gap \n
    while (getchar( ) != '\n') ;
    return kytuNhapVao; // Tra ve ky tu dau tien doc duoc
}
int win(int sokytuBimat[ ], long dodaiTu)
{
    long i = 0;
    int nguoichoiChienThang = 1;
    for (i = 0 ; i < dodaiTu ; i++)
    {
        if (sokytuBimat[i] == 0)
        nguoichoiChienThang = 0;
    }
    return nguoichoiChienThang;
}
int kiemtraKytu(char kytu, char tuBimat[ ], int sokytuBimat[ ])
{
    long i = 0;
    int kytuChinhXac = 0;// Kiem tra xem ky tu cua nguoi choi da doan co nam trong tu bi mat ko
    for (i = 0 ; tuBimat[i] != '\0' ; i++)
    {
        if (kytu == tuBimat[i]) // Neu ky tu co chua trong tu bi mat
        {
            kytuChinhXac = 1; // Ky tu se duoc luu tru gia tri the hien no la ky tu chinh xac
            sokytuBimat[i] = 1; // Gui gia tri 1 vao o tuong ung voi vi tri cua ky tu do trong mang
        }
    }
    return kytuChinhXac;
}