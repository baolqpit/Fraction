#include <iostream>
#include <math.h>
using namespace std;

struct PhanSo
{
    int iTuSo;
    int iMauSo;
};

void Nhap(PhanSo &a)
{
    cout << "Nhap vao phan so: ";
    cin >> a.iTuSo >> a.iMauSo;
}

int Gcd(int a, int b)
{
    if (b == 0)
        return a;
    return Gcd(b,a%b);
}

void Rut_Gon(PhanSo &a)
{
    int u = Gcd(abs(a.iTuSo),abs(a.iMauSo));
    a.iTuSo /= u;
    a.iMauSo /= u;
}

void Xuat(PhanSo a)
{
    if (a.iMauSo == 0)
     cout << "\nKhong the thuc hien duoc";
    else
    {
        cout << "\nPhan so vua nhap: ";
        Rut_Gon(a);
        if (a.iMauSo < 0)
        {
            a.iMauSo = -a.iMauSo;
            a.iTuSo = -a.iTuSo;
        }
        if (a.iMauSo == 1)
            cout << a.iTuSo;
        else 
            cout << a.iTuSo << "/" << a.iMauSo;
    }
}

int main()
{
    PhanSo a;
    Nhap(a);
    Xuat(a);
    return 0;
}