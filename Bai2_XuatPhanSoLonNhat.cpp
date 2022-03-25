#include <iostream>
#include <math.h>
using namespace std;

struct PhanSo
{
    int TuSo;
    int MauSo;
};

void NhapA(PhanSo &a)
{
    cout << "Nhap phan so a: ";
    cin >> a.TuSo >> a.MauSo;
}

void NhapB(PhanSo &b)
{
    cout << "Nhap phan so b: ";
    cin >> b.TuSo >> b.MauSo;
}

int Gcd(int a, int b)//Ham uoc chung lon nhat
{
    if (b == 0)
        return a;
    return Gcd(b,a%b);
}

void Rut_Gon_Hai_Phan_So(PhanSo &a, PhanSo &b)
{
    int u1 = Gcd(abs(a.TuSo),abs(a.MauSo));
    int u2 = Gcd(abs(b.TuSo),abs(b.MauSo));
    a.TuSo /= u1;
    a.MauSo /= u1;
    b.TuSo /= u2;
    b.MauSo /= u2;
}

void Rut_Gon_Mot_Phan_So(PhanSo &x)
{
    int u = Gcd(abs(x.TuSo),abs(x.MauSo));
    x.TuSo /= u;
    x.MauSo /=u;
}

int So_Sanh(PhanSo a, PhanSo b)
{
    Rut_Gon_Hai_Phan_So(a,b);
    if (float(a.TuSo) / a.MauSo > float(b.TuSo) / b.MauSo)
        return 1;
    return 0;
}

void Xuat(PhanSo &x)
{
    Rut_Gon_Mot_Phan_So(x);
    if (x.MauSo < 0)
        {
            x.MauSo = -x.MauSo;
            x.TuSo = -x.TuSo;
        }
    if (x.MauSo == 1)
            cout << x.TuSo;
    else 
        cout << x.TuSo << "/" << x.MauSo;
}

void XuatPhanSo(PhanSo a, PhanSo b)
{
    cout << "\nPhan so lon nhat: ";
    if (So_Sanh(a,b) == 1)
        Xuat(a);
    else Xuat(b);
}

int main()
{
    PhanSo a,b;
    NhapA(a);
    NhapB(b);
    XuatPhanSo(a,b);
    return 0;
}