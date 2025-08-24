/*Headerfile
Họ và tên: LÊ THỊ NHƯ QUỲNH
Lớp		 : Sang T3 - KTLT
*/
//========================================================
//Phần khai báo thư viện
#include <stdio.h>
#include <conio.h>
#include <string.h>
//========================================================
//Phần khai dữ liệu
#define MAXSIZE 100
struct SinhVien
{
	char Mssv[11];
	char ho[8], hoLot[20], ten[8];
	float diemTB;
	char xepLoai[11];
};
typedef SinhVien Itemtype;
//========================================================
//Phần khai báo các nguyên mẫu hàm
void nhapTTSV(Itemtype &x);
void xuatTTSV(Itemtype x);
void xuatDSSV(Itemtype a[], int &n);

void docTTSV(FILE *fi, Itemtype &x);
void ghiTTSV(FILE *fo, Itemtype x);
void docDSSV(char fNameIn[], Itemtype ds[], int&n);
void ghiDSSV(char fNameOut[], Itemtype ds[], int n);

void swap(Itemtype &a, Itemtype &b);
void sapXepTangDanTheoDTB_InterchangeSort(Itemtype a[], int n);//Sắp xếp danh sách sinh viên tăng dần theo điểm trung bình (đổi chỗ trực tiếp)
void sapXepTangDanTheoDTB_SelectionSort(Itemtype a[], int n);//Sắp xếp danh sách sinh viên tăng dần theo điểm trung bình (chọn trực tiếp)
void sapXepTangDanTheoDTB_QuickSort(Itemtype a[], int Left, int Right);//Sắp xếp danh sách sinh viên tăng dần theo điểm trung bình (QuickSort)
void xuatSVCoDiemTBCaoNhat(Itemtype a[], int n); //Tìm và in ra sinh viên có điểm trung bình cao nhất
void xepLoai(Itemtype &a);
void xuatSVXepLoaiGioiVaKha(Itemtype a[], int n); //In danh sách sinh viên có xếp loại Giỏi và Khá
int demSVHoNguyen(Itemtype a[], int n); //Đếm sinh viên có họ Nguyễn

void showMenu();
void process();
//========================================================
//Phần khai chương trình chính
void main()
{
	process();
}
void showMenu()
{
	printf("\n**********************************************************");
	printf("\n*                    MENU                                *");
	printf("\n**********************************************************");
	printf("\n* 0.Thoat chuong trinh                                   *");
	printf("\n* 1.Doc danh sach sinh vien tu file text                 *");
	printf("\n* 2.Xem noi dung danh sach sinh vien                     *");
	printf("\n* 3.Ghi DSSV xuong file text                             *");
	printf("\n* 4.Sap xep DSSV tang dan theo diem TB (InterchangeSort) *");
	printf("\n* 5.Sap xep DSSV tang dan theo diem TB (SelectionSort)   *");
	printf("\n* 6.Sap xep DSSV tang dan theo diem TB (QuickSort)       *");
	printf("\n* 7.Xuat sinh vien co diem TB cao nhat                   *");
	printf("\n* 8.Xuat sinh vien xep loai gioi va kha                  *");
	printf("\n* 9.Dem so sinh vien co ho Nguyen                        *");
	printf("\n**********************************************************");
}
void process()
{
	char FileName_In[] = "DSSinhVien_In.txt";
	char FileName_Out[] = "DSSinhVien_Out.txt";
	Itemtype a[MAXSIZE];
	int n, kq;
	int luaChon;
	do
	{
		showMenu();
		printf("\nBan hay lua chon mot chuc nang: ");
		scanf("%d", &luaChon);

		switch (luaChon)
		{
		case 1:
			docDSSV(FileName_In, a, n);
			printf("NOI DUNG DANH SACH SINH VIEN LOAD TU FILE TEXT\n");
			xuatDSSV(a, n);
			break;
		case 2:
			printf("NOI DUNG DANH SACH SINH VIEN\n");
			xuatDSSV(a, n);
			break;
		case 3:
			printf("GHI DANH SACH SINH VIEN DOC XUONG FILE\n");
			ghiDSSV(FileName_Out, a, n);
			break;
		case 4:
			sapXepTangDanTheoDTB_InterchangeSort(a, n);
			printf("NOI DUNG DSSV SAU KHI SAP XEP TANG DAN THEO DIEM TB (InterchangeSort)\n");
			xuatDSSV(a, n);
			break;
		case 5:
			sapXepTangDanTheoDTB_SelectionSort(a, n);
			printf("NOI DUNG DSSV SAU KHI SAP XEP TANG DAN THEO DIEM TB (SelectionSort)\n");
			xuatDSSV(a, n);
			break;
		case 6:
			sapXepTangDanTheoDTB_QuickSort(a, 0, n - 1);
			printf("NOI DUNG DSSV SAU KHI SAP XEP TANG DAN THEO DIEM TB (QuickSort)\n");
			xuatDSSV(a, n);
			break;
		case 7:
			printf("DANH SACH SINH VIEN CO DIEM TRUNG BINH CAO NHAT: \n");
			xuatSVCoDiemTBCaoNhat(a, n);
			break;
		case 8:
			printf("DANH SACH SINH VIEN CO XEP LOAI GIOI VA KHA: \n");
			xuatSVXepLoaiGioiVaKha(a, n);
			break;
		case 9:
			kq = demSVHoNguyen(a, n);
			if (kq == -1)
				printf("Khong co sinh vien nao co ho Nguyen");
			else
				printf("Co %d sinh vien co ho Nguyen", kq);
			break;

		}
	} while (luaChon != 0);
}
//========================================================
//Phần định nghĩa các hàm
void nhapTTSV(Itemtype &x)
{
	printf("MSSV: "); fflush(stdin); gets(x.Mssv);
	printf("Ho: "); fflush(stdin); gets(x.ho);
	printf("Ho lot: "); fflush(stdin); gets(x.hoLot);
	printf("Ten: "); fflush(stdin); gets(x.ten);
	printf("Diem trung binh: "); scanf("%f", &x.diemTB);
}
//--------------------------------
void xuatTTSV(Itemtype x)
{
	printf("%-15s%-10s%-20s%-10s%-10.2lf%-11s\n", x.Mssv, x.ho, x.hoLot, x.ten, x.diemTB, x.xepLoai);
}
//--------------------------------
void docTTSV(FILE *fi, Itemtype &x)
{
	fscanf(fi, "%[^#]#%[^#]#%[^#]#%[^#]#%f\n", &x.Mssv, &x.ho, &x.hoLot, &x.ten, &x.diemTB);
	xepLoai(x);
}
//--------------------------------
void ghiTTSV(FILE *fo, Itemtype x)
{
	fprintf(fo, "%-15s%-10s%-20s%-10s%-10.2lf%-11s\n", x.Mssv, x.ho, x.hoLot, x.ten, x.diemTB, x.xepLoai);
}
//--------------------------------
void docDSSV(char fNameIn[], Itemtype ds[], int&n)
{
	FILE *fi = fopen(fNameIn, "rt"); //read text
	if (fi == NULL)
	{
		printf("Loi mo file de doc du lieu");
		getch();
		return;
	}
	fscanf(fi, "%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		Itemtype x;
		docTTSV(fi, x);
		ds[i] = x;
	}
	fclose(fi);
}
//--------------------------------
void ghiDSSV(char fNameOut[], Itemtype ds[], int n)
{
	FILE *fo = fopen(fNameOut, "wt");
	if (fo == NULL)
	{
		printf("Loi mo file de ghi du lieu");
		getch();
		return;
	}
	fprintf(fo, "%-5s%-15s%-40s%-10s%-11s\n", "STT", "MSSV", "HO VA TEN SV", "DIEM TB", "XEP LOAI");
	for (int i = 0; i < n; i++)
	{
		fprintf(fo, "%-5d", i + 1);
		ghiTTSV(fo, ds[i]);
	}
	fclose(fo);
}
//--------------------------------
void xuatDSSV(Itemtype a[], int &n)
{
	printf("%-5s%-15s%-40s%-10s%-11s\n", "STT", "MSSV", "HO VA TEN SV", "DIEM TB", "XEP LOAI");
	for (int i = 0; i < n; i++)
	{
		printf("%-5d", i + 1);
		xuatTTSV(a[i]);
	}
}

//--------------------------------
void swap(Itemtype &a, Itemtype &b)
{
	Itemtype tmp = a;
	a = b;
	b = tmp;
}
//--------------------------------
void sapXepTangDanTheoDTB_InterchangeSort(Itemtype a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].diemTB > a[j].diemTB)
				swap(a[i], a[j]);
		}
	}
}
//--------------------------------
void sapXepTangDanTheoDTB_SelectionSort(Itemtype a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[min].diemTB>a[j].diemTB)
				min = j;
		}
		swap(a[i], a[min]);
	}

}
//========================================================
void sapXepTangDanTheoDTB_QuickSort(Itemtype a[], int Left, int Right)
{
	if (Left >= Right)
		return;
	int Mid = (Left + Right) / 2;
	float t = a[Mid].diemTB;
	int i = Left;
	int j = Right;
	do
	{
		while (a[i].diemTB < t)
			i++;
		while (a[j].diemTB > t)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i < j);
	sapXepTangDanTheoDTB_QuickSort(a, Left, Mid - 1);
	sapXepTangDanTheoDTB_QuickSort(a, Mid + 1, Right);
}
//========================================================
void xuatSVCoDiemTBCaoNhat(Itemtype a[], int n)
{//Tìm và in ra sinh viên có điểm trung bình cao nhất
	Itemtype b[10];
	float max = a[0].diemTB;
	int m = 0;

	for (int i = 0; i < n; i++)
	{
		if (a[i].diemTB > max)
		{
			max = a[i].diemTB;
			m = 1;
			b[0] = a[i]; 
		}
		else if (a[i].diemTB == max)
		{
			b[m++] = a[i]; 
		}
	}

	for (int i = 0; i < m; i++)
	{
		xuatTTSV(b[i]);

	}
}
//========================================================
void xuatSVXepLoaiGioiVaKha(Itemtype a[], int n)
{//In danh sách sinh viên có xếp loại Giỏi và Khá
	for (int i = 0; i < n; i++)
	{
		if ((strcmp(a[i].xepLoai, "Gioi") == 0) || (strcmp(a[i].xepLoai, "Kha") == 0))
			xuatTTSV(a[i]);
	}
}
//========================================================
int demSVHoNguyen(Itemtype a[], int n)
{ //Đếm sinh viên có họ Nguyễn
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].ho, "Nguyen") == 0)
			dem++;
	}
	return dem;
}
//========================================================
void xepLoai(Itemtype &a)
{
	if (a.diemTB >= 8)
		strcpy(a.xepLoai, "Gioi");
	else if (a.diemTB >= 6.5)
		strcpy(a.xepLoai, "Kha");
	else if (a.diemTB >= 5.0)
		strcpy(a.xepLoai, "Trung binh");
	else
		strcpy(a.xepLoai, "Yeu");
}