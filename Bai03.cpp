#include <bits/stdc++.h>
using namespace std;

class SoPhuc 
{
    private:
        double Thuc, Ao;
    public:
        SoPhuc();
        SoPhuc(double thuc, double ao);
        void Nhap();
        void Xuat() ;
        SoPhuc Cong(SoPhuc x) ;
        SoPhuc Tru(SoPhuc x) ;
        SoPhuc Nhan(SoPhuc x) ;
        SoPhuc Chia(SoPhuc x) ;
};

SoPhuc::SoPhuc() : Thuc(0), Ao(0) {}

SoPhuc::SoPhuc(double thuc, double ao) : Thuc(thuc), Ao(ao) {}

void SoPhuc::Nhap() {
    cout << "Nhap phan thuc: ";
    cin >> Thuc;
    cout << "Nhap phan ao: ";
    cin >> Ao;
}

void SoPhuc::Xuat() {
    if (Ao == 0) 
        cout << Thuc << endl;
    else if (Ao > 0) 
        cout << Thuc << " + " << Ao << "i\n";
    else 
        cout << Thuc << " - " << fabs(Ao) << "i\n";
}

SoPhuc SoPhuc::Cong(SoPhuc x) {
    return SoPhuc(Thuc + x.Thuc, Ao + x.Ao);
}

SoPhuc SoPhuc::Tru(SoPhuc x) {
    return SoPhuc(Thuc - x.Thuc, Ao - x.Ao);
}

SoPhuc SoPhuc::Nhan(SoPhuc x) {
    return SoPhuc(Thuc * x.Thuc - Ao * x.Ao, Thuc * x.Ao + Ao * x.Thuc);
}

SoPhuc SoPhuc::Chia(SoPhuc x) {
    double MauSo = x.Thuc * x.Thuc + x.Ao * x.Ao;
    if (MauSo == 0) {
        throw runtime_error("Loi: Khong the chia cho so phuc bang 0.");
    }
    return SoPhuc((Thuc * x.Thuc + Ao * x.Ao) / MauSo, (Ao * x.Thuc - Thuc * x.Ao) / MauSo);
}

int main() 
{
    try {
        SoPhuc x, y;
        cout << "Nhap so phuc x:\n";
        x.Nhap();
        cout << "Nhap so phuc y:\n";
        y.Nhap();

        cout << "\nTong hai so phuc: ";
        x.Cong(y).Xuat();

        cout << "Hieu hai so phuc: ";
        x.Tru(y).Xuat();

        cout << "Tich hai so phuc: ";
        x.Nhan(y).Xuat();

        cout << "Thuong hai so phuc: ";
        x.Chia(y).Xuat();
    } catch (runtime_error &e) {
        cout << e.what() << endl;
    }
}