#include <iostream>
#include <math.h>
using namespace std;

struct PhanSo
{
    int iTu,iMau;
};

int ucln(int a, int b)
{
    if (b == 0)
        return a;
    return ucln(b,a%b);
}

void NhapA(PhanSo &a)
{
    cout << "Nhap Phan So A: ";
    cin >> a.iTu >> a.iMau;
}

void NhapB(PhanSo &b)
{
    cout << "\nNhap Phan So B: ";
    cin >> b.iTu >> b.iMau;
} 

void RutGon(PhanSo &c)
{
    int gcd = ucln(abs(c.iTu), abs(c.iMau));
    c.iTu /= gcd;
    c.iMau /= gcd;
}

void XuatPhanSo(PhanSo c)
{
        if(c.iMau < 0)
        {
            c.iTu = -c.iTu;
            c.iMau = -c.iMau;
        }
        if(c.iMau == 1)
        {
            cout << c.iTu;
        }
        else 
        {
            cout << c.iTu <<"/" << c.iMau;
        }
}  


PhanSo TinhTong(PhanSo a, PhanSo b)
{
    PhanSo c;
    c.iTu = (a.iTu * b.iMau) + (b.iTu * a.iMau);
    c.iMau = a.iMau * b.iMau;
    RutGon(c);
    return c;
}

PhanSo TinhHieu(PhanSo a, PhanSo b)
{
    PhanSo c;
    c.iTu = (a.iTu * b.iMau) - (b.iTu * a.iMau);
    c.iMau = a.iMau * b.iMau;
    RutGon(c);
    return c;
}

PhanSo TinhTich(PhanSo a, PhanSo b)
{
    PhanSo c;
    c.iTu = a.iTu * b.iTu;
    c.iMau = b.iMau * a.iMau;
    RutGon(c);
    return c;
}

PhanSo TinhThuong(PhanSo a, PhanSo b)
{
    PhanSo c;
    c.iTu = a.iTu * b.iMau;
    c.iMau = a.iMau * b.iTu;
    RutGon(c);
    return c;
}

int main()
{
    PhanSo a;
    PhanSo b;
    NhapA(a);
    NhapB(b);
    cout << "\nTong Hai Phan So: ";
    XuatPhanSo(TinhTong(a,b));
    cout << "\nHieu Hai Phan So: ";
    XuatPhanSo(TinhHieu(a,b));
    cout << "\nTich Hai Phan So: ";
    XuatPhanSo(TinhTich(a,b));
    cout << "\nThuong Hai Phan So: ";
    XuatPhanSo(TinhThuong(a,b));
    return 0;
}