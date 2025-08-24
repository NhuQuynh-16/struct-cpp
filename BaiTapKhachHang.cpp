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
struct KhachHang
{
	char hoTen[35];
	char soDienThoai[15];
	int soVeNguoiLon;
	int soVeTreEm;
	char tenPhim[35];
	char phongChieu[10];
	char xuatChieu[20];
	int tienPhaiTra;
	char ho[8], hoLot[20], ten[8];
};
typedef KhachHang Itemtype;
//========================================================
//Phần khai báo các nguyên mẫu hàm
void nhapTTKH(Itemtype &x);
void xuatTTKH(Itemtype x);
void xuatDSKH(Itemtype dskh[], int &n);

void docTTKH(FILE *fi, Itemtype &x);
void ghiTTKH(FILE *fo, Itemtype x);
void docDSKH(char fNameIn[], Itemtype dskh[], int&n);
void ghiDSKH(char fNameOut[], Itemtype dskh[], int n);

int tinhTienPhaiTra(Itemtype &x);
void swap(Itemtype &a, Itemtype &b);
void sapXepTangDanTheoTienPhaiTra_InterchangeSort(Itemtype dskh[], int n);//Sắp xếp danh sách khách hàng tăng dần theo tiền phải trả (đổi chỗ trực tiếp)
void sapXepTangDanTheoTienPhaiTra_SelectionSort(Itemtype dskh[], int n);//Sắp xếp danh sách khách hàng tăng dần theo tiền phải trả (chọn trực tiếp)
void sapXepTangDanTheoTienPhaiTra_QuickSort(Itemtype dskh[], int Left, int Right);//Sắp xếp danh sách khách hàng tăng dần theo tiền phải trả (QuickSort)
void xuatKHDatVePhongChieuXVaXuatChieuY(Itemtype dskh[], int n, char x[], char y[]);
int tinhTongDoanhThu(Itemtype dskh[], int n);


void showMenu();
void process();
//========================================================
//Phần khai chương trình chính
void main()
{
	process();
	return;
}
void showMenu()
{
	printf("\n****************************************************************");
	printf("\n*                    MENU                                      *");
	printf("\n****************************************************************");
	printf("\n* 0.Thoat chuong trinh                                         *");
	printf("\n* 1.Doc danh sach sinh vien tu file text                       *");
	printf("\n* 2.Xem noi dung danh sach sinh vien                           *");
	printf("\n* 3.Ghi DSKH xuong file text                                   *");
	printf("\n* 4.Sap xep DSKH tang dan theo tien phai tra (InterchangeSort) *");
	printf("\n* 5.Sap xep DSKH tang dan theo tien phai tra (SelectionSort)   *");
	printf("\n* 6.Sap xep DSKH tang dan theo tien phai tra (QuickSort)       *");
	printf("\n* 7.Xuat khach hang dat ve phong chieu x va xuat chieu y       *");
	printf("\n* 8.Tong doanh thu cua rap phim                                *");
	printf("\n* 9.Dem so sinh vien co ho Nguyen                              *");
	printf("\n****************************************************************");
}
void process()
{
	char FileName_In[] = "DSKhachHang_In.txt";
	char FileName_Out[] = "DSKhachHang_Out.txt";
	Itemtype a[MAXSIZE];
	int n, kq;
	char x[10], y[20];
	int luaChon;
	do
	{
		showMenu();
		printf("\nBan hay lua chon mot chuc nang: ");
		scanf("%d", &luaChon);

		switch (luaChon)
		{
		case 1:
			docDSKH(FileName_In, a, n);
			printf("NOI DUNG DANH SACH KHACH HANG LOAD TU FILE TEXT\n");
			xuatDSKH(a, n);
			break;
		case 2:
			printf("NOI DUNG DANH SACH KHACH HANG\n");
			xuatDSKH(a, n);
			break;
		case 3:
			printf("GHI DANH SACH KHACH HANG DOC XUONG FILE\n");
			ghiDSKH(FileName_Out, a, n);
			break;
		case 4:
			sapXepTangDanTheoTienPhaiTra_InterchangeSort(a, n);
			printf("NOI DUNG DSKH SAU KHI SAP XEP TANG DAN THEO SO TIEN PHAI TRA (InterchangeSort)\n");
			xuatDSKH(a, n);
			break;
		case 5:
			sapXepTangDanTheoTienPhaiTra_SelectionSort(a, n);
			printf("NOI DUNG DSKH SAU KHI SAP XEP TANG DAN THEO SO TIEN PHAI TRA (SelectionSort)\n");
			xuatDSKH(a, n);
			break;
		case 6:
			sapXepTangDanTheoTienPhaiTra_QuickSort(a, 0, n - 1);
			printf("NOI DUNG DSKH SAU KHI SAP XEP TANG DAN THEO SO TIEN PHAI TRA (QuickSort)\n");
			xuatDSKH(a, n);
			break;
		case 7:
			printf("Nhap phong chieu: "); fflush(stdin);  gets(x);
			printf("Nhap xuat chieu: "); fflush(stdin);  gets(y);
			printf("DANH SACH KHACH HANG DAT VE PHONG CHIEU %s VA XUAT CHIEU %s: \n",x,y);
			xuatKHDatVePhongChieuXVaXuatChieuY(a, n, x, y);
			break;
		case 8:
			kq = tinhTongDoanhThu(a, n);
			printf("TONG DOANH THU CUA RAP PHIM: %d\n",kq);
			break;
		case 9:
			
			break;

		}
	} while (luaChon != 0);
}
//========================================================
//Phần định nghĩa các hàm

void xuatTTKH(Itemtype x)
{
	printf("%-35s%-15s%-20d%-20d%-35s%-15s%-15s%-20d\n", x.hoTen, x.soDienThoai, x.soVeNguoiLon, x.soVeTreEm, x.tenPhim, x.phongChieu, x.xuatChieu, x.tienPhaiTra);
}
//--------------------------------
void docTTKH(FILE *fi, Itemtype &x)
{
	fscanf(fi, "%[^#]#%[^#]#%d#%d#%[^#]#%[^#]#%s\n", x.hoTen, x.soDienThoai, x.soVeNguoiLon, x.soVeTreEm, x.tenPhim, x.phongChieu, x.xuatChieu);
	x.tienPhaiTra=tinhTienPhaiTra(x);
}
//--------------------------------
void ghiTTKH(FILE *fo, Itemtype x)
{
	fprintf(fo, "%-35s%-15s%-20d%-20d%-35s%-15s%-15s%-20d\n", x.hoTen, x.soDienThoai, x.soVeNguoiLon, x.soVeTreEm, x.tenPhim, x.phongChieu, x.xuatChieu, x.tienPhaiTra);
}
//--------------------------------
void docDSKH(char fNameIn[], Itemtype dskh[], int&n)
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
		docTTKH(fi, x);
		dskh[i] = x;
	}
	fclose(fi);
}
//--------------------------------
void ghiDSKH(char fNameOut[], Itemtype dskh[], int n)
{
	FILE *fo = fopen(fNameOut, "wt");
	if (fo == NULL)
	{
		printf("Loi mo file de ghi du lieu");
		getch();
		return;
	}
	fprintf(fo, "%-5s%-40s%-15s%-20s%-20s%-35s%-15s%-15s%-20s\n", "STT", "HO VA TEN KH", "SO DT", "SO VE NGUOI LON", "SO VE TRE EM","TEN PHIM","PHONG CHIEU", "XUAT CHIEU","TIEN PHAI TRA");
	for (int i = 0; i < n; i++)
	{
		fprintf(fo, "%-5d", i + 1);
		ghiTTKH(fo, dskh[i]);
	}
	fclose(fo);
}
//--------------------------------
void xuatDSKH(Itemtype dskh[], int &n)
{
	printf("%-5s%-40s%-15s%-20s%-20s%-35s%-15s%-15s%-20s\n", "STT", "HO VA TEN KH", "SO DT", "SO VE NGUOI LON", "SO VE TRE EM", "TEN PHIM", "PHONG CHIEU", "XUAT CHIEU", "TIEN PHAI TRA");
	for (int i = 0; i < n; i++)
	{
		printf("%-5d", i + 1);
		xuatTTKH(dskh[i]);
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
void sapXepTangDanTheoTienPhaiTra_InterchangeSort(Itemtype dskh[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (dskh[i].tienPhaiTra > dskh[j].tienPhaiTra)
				swap(dskh[i], dskh[j]);
		}
	}
}
//--------------------------------
void sapXepTangDanTheoTienPhaiTra_SelectionSort(Itemtype dskh[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (dskh[min].tienPhaiTra>dskh[j].tienPhaiTra)
				min = j;
		}
		swap(dskh[i], dskh[min]);
	}

}
//========================================================
void sapXepTangDanTheoTienPhaiTra_QuickSort(Itemtype dskh[], int Left, int Right)
{
	if (Left >= Right)
		return;
	int Mid = (Left + Right) / 2;
	float t = dskh[Mid].tienPhaiTra;
	int i = Left;
	int j = Right;
	do
	{
		while (dskh[i].tienPhaiTra < t)
			i++;
		while (dskh[j].tienPhaiTra > t)
			j--;
		if (i <= j)
		{
			swap(dskh[i], dskh[j]);
			i++;
			j--;
		}
	} while (i < j);
	sapXepTangDanTheoTienPhaiTra_QuickSort(dskh, Left, Mid - 1);
	sapXepTangDanTheoTienPhaiTra_QuickSort(dskh, Mid + 1, Right);
}
//========================================================
void xuatKHDatVePhongChieuXVaXuatChieuY(Itemtype dskh[], int n, char x[], char y[])
{//In danh sách khách hàng có xếp loại Giỏi và Khá
	for (int i = 0; i < n; i++)
	{
		if ((strcmp(dskh[i].phongChieu, x) == 0) || (strcmp(dskh[i].xuatChieu, y) == 0))
			xuatTTKH(dskh[i]);
	}
}
//========================================================
int tinhTongDoanhThu(Itemtype dskh[], int n) 
{
	int tongDoanhThu = 0;
	for (int i = 0; i < n; i++) {
		tongDoanhThu += dskh[i].tienPhaiTra;
	}
	return tongDoanhThu;
}
//========================================================
int tinhTienPhaiTra(Itemtype &x)
{
	return x.soVeNguoiLon * 40000 + x.soVeTreEm * 20000;
}
//========================================================
