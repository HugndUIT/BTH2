#include <bits/stdc++.h>
using namespace std;

class ThoiGian
{
    private:
        int Gio, Phut, Giay;
    public:
        ThoiGian();
        ThoiGian(int h, int m, int s);
        void Nhap();
        void Xuat();
        void ChuanHoa();
        ThoiGian TangTG(ThoiGian x) ;
        ThoiGian GiamTG(ThoiGian x) ;
};

ThoiGian::ThoiGian() : Gio(0), Phut(0), Giay(0) {}

ThoiGian::ThoiGian(int h, int m, int s) : Gio(h), Phut(m), Giay(s) {
    ChuanHoa();
}

void ThoiGian::Nhap() {
    cout << "Nhap gio: ";
    cin >> Gio;
    cout << "Nhap phut: ";
    cin >> Phut;
    cout << "Nhap giay: ";
    cin >> Giay;
    ChuanHoa();
}

void ThoiGian::Xuat() {
    cout << Gio << ":" << Phut << ":" << Giay << endl;
}

void ThoiGian::ChuanHoa() {
    int TongGiay = Gio * 3600 + Phut * 60 + Giay;
    Gio = (TongGiay / 3600) % 24;
    Phut = (TongGiay / 60) % 60;
    Giay = TongGiay % 60;
}

ThoiGian ThoiGian::TangTG(ThoiGian x) {
    return ThoiGian(Gio + x.Gio, Phut + x.Phut, Giay + x.Giay);
}

ThoiGian ThoiGian::GiamTG(ThoiGian x) {
    int TongGiay = Gio * 3600 + Phut * 60 + Giay;
    int TongGiayX = x.Gio * 3600 + x.Phut * 60 + x.Giay;
    int KetQuaGiay = max(0, TongGiay - TongGiayX);
    return ThoiGian(KetQuaGiay / 3600, (KetQuaGiay / 60) % 60, KetQuaGiay % 60);
}

int main() 
{
    ThoiGian Time;
    cout << "Nhap thoi gian ban dau:\n";
    Time.Nhap();

    ThoiGian A;
    cout << "Nhap khoang thoi gian can tang:\n";
    A.Nhap();
    cout << "Thoi gian sau khi tang: ";
    Time.TangTG(A).Xuat();

    ThoiGian B;
    cout << "Nhap khoang thoi gian can giam:\n";
    B.Nhap();
    cout << "Thoi gian sau khi giam: ";
    Time.GiamTG(B).Xuat();
}