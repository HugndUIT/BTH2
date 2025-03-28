#include <bits/stdc++.h>
using namespace std;

class Diem 
{
    private:
        double HoanhDo, TungDo;
    public:
        Diem();
        Diem(double HD, double TD);
        double getHoanhDo() ;
        double getTungDo() ;
        void setHoanhDo(double HD);
        void setTungDo(double TD);
        void Nhap();
        void Xuat() ;
        Diem TinhTien( Diem x) ;
};

Diem::Diem() : HoanhDo(0), TungDo(0) {}

Diem::Diem(double HD, double TD) : HoanhDo(HD), TungDo(TD) {}

double Diem::getHoanhDo() {
    return HoanhDo;
}

double Diem::getTungDo() {
    return TungDo;
}

void Diem::setHoanhDo(double HD) {
    HoanhDo = HD;
}

void Diem::setTungDo(double TD) {
    TungDo = TD;
}

void Diem::Nhap() {
    cout << "Nhap hoanh do: ";
    cin >> HoanhDo;
    cout << "Nhap tung do: ";
    cin >> TungDo;
}

void Diem::Xuat() {
    cout << "(" << HoanhDo << ", " << TungDo << ")\n";
}

Diem Diem::TinhTien(Diem x) { 
    return Diem(HoanhDo + x.HoanhDo, TungDo + x.TungDo);
}

int main() 
{
    Diem a;
    cout << "Nhap diem a:\n";
    a.Nhap();
    cout << "Toa do diem a: ";
    a.Xuat();

    cout << "Hoanh do cua a: " << a.getHoanhDo() << endl;
    cout << "Tung do cua a: " << a.getTungDo() << endl;

    Diem b;
    cout << "\nNhap diem b:\n";
    b.Nhap();
    cout << "Toa do diem b: ";
    b.Xuat();

    Diem c = a.TinhTien(b);
    cout << "\nToa do diem c sau khi tinh tien: ";
    c.Xuat();
}