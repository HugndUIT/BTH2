#include <bits/stdc++.h>
using namespace std;

class Vehicle {
private:
    string ChuXe, LoaiXe;
    double TriGia;
    int DungTich;
public:
    Vehicle(string cx, string lx, double tg, int dt);
    Vehicle();
    void Nhap();
    double TinhThue();
    void Xuat();
};

Vehicle::Vehicle(string cx, string lx, double tg, int dt) {
    if (tg < 0 || dt < 0) throw invalid_argument("Tri gia va dung tich phai >= 0!");
    ChuXe = cx;
    LoaiXe = lx;
    TriGia = tg;
    DungTich = dt;
}

Vehicle::Vehicle() {
    ChuXe = LoaiXe = "";
    TriGia = DungTich = 0;
}

void Vehicle::Nhap() {
    cout << "Nhap ten chu xe: "; getline(cin, ChuXe);
    cout << "Nhap loai xe: "; getline(cin, LoaiXe);
    do {
        cout << "Nhap tri gia xe: "; cin >> TriGia;
        cout << "Nhap dung tich xylanh: "; cin >> DungTich;
        if (TriGia < 0 || DungTich < 0) cout << "Gia tri khong hop le! Nhap lai.\n";
    } while (TriGia < 0 || DungTich < 0);
}

double Vehicle::TinhThue() {
    if (DungTich < 100) return TriGia * 0.01;
    if (DungTich <= 200) return TriGia * 0.03;
    return TriGia * 0.05;
}

void Vehicle::Xuat() {
    cout << ChuXe << " " << LoaiXe << " " << TriGia << " " << DungTich << " " << TinhThue() << endl;
}

int main() {
    Vehicle xe1("Nguyen Van A", "Xe may", 30000, 150);
    Vehicle xe2("Tran Thi B", "O to", 500000, 250);
    Vehicle xe3;
    xe3.Nhap();
    xe1.Xuat();
    xe2.Xuat();
    xe3.Xuat();
}