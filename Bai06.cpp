#include <bits/stdc++.h>
using namespace std;

class Chuoi 
{
    private:
        vector<char> kyTu;
    public:
        void nhap();
        int layDoDai();
        void daoNguoc();
        void inHoa();
        void inThuong();
        void xuat();
};

void Chuoi::nhap() {
    string temp;
    cout << "Nhap chuoi: ";
    getline(cin, temp);
    kyTu.assign(temp.begin(), temp.end());
}

int Chuoi::layDoDai() {
    return kyTu.size();
}

void Chuoi::daoNguoc() {
    reverse(kyTu.begin(), kyTu.end());
}

void Chuoi::inHoa() {
    for (char& c : kyTu) {
        c = toupper(c);
    }
}

void Chuoi::inThuong() {
    for (char& c : kyTu) {
        c = tolower(c);
    }
}

void Chuoi::xuat() {
    for (char c : kyTu) {
        cout << c;
    }
    cout << endl;
}

int main() 
{
    Chuoi chuoi;

    chuoi.nhap();
    cout << "\nChuoi da nhap:\n";
    chuoi.xuat();

    cout << "\nDo dai chuoi: " << chuoi.layDoDai() << endl;

    chuoi.inHoa();
    cout << "\nSau khi in hoa:\n";
    chuoi.xuat();

    chuoi.inThuong();
    cout << "\nSau khi in thuong:\n";
    chuoi.xuat();

    chuoi.daoNguoc();
    cout << "\nSau khi dao nguoc:\n";
    chuoi.xuat();
}