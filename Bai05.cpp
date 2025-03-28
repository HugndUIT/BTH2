#include <bits/stdc++.h>
using namespace std;

class ThoiGian {
    private:
        int Ngay, Thang, Nam;
        bool IsValidDate(int, int, int);
    public:
        ThoiGian();
        ThoiGian(int, int, int);
        void Nhap();
        void Xuat();
        void Change(ThoiGian);
        void ChuanHoa();
        int GetDay();
        int GetMonth();
        int GetYear();
        ThoiGian TangNgay(int);
        ThoiGian GiamNgay(int);
        bool IsLeapYear();
};

ThoiGian::ThoiGian() : Ngay(1), Thang(1), Nam(1900) {}

ThoiGian::ThoiGian(int Day, int Month, int Year) : Ngay(Day), Thang(Month), Nam(Year) {
    ChuanHoa();
}

void ThoiGian::Nhap() {
    cout << "Nhap ngay: ";
    cin >> Ngay;
    cout << "Nhap thang: ";
    cin >> Thang;
    cout << "Nhap nam: ";
    cin >> Nam;
}

void ThoiGian::Xuat() {
    cout << Ngay << "/" << Thang << "/" << Nam << endl;
}

void ThoiGian::Change(ThoiGian x) {
    Ngay = x.Ngay;
    Thang = x.Thang;
    Nam = x.Nam;
    ChuanHoa();
}

void ThoiGian::ChuanHoa() {
    vector<int> DaysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (IsLeapYear()) DaysInMonth[1] = 29;
    while (Ngay > DaysInMonth[Thang - 1]) {
        Ngay -= DaysInMonth[Thang - 1];
        Thang++;
        if (Thang > 12) {
            Thang = 1;
            Nam++;
        }
    }
    while (Ngay < 1) {
        Thang--;
        if (Thang < 1) {
            Thang = 12;
            Nam--;
        }
        Ngay += DaysInMonth[Thang - 1];
    }
}

bool ThoiGian::IsLeapYear() {
    return (Nam % 4 == 0 && Nam % 100 != 0) || (Nam % 400 == 0);
}

ThoiGian ThoiGian::TangNgay(int SoNgay) {
    Ngay += SoNgay;
    ChuanHoa();
    return *this;
}

ThoiGian ThoiGian::GiamNgay(int SoNgay) {
    Ngay -= SoNgay;
    ChuanHoa();
    return *this;
}

int ThoiGian::GetDay() { 
    return Ngay; 
}

int ThoiGian::GetMonth() { 
    return Thang; 
}

int ThoiGian::GetYear() { 
    return Nam; 
}

int main() {
    ThoiGian x, y;
    cout << "Nhap ngay thang nam cho doi tuong x:\n";
    x.Nhap();
    cout << "Nhap ngay thang nam cho doi tuong y:\n";
    y.Nhap();

    cout << "Ngay thang nam cua x: ";
    x.Xuat();
    cout << "Ngay thang nam cua y: ";
    y.Xuat();

    int ngay;
    cout << "Nhap so ngay muon tang: ";
    cin >> ngay;
    x.TangNgay(ngay).Xuat();
    y.TangNgay(ngay).Xuat();
    cout << "Nhap so ngay muon giam: ";
    cin >> ngay;
    x.GiamNgay(ngay).Xuat();
    y.GiamNgay(ngay).Xuat();

    cout << "Kiem tra x co nam nhuan: " << (x.IsLeapYear() ? "Co" : "Khong") << endl;
    cout << "Kiem tra y co nam nhuan: " << (x.IsLeapYear() ? "Co" : "Khong") << endl;
}