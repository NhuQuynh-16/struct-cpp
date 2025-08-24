//﻿Headerfile
// Họ và tên: LÊ THỊ NHƯ QUỲNH
// Lớp		 : Sang T3 - KTLT

//========================================================
//Phần khai báo thư viện
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
//========================================================
//Phần khai dữ liệu
struct PhanSo
{
	int tu;
	int mau;
};
struct HonSo
{
	int n;
	PhanSo p;
};
typedef HonSo ItemType;
//========================================================
//Phần khai báo các nguyên mẫu hàm
void nhapPhanSo(PhanSo& p);
void taoPhanSo(PhanSo& p);
void daoDauPhanSo(PhanSo& p);
int UCLN(int a, int b);
void rutGonPhanSo(PhanSo &p);
void xuatPhanSo(PhanSo p);

int soSanhPhanSo(PhanSo a, PhanSo b);
void xuatPSCoMauLonHonTu(ItemType *a, int n);
int demPSCoMauVaTuChan(ItemType *a, int n);
ItemType timPSLonNhat(ItemType *a, int n);
void xoaPTTaiViTriK(ItemType *&a, int &n, int k);
void themPT_X_TaiViTriK(ItemType *&a, int &n, int k, ItemType x);

//Phan hon so
void nhapHonSo(ItemType& h);
void taoHonSo(ItemType& h);
void xuatHonSo(ItemType h);
void rutGonHonSo(ItemType &h);

void nhapMang1c_HonSo(ItemType *&a, int &n);
void taoMang1c_HonSo(ItemType *&a, int &n);
void xuatMang1c_HonSo(ItemType *a, int n);

int soSanhHonSo(ItemType hs1, ItemType hs2);
PhanSo chuyenHonSoSangPhanSo(ItemType &h);
ItemType chuyenPhanSoSangHonSo(PhanSo &a);
void swap(ItemType &a, ItemType &b);
void sapXepHonSoTangDan_InterchangeSort(ItemType *a, int n);
void sapXepHonSoTangDan_SelectionSort(ItemType *a, int n);
void sapXepHonSoTangDan_QuickSort(ItemType *a, int Left, int Right);
int timHonSoX_LinearSearch(ItemType *a, int n, ItemType x);
int timHonSoX_BinarySearch(ItemType *a, int n, ItemType x);
void chuyenChanLe(ItemType *a, int n); //Chuyển phần nguyên chẵn lên đầu mảng, chuyển phần nguyên lẻ xuống cuối mảng
void chiaThanh2MangPhanNguyenVaPhanPS(ItemType *a, int n, int *&s1, PhanSo *&s2);
void xoaPTTaiViTriK(ItemType *&a, int &n, int k);
void themXVaoViTriK(ItemType *&a, int &n, ItemType x, int k);
ItemType timHonSoMax(ItemType *a, int n);
void xuatViTriPTCoPhanNguyenChan(ItemType *a, int n);

void xuatMangSoNguyen(int *a, int n);
void xuatMang_PhanSo(PhanSo *a, int n);

void showMenu();
void process();
//========================================================
//Phần khai chương trình chính
void main()
{
	process();
	return;
}
//-------------------------------------------------------
void showMenu()
{
	printf("\n****************************************************************************");
	printf("\n*                    MENU                                                  *");
	printf("\n****************************************************************************");
	printf("\n* 0.Thoat chuong trinh                                                     *");
	printf("\n* 1. Nhap mang hon so (tu ban phim)                                        *");
	printf("\n* 2. Tao mang hon so (ngau nhien)                                          *");
	printf("\n* 3. Xem noi dung cua mang                                                 *");
	printf("\n* 4. So sanh 2 hon so                                                      *");
	printf("\n* 5. Chuyen hon so sang phan so                                            *");
	printf("\n* 6. Chuyen phan so sang hon so                                            *");
	printf("\n* 7. Sap xep mang tang dan (InterchangeSort)                               *");
	printf("\n* 8. Sap xep mang tang dan (SelectionSort)                                 *");
	printf("\n* 9. Sap xep mang tang dan (QuickSort)                                     *");
	printf("\n* 10. Tim hon so x (LinearSearch)                                          *");
	printf("\n* 11. Tim hon so x (BinarySearch)                                          *");
	printf("\n* 12. Chuyen phan nguyen chan len dau mang, phan nguyen le xuong cuoi mang *");
	printf("\n* 13. Chia thanh 2 mang s1 chua phan nguyen, s2 chua phan phan so          *");
	printf("\n* 14. Xoa phan tu tai vi tri k                                             *");
	printf("\n* 15. Them phan tu x tai vi tri k                                          *");
	printf("\n* 16. Tim phan tu lon nhat                                                 *");
	printf("\n* 17. Xuat vi tri phan tu co phan nguyen chan                              *");
	printf("\n***************************************************************************");
}
//-------------------------------------------------------
void process()
{

	ItemType *A = NULL, X;
	ItemType Hs1, Hs2;
	PhanSo P,*S2;
	int N = 0, kq, k, p, *S1;
	int luaChon;
	do
	{
		showMenu();
		printf("\nBan hay lua chon mot chuc nang: ");
		scanf("%d", &luaChon);

		switch (luaChon)
		{
		case 1:
			nhapMang1c_HonSo(A, N);
			printf("NOI DUNG MANG VUA NHAP TU BAN PHIM LA: \n");
			xuatMang1c_HonSo(A, N);
			break;
		case 2:
			taoMang1c_HonSo(A, N);
			printf("NOI DUNG MANG VUA TAO NGAU NHIEN LA: \n");
			xuatMang1c_HonSo(A, N);
			break;
		case 3:
			printf("NOI DUNG CUA MANG LA: \n");
			xuatMang1c_HonSo(A, N);
			break;
		case 4:
			printf("Nhap hon so thu nhat: ");
			nhapHonSo(Hs1);
			printf("Nhap hon so thu hai: ");
			nhapHonSo(Hs2);
			kq = soSanhHonSo(Hs1, Hs2);
			if (kq == 1)
			{
				xuatHonSo(Hs1); printf(" lon hon "); xuatHonSo(Hs2);
			}
			else if (kq == 0)
			{
				xuatHonSo(Hs1); printf(" bang "); xuatHonSo(Hs2);
			}
			else
			{
				xuatHonSo(Hs1); printf(" nho hon "); xuatHonSo(Hs2);
			}
			break;
		case 5:
			nhapHonSo(Hs1);
			xuatHonSo(Hs1);
			printf(" chuyen sang phan so bang ");
			P = chuyenHonSoSangPhanSo(Hs1);
			xuatPhanSo(P);
			break;
		case 6:
			nhapPhanSo(P);
			xuatPhanSo(P);
			printf(" chuyen sang hon so bang ");
			Hs1 = chuyenPhanSoSangHonSo(P);
			xuatHonSo(Hs1);
			break;
		case 7:
			sapXepHonSoTangDan_InterchangeSort(A, N);
			printf("NOI DUNG CUA MANG HON SO SAU KHI SAP XEP TANG DAN (InterchangSort): \n");
			xuatMang1c_HonSo(A, N);
			break;
		case 8:
			sapXepHonSoTangDan_SelectionSort(A, N);
			printf("NOI DUNG CUA MANG HON SO SAU KHI SAP XEP TANG DAN (SelectionSort): \n");
			xuatMang1c_HonSo(A, N);
			break;
		case 9:
			sapXepHonSoTangDan_QuickSort(A, 0, N - 1);
			printf("NOI DUNG CUA MANG HON SO SAU KHI SAP XEP TANG DAN (QuickSort): \n");
			xuatMang1c_HonSo(A, N);
			break;
		case 10:
			nhapHonSo(Hs1);
			kq = timHonSoX_LinearSearch(A, N, Hs1);
			if (kq == -1)
				printf("Khong tim thay!");
			else
				printf("Tim thay tai vi tri thu %d", kq);
			break;
		case 11:
			nhapHonSo(Hs1);
			kq = timHonSoX_BinarySearch(A, N, Hs1);
			if (kq == -1)
				printf("Khong tim thay!");
			else
				printf("Tim thay tai vi tri thu %d", kq);
			break;
		case 12:
			chuyenChanLe(A, N);
			printf("Mang sau khi chuyen phan nguyen chan len dau mang va phan nguyen le xuong cuoi mang: \n");
			xuatMang1c_HonSo(A, N);
			break;
		case 13:
			chiaThanh2MangPhanNguyenVaPhanPS(A, N, S1, S2);
			printf("NOI DUNG MANG PHAN NGUYEN: \n");
			xuatMangSoNguyen(S1, N);
			printf("\nNOI DUNG MANG PHAN PHAN SO: \n");
			xuatMang_PhanSo(S2, N);
			break;
		case 14:
			printf("Nhap vi tri k: "); scanf("%d", &k);
			xoaPTTaiViTriK(A, N, k);
			printf("NOI DUNG CUA MANG SAU KHI XOA PHAN TU TAI VI TRI %d: \n", k);
			xuatMang1c_HonSo(A, N);
			break;
		case 15:
			nhapHonSo(Hs1);
			printf("Nhap vi tri k: ");
			scanf("%d", &k);

			themXVaoViTriK(A, N, Hs1, k);
			printf("NOI DUNG CUA MANG SAU KHI THEM PHAN TU %d(%d/%d) VAO VI TRI %d\n", Hs1.n, Hs1.p.tu, Hs1.p.mau, k);
			xuatMang1c_HonSo(A, N);
			break;
		case 16:
			Hs1 = timHonSoMax(A, N);
			printf("Phan tu lon nhat trong mang la: ");
			xuatHonSo(Hs1);
			break;
		}
	} while (luaChon != 0);
	free(A);
}
//========================================================
//Phần định nghĩa các hàm
void nhapPhanSo(PhanSo& p)
{
	printf("Nhap tu so: ");
	scanf("%d", &p.tu);
	do
	{
		printf("Nhap mau so: "); scanf("%d", &p.mau);
	} while (p.mau == 0);
}

//========================================================
void daoDauPhanSo(PhanSo& p)
{
	if (p.mau < 0)
	{
		p.tu *= -1;
		p.mau *= -1;
	}
}
//========================================================
int UCLN(int a, int b)
{
	a = abs(a);
	b = abs(b);
	if (a == 0) return 1;
	if (b == 0) return 1;
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}
//========================================================
void rutGonPhanSo(PhanSo &p)
{
	int ucln = UCLN(p.tu, p.mau);
	p.tu /= ucln;
	p.mau /= ucln;
}

//========================================================
void taoPhanSo(PhanSo& p)
{
	int x = -99, y = 99;
	p.tu = rand() % (y - x + 1) + x;
	do
	{
		int x = -99, y = 99;
		p.mau = rand() % (y - x + 1) + x;
	} while (p.mau == 0);
	daoDauPhanSo(p);
	rutGonPhanSo(p);
}
//========================================================
void xuatPhanSo(PhanSo p)
{
	printf("%d/%d", p.tu, p.mau);
}
//========================================================
void nhapHonSo(ItemType& h)
{
	printf("Nhap phan nguyen: ");
	scanf("%d", &h.n);
	nhapPhanSo(h.p);
}
//========================================================
void taoHonSo(ItemType& h)
{
	int p = -99, y = 99;
	h.n = rand() % (y - p + 1) + p;
	taoPhanSo(h.p);
}
//========================================================
void xuatHonSo(ItemType h)
{
	printf("%d(", h.n);
	xuatPhanSo(h.p);
	printf(")");
}
//========================================================
void rutGonHonSo(ItemType &h)
{
	if (abs(h.p.tu) >= abs(h.p.mau))
	{
		h.n += 1;
		h.p.tu %= h.p.mau;
	}
}
//========================================================
void taoMang1c_HonSo(ItemType *&a, int &n)
{
	do {
		printf("Ban hay cho biet so node can tao: ");
		scanf("%d", &n);
	} while (n <= 0);
	a = new ItemType[n];

	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		ItemType tmp;
		taoHonSo(tmp);
		rutGonHonSo(tmp);
		a[i] = tmp;
	}
}
//========================================================
void nhapMang1c_HonSo(ItemType *&a, int &n)
{
	printf("Nhap so phan tu cua mang: ");
	scanf("%d", &n);
	a = new ItemType[n];

	for (int i = 0; i < n; i++)
	{
		ItemType tmp;
		nhapHonSo(tmp);
		rutGonHonSo(tmp);
		a[i] = tmp;

	}
}
//========================================================
void xuatMang1c_HonSo(ItemType *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		xuatHonSo(a[i]);
		printf(" ");
	}
}
//========================================================
int soSanhPhanSo(PhanSo a, PhanSo b)
{
	if (a.tu*b.mau > b.tu*a.mau)
		return 1;
	if (a.tu*b.mau < b.tu*a.mau) 
		return -1;
	return 0;
}
//========================================================
int soSanhHonSo(ItemType hs1, ItemType hs2)
{
	PhanSo p = chuyenHonSoSangPhanSo(hs1);
	PhanSo q = chuyenHonSoSangPhanSo(hs2);
	return soSanhPhanSo(p, q);
}
//========================================================
void swap(ItemType &a, ItemType &b)
{
	ItemType tmp = a;
	a = b;
	b = tmp;
}
//========================================================
PhanSo chuyenHonSoSangPhanSo(ItemType &a)
{
	PhanSo p;
	p.tu = a.n * a.p.mau + a.p.tu;
	p.mau = a.p.mau;
	return p;
}
//========================================================
ItemType chuyenPhanSoSangHonSo(PhanSo &a)
{
	ItemType hs;
	hs.n = a.tu / a.mau;
	hs.p.tu = a.tu %a.mau;
	hs.p.mau = a.mau;
	return hs;
}
//========================================================
void sapXepHonSoTangDan_InterchangeSort(ItemType *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (soSanhHonSo(a[i], a[j])>0)
				swap(a[i], a[j]);
		}
	}
}
//========================================================
void sapXepHonSoTangDan_SelectionSort(ItemType *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (soSanhHonSo(a[min], a[j])>0)
				min = j;
		}
		if (min != i)
			swap(a[min], a[i]);
	}
}
//========================================================
void sapXepHonSoTangDan_QuickSort(ItemType *a, int Left, int Right)
{
	if (Left >= Right) return;
	int i = Left, j = Right;
	int Mid = (Left + Right) / 2;
	ItemType x = a[Mid];
	do
	{
		while (soSanhHonSo(a[i], x)<0)
			i++;
		while (soSanhHonSo(a[j], x)>0)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}

	} while (i < j);
	sapXepHonSoTangDan_QuickSort(a, Left, j);
	sapXepHonSoTangDan_QuickSort(a, i, Right);
}
//========================================================
int timHonSoX_LinearSearch(ItemType *a, int n, ItemType x)
{

	for (int i = 0; i < n; i++)
	{
		if (soSanhHonSo(a[i], x) == 0)
			return i;
	}
	return -1;
}
//========================================================
int timHonSoX_BinarySearch(ItemType *a, int n, ItemType x)
{
  sapXepHonSoTangDan_InterchangeSort(a,n);
	int Left = 0;
	int Right = n - 1;
	while (Left <= Right)
	{
		int Mid = (Left + Right) / 2;
		if (soSanhHonSo(a[Mid], x) == 0)
			return Mid;
		else if (soSanhHonSo(x, a[Mid]) < 0)
			Right = Mid - 1;
		else
			Left = Mid + 1;

	}
	return -1;
}
//========================================================
void chuyenChanLe(ItemType *a, int n)
{//Chuyển phần nguyên chẵn lên đầu mảng, chuyển phần nguyên lẻ xuống cuối mảng
	int i = 0, j = n - 1;
	while (i <= j)
	{
		while (a[i].n % 2 == 0)
			i++;
		while (a[j].n % 2 != 0)
			j--;
		if (i <= j)
			swap(a[i], a[j]);
		i++;
		j--;
	}
}
//========================================================
void chiaThanh2MangPhanNguyenVaPhanPS(ItemType *a, int n, int *&s1, PhanSo *&s2)
{
	s1 = new int[n];
	s2 = new PhanSo[n];

	for (int i = 0; i < n; i++)
	{
		s1[i] = a[i].n;
		s2[i] = a[i].p;
	}
}
//========================================================
void xoaPTTaiViTriK(ItemType *&a, int &n, int k)
{
	if (k < 0 || k >= n) {
		printf("Vi tri k khong hop le!");
		return;
	}
	for (int i = k; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
//========================================================
void themXVaoViTriK(ItemType *&a, int &n, ItemType x, int k)
{
	if (k < 0 || k >= n) {
		printf("Vi tri k khong hop le!");
		return;
	}
	ItemType *newA = new ItemType[n + 1];
	for (int i = 0; i < k; i++)
	{
		newA[i] = a[i];
	}
	newA[k] = x;
	for (int i = k; i < n; i++)
	{
		newA[i + 1] = a[i];
	}
	delete[] a;
	a = newA;
	n++;
}
//========================================================
ItemType timHonSoMax(ItemType *a, int n)
{
	ItemType max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (soSanhHonSo(max, a[i])>0)
		{
			max = a[i];
		}
	}
	return max;
}
//========================================================
void xuatViTriPTCoPhanNguyenChan(ItemType *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i].n % 2 == 0)
			printf("%d ", i);
	}
}
//========================================================
void xuatMangSoNguyen(int *a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}
//========================================================
void xuatMang_PhanSo(PhanSo *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		xuatPhanSo(a[i]);
		printf(" ");
	}
}

