#include<bits/stdc++.h>
#include <chrono>
using namespace std;
#define int long long
const int INF = numeric_limits<int>::max();
const int nax = (int)(2005);
const int MAXN= (int)(1e6+5);
const int mod =1e9+2277;
const int BASE = (int)(301);
#define all(x) (x).begin(), (x).end()
#define size(x) ((int)x.size())
#define double long double
#define pii pair<int, int>
#define tup tuple<int, int, int>
#define iii pair<pii, int>
#define unsetbit(mask, x) ((mask)&=(~(1 << x)))
#define setbit(mask, x) ((mask)|=(1 << x))
#define reversebit(mask, x) ((mask) ^=(1 << n))
int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
const int d8x[8] = { -1, 1, 0, 0, -1, 1, 1, -1};
const int d8y[8] = {0, 0, 1, -1, 1, -1, 1, -1};
const int Trie_sz = 1e6;
#define get_bit(mask, x) ((mask)>>(x)&1)
const int LOG=19;

 
template<class X, class Y>
bool maximize(X& x, const Y y) {
    if (y > x) {x = y; return true;}
    return false;
}
 
template<class X, class Y>
bool minimize(X& x, const Y y) {
    if (y < x) {x = y; return true;}
    return false;
}
class PhanSo {
private:
    int tuso;
    int mauso;

public:
    // Constructor
    PhanSo(int t = 0, int m = 1) : tuso(t), mauso(m) {}

    // Copy Constructor
    PhanSo(const PhanSo &p) {
        tuso = p.tuso;
        mauso = p.mauso;
    }


    int LayTu() {
        return tuso;
    }


    int LayMau() {
        return mauso;
    }


    void GanTu(int t) {
        tuso = t;
    }

 
    void GanMau(int m) {
        mauso = m;
    }


    void Nhap() {
        cout << "Nhap tu so: ";
        cin >> tuso;
        do {
            cout << "Nhap mau so (khac 0): ";
            cin >> mauso;
        } while (mauso == 0);
    }


    void Xuat() {
        if (mauso == 1)
            cout << tuso;
        else
            cout << tuso << "/" << mauso;
    }

    // Toán t? l?n hon >
    bool operator>(PhanSo p) {
        return tuso * p.mauso > mauso * p.tuso;
    }

    // Toán t? c?ng +
    PhanSo operator+(PhanSo p) {
        int tuMoi = tuso * p.mauso + mauso * p.tuso;
        int mauMoi = mauso * p.mauso;
        return PhanSo(tuMoi, mauMoi);
    }

    // Toán t? tr? -
    PhanSo operator-(PhanSo p) {
        int tuMoi = tuso * p.mauso - mauso * p.tuso;
        int mauMoi = mauso * p.mauso;
        return PhanSo(tuMoi, mauMoi);
    }
};


class DSPhanSo {
private:
    PhanSo *ds;
    int n;

public:
    DSPhanSo(int soLuong) {
        n = soLuong;
        ds = new PhanSo[n];
    }


    void Nhap() {
        for (int i = 0; i < n; i++) {
            cout << "Nhap phan so thu " << i + 1 << ": " << '\n';
            ds[i].Nhap();
        }
    }

    PhanSo TimMax() {
        PhanSo max = ds[0];
        for (int i = 1; i < n; i++) {
            if (ds[i] > max) {
                max = ds[i];
            }
        }
        return max;
    }


    PhanSo TinhTong() {
        PhanSo tong = ds[0];
        for (int i = 1; i < n; i++) {
            tong = tong + ds[i];
        }
        return tong;
    }


    void Xuat() {
        for (int i = 0; i < n; i++) {
            ds[i].Xuat();
            cout << " ";
        }
        cout << '\n';
    }

    ~DSPhanSo() {
        delete[] ds;
    }
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
     //freopen("connect.inp", "r", stdin);
    // freopen("connect.out", "w", stdout);
     int soLuong;
    cout << "Nhap so luong phan so: ";
    cin >> soLuong;

    DSPhanSo ds(soLuong);
    ds.Nhap();

    cout << "Cac phan so da nhap: " << endl;
    ds.Xuat();

    PhanSo max = ds.TimMax();
    cout << "Phan so lon nhat: ";
    max.Xuat();
    cout << '\n';

    PhanSo tong = ds.TinhTong();
    cout << "Tong cac phan so: ";
    tong.Xuat();
    cout << '\n';

    
  
    exit(0);
}
    
   


