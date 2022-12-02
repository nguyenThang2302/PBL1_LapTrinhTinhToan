#include<stdio.h>
#include<math.h>
#include<unistd.h>

void INFORMATION_GROUP();
void INFORMATION_PROJECT();
void MENU();
float DETERMINANT(float a[101][101], int n); // HAM TINH DINH THUC MA TRAN VUONG CAP N
void READ_FILE(float a[101][101], int &n,FILE *t1,char k1[255]); 
void DISPLAY_MATRIX(float a[101][101],int n); // HIEN THI MA TRAN TU DU LIEU VAO
void DISPLAY_MATRIX_HANDLING(float a[101][101], int n,float b[101][101],float d[101][101]); // HIEN THI MA TRAN SAU KHI BIEN DOI TU MA TRAN VAO
void DISPLAY_MATRIX_CHILD(float a[101][101],int n,float c[101][101],float d[101][101],float x[101]); // HIEN THI MA TRAN CON CUA MA TRAN VAO VA TINH DINH THUC MA TRAN CON
void DISPLAY_ROOT_OF_AN_EQUATION(float x[101],int n); // HIEN THI NGHIEM CUA HE PHUONG TRINH
void WRITE_FILE(float x[101],int &n, FILE *t2, char k2[255]);

int main()
{
    //  KHAI BAO DU LIEU
    float Matrix_A[101][101]; // Ma Tran A
    float Temp[101][101]; // Ma Tran Trung Gian
    float Matrix_B[101][101]; // Ma Tran B la tong cac phan tu truoc no
    float Matrix_B_Temp[101][101]; // Ma Tran Tam cua Ma Tran B
    int CapMaTran; // n 
    char File_Name_INP[255];
    FILE *fptr_inp;
    char File_Name_OUTP[255];
    FILE *fptr_outp;
    int ChucNang;
    float X[101];

    //  THONG TIN VE DU AN VA NHOM
    INFORMATION_GROUP();
    printf("\n");

    INFORMATION_PROJECT();
    printf("\n");
    system("pause");

    //   NHAP TEN FILE VOI DU LIEU VAO
    READ_FILE(Matrix_A, CapMaTran,fptr_inp,File_Name_INP);

    //   THUC HIEN CAC CHUC NANG
    MENU();
    printf("\n");
    ChucNang:
    printf("Nhap Chuc Nang: ");
    scanf("%d", &ChucNang);
    system("cls");
    switch(ChucNang)
    {
        case 1:
        printf("=> Ma Tran A (%dx%d) Vua Nhap Tu File\n",CapMaTran,CapMaTran);
        DISPLAY_MATRIX(Matrix_A, CapMaTran);
        system("pause");
        printf("\n");
        MENU();
        printf("\n");
        goto ChucNang;
        break;

        case 2:
        printf("=> Dinh Thuc Ma Tran A(%dx%d) = %.2f",CapMaTran,CapMaTran,DETERMINANT(Matrix_A,CapMaTran));
        if( DETERMINANT(Matrix_A,CapMaTran) == 0 )
        {
            printf("\n=> He Bat Phuong Trinh Khong The Giai Bang Phuong Phap Cramer\n");
            system("pause");
            break;
        } else
        {
            printf("\n=> He Bat Phuong Giai Duoc Theo Phuong Phap Cramer\n"); 
            system("pause");
            printf("\n");
            MENU();
            printf("\n");
            goto ChucNang;
        }
        break;

        case 3:
        printf("=> Ma Tran B(%dx%d) Sau Khi Bien Doi Tu Ma Tran A(%dx%d): ",CapMaTran+1,CapMaTran,CapMaTran,CapMaTran);
        DISPLAY_MATRIX_HANDLING(Matrix_A, CapMaTran, Matrix_B, Matrix_B_Temp);
        system("pause");
        printf("\n");
        MENU();
        printf("\n");
        goto ChucNang;
        break;

        case 4:
        printf("=> Ma Tran Con Cua A Va Dinh Thuc Cua Moi Ma Tran Con:\n");
        DISPLAY_MATRIX_CHILD(Matrix_A, CapMaTran, Temp, Matrix_B_Temp,X);
        system("pause");
        printf("\n");
        MENU();
        printf("\n");
        goto ChucNang;
        break;

        case 5:
        DISPLAY_ROOT_OF_AN_EQUATION(X, CapMaTran);
        printf("\n");
        system("pause");
        printf("\n");
        MENU();
        printf("\n");
        goto ChucNang;
        break;

        case 6:
        TryAgain2:
        WRITE_FILE(X, CapMaTran, fptr_outp,File_Name_OUTP);
        system("pause");
        printf("\n");
        MENU();
        printf("\n");
        goto ChucNang;
        break;

        case 0:
        printf("=> Chuong Trinh Da Ket Thuc\n");
        system("pause");
        return 0;
        break;

        default:
        printf("Nhap Chuc Nang Loi.Vui Long Nhap Lai\n");
        goto ChucNang;
    }
    return 0;
}

void INFORMATION_GROUP()
{
    printf("\n|********************************************************|");
    printf("\n|                         GROUP_10                       |");
    printf("\n|********************************************************|");
    printf("\n|     Ho va Ten       ||      Lop        ||   MSSV       |");
    printf("\n|********************************************************|");
    printf("\n| 1. LE QUOC AN       ||   21TCLC_KHDL   ||  102210288   |");
    printf("\n| 2. NGUYEN VAN THANG ||   21TCLC_KHDL   ||  102210307   |");
    printf("\n|                     ||                 ||              |");
    printf("\n|********************************************************|");
}

void INFORMATION_PROJECT()
{
    printf("\n|***********************************************************************************************************************************|");
    printf("\n|                                              INFORMATION OF PROJECT: 207                                                          |");
    printf("\n|                                                                                                                                   |");
    printf("\n|1.Dung Phuong Phap Cramer De Giai Giai He Bat Phuong Trinh Gom n Phuong Trinh, n An: AX = B                                        |");
    printf("\n|                                                                                                                                   |");
    printf("\n|2.Khai Bao Du Lieu: Mang 2 Chieu Cho Ma Tran A Cap n                                                                               |");
    printf("\n|                                                                                                                                   |");
    printf("\n|3.Yeu Cau                                                                                                                          |");
    printf("\n|+ 3.1: Doc So Nguyen Duong n Va Ma Tran Vuong Cap n Tu File DATA.INP                                                               |");
    printf("\n|+ 3.2: Them Cot Cuoi Cung, Ma Moi Phan Tu Bi la tong cac phan tu dung truoc no tren hang do ( Bi = Ai1 + Ai2 + ... + Ai2 )         |");
    printf("\n|+ 3.3: Luu Ket Qua Ra File DATA.OUT                                                                                                |");
    printf("\n|                                                                                                                                   |");
    printf("\n|***********************************************************************************************************************************|");
}

void MENU()
{
    printf("\n|*******************************************************************************************************|");
    printf("\n|                                              CHUC NANG                                                |");
    printf("\n| CHUC NANG  1: Hien Thi Ma Tran A Vua Nhap Tu File                                                     |");
    printf("\n| CHUC NANG  2: Hien Thi Dinh Thuc Cua Ma Tran A Vua Nhap Tu File Va Kiem Tra Dieu Kien                 |");
    printf("\n| CHUC NANG  3: Hien Thi Ma Tran A Thanh Ma Tran B Sau Khi Bien Doi                                     |");
    printf("\n| CHUC NANG  4: Hien Thi Cac Ma Tran Con Va Dinh Thuc Ma Tran Con Cua A ( A1, A2, A3,...,An )           |");
    printf("\n| CHUC NANG  5: Hien Thi Nghiem Cua Bat Phuong Trinh Cua Ma Tran A                                      |");
    printf("\n| CHUC NANG  6: Nhap Ten File De Luu Ket Qua Vao                                                        |");
    printf("\n| CHUC NANG  0: Thoat Khoi Chuong Trinh                                                                 |");
    printf("\n|                                                                                                       |");
    printf("\n|*******************************************************************************************************|");
}

float DETERMINANT(float a[101][101], int n)
{
    float DET_MATRIX = 0;
    if (n == 1)
    {
        return a[1][1];
    }
    if (n == 2)
    {
        return a[1][1] * a[2][2] - a[2][1] * a[1][2];
    }
    for (int i = 1; i <= n; i++)
    {
        float B[101][101]; // MA TRAN THU NHO
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n - 1; k++)
            {
                if (k < i)
                {
                    B[j][k] = a[j + 1][k];
                }
                else
                {
                    B[j][k] = a[j + 1][k + 1];
                }
            }
        }
        DET_MATRIX += pow(-1, i + 1) * a[1][i] * DETERMINANT(B, n - 1);
    }
    return DET_MATRIX;
}

void DISPLAY_MATRIX(float a[101][101],int n)
{
    for ( int i = 1;i <= n;i++ )
    {
        for ( int j = 1;j <= n;j++ )
        {
            printf("%.2lf",a[i][j]);
            printf("\t");
        }
        printf("\n");
    }
}

void READ_FILE(float a[101][101], int &n,FILE *t1,char k1[255])
{
    TryAgain1:
    printf("Nhap Ten File (Du Lieu Vao): ");
    fflush(stdin);
    gets(k1);
    t1 = fopen(k1,"r");
    if( t1 == NULL )
    {
        printf("=> File Khong Ton Tai.Vui Long Nhap Lai\n");
        goto TryAgain1;
    }
    fscanf(t1, "%d", &n);
    for ( int i = 1;i <= n;i++ )
        {
            for ( int j = 1;j <= n;j++ )
            {
                fscanf(t1,"%f",&a[i][j]);
            }
        }
    printf("=> Doc File Du Lieu Vao Thanh Cong\n");
    sleep(2);
    fclose(t1);
}

void DISPLAY_MATRIX_HANDLING(float a[101][101], int n,float b[101][101],float d[101][101])
{
    printf("\n");
    for ( int i = 1;i <= n;i++ )
    {
        for ( int j = 1;j <= n;j++ )
        {
            b[i][n+1] += a[i][j];
        }
    }
    for ( int i = 1;i <= n;i++ )
    {
        for ( int j = 1;j <= n;j++ )
        {
            printf("%.2f",a[i][j]);
            if ( j == n )
            {
                j += 1;
                printf("\t");
                printf("%.2f",b[i][j]);
                printf("\t");
            }
            printf("\t");
        }
        printf("\n");
    }
    for( int i = 1;i <= n;i++ )
    {
        d[i][n+1] = b[i][n+1];
        b[i][n+1] = 0;
    }
}

void DISPLAY_MATRIX_CHILD(float a[101][101],int n,float c[101][101],float d[101][101],float x[101])
{
    for ( int k = 1;k <= n;k++ )
	{
        printf("Ma Tran A%d: \n", k);
		for( int i = 1;i <= n;i++ )
		{
			for(int j = 1;j <= n;j++ )
			{
				if ( j == k )
				{
					c[i][j] = d[i][n+1];
				} else
				{
					c[i][j] = a[i][j];
				}
			}
		}
        DISPLAY_MATRIX(c, n);
		printf("=> Gia Tri Dinh Thuc Cua Ma Tran Con A%d = %.2f\n",k,DETERMINANT(c,n));
        x[k] = DETERMINANT(c,n) / DETERMINANT(a,n);
        printf("\n");
	}
}           

void DISPLAY_ROOT_OF_AN_EQUATION(float x[101],int n)
{
    printf("=> Nghiem Cua He Bat Phuong Trinh:\n");
    for(int i = 1;i <= n;i++)
    { 
        printf("%.2f  ",x[i]);
    }
}

void WRITE_FILE(float x[101],int &n,FILE *t2,char k2[255])
{
    TryAgain2:
    printf("Nhap Ten File (Luu Ket Qua): ");
    fflush(stdin);
    gets(k2);
    t2 = fopen(k2,"w");
    if ( t2 == NULL )
    {
        printf("File Khong Ton Tai.Vui Long Nhap Lai Ten File\n");
        goto TryAgain2;
    }
    for( int i = 1;i <= n;i++ )
	{
		fprintf(t2,"%5.2f",x[i]);
	}
    printf("=> Da Luu Ket Qua Vao File\n");
    fclose(t2);
}