#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b) {
    if (b == 0) return abs(a);
    return GCD(b, a % b);
}

class cPhanSo 
{
    private:
        int TuSo, MauSo;
        void RutGon();
    public:
        cPhanSo();
        cPhanSo(int Tu, int Mau);
        cPhanSo Cong(cPhanSo x);
        cPhanSo Tru(cPhanSo x);
        cPhanSo Nhan(cPhanSo x);
        cPhanSo Chia(cPhanSo x);
        void Nhap();
        void Xuat();
};

cPhanSo::cPhanSo() : TuSo(0), MauSo(1) {}

cPhanSo::cPhanSo(int Tu, int Mau) : TuSo(Tu), MauSo(Mau) {
    RutGon();
}

void cPhanSo::RutGon() {
    int gcd = GCD(TuSo, MauSo);
    TuSo /= gcd;
    MauSo /= gcd;
    if (MauSo < 0) {
        TuSo = -TuSo;
        MauSo = -MauSo;
    }
}

cPhanSo cPhanSo::Cong(cPhanSo x) {
    cPhanSo kq(x.TuSo * MauSo + x.MauSo * TuSo, x.MauSo * MauSo);
    kq.RutGon();
    return kq;
}

cPhanSo cPhanSo::Tru(cPhanSo x) {
    cPhanSo kq(TuSo * x.MauSo - MauSo * x.TuSo, x.MauSo * MauSo);
    kq.RutGon();
    return kq;
}

cPhanSo cPhanSo::Nhan(cPhanSo x) {
    cPhanSo kq(x.TuSo * TuSo, x.MauSo * MauSo);
    kq.RutGon();
    return kq;
}

cPhanSo cPhanSo::Chia(cPhanSo x) {
    if (x.TuSo == 0) {
        cout << "Loi: Khong the chia cho ";
        return cPhanSo(0, 1);
    }
    cPhanSo kq(TuSo * x.MauSo, MauSo * x.TuSo);
    kq.RutGon();
    return kq;
}

void cPhanSo::Nhap() {
    cout << "Nhap tu so: ";
    cin >> TuSo;
    do {
        cout << "Nhap mau so (khac 0): ";
        cin >> MauSo;
        if (MauSo == 0) {
            cout << "Loi: Mau so phai khac 0!\n";
        }
    } while (MauSo == 0);
    RutGon();
}

void cPhanSo::Xuat() {
    if (TuSo == 0) {
        cout << 0 << endl;
    } else if (MauSo == 1) {
        cout << TuSo << endl;
    } else {
        cout << TuSo << " / " << MauSo << endl;
    }
}

int main()
{
    cPhanSo x, y;
    cout << "Nhap phan so thu nhat:\n";
    x.Nhap();
    cout << "Nhap phan so thu hai:\n";
    y.Nhap();

    cout << "Tong: ";
    x.Cong(y).Xuat();
    
    cout << "Hieu: ";
    x.Tru(y).Xuat();
    
    cout << "Tich: ";
    x.Nhan(y).Xuat();

    cout << "Thuong: ";
    x.Chia(y).Xuat();
}