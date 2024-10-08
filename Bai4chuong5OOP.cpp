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

class MaTran {
private:
    int soDong, soCot;
    vector<vector<int>> data;

public:
    MaTran(int m = 0, int n = 0) : soDong(m), soCot(n) {
        data.resize(m, vector<int>(n, 0));
    }

    void taoNgauNhien(int m, int n) {
        soDong = m;
        soCot = n;
        data.resize(m, vector<int>(n));

        srand(time(0)); 
        for (int i = 0; i < soDong; ++i) {
            for (int j = 0; j < soCot; ++j) {
                data[i][j] = rand() % 1000000;
            }
        }
    }


    void nhap() {
        cout << "Nhap so dong: ";
        cin >> soDong;
        cout << "Nhap so cot: ";
        cin >> soCot;
        data.resize(soDong, vector<int>(soCot));

        for (int i = 0; i < soDong; ++i) {
            for (int j = 0; j < soCot; ++j) {
                cout << "Nhap phan tu [" << i << "][" << j << "]: ";
                cin >> data[i][j];
            }
        }
    }

    void xuat() const {
        for (int i = 0; i < soDong; ++i) {
            for (int j = 0; j < soCot; ++j) {
                cout << data[i][j] << " ";
            }
            cout << '\n';
        }
    }


   MaTran operator+(const MaTran &other) {
    if (soDong != other.soDong || soCot != other.soCot) {
        cout << "Loi: Hai ma tran phai co cung kich thuoc." << '\n';
        return MaTran();  
    }

    MaTran tong(soDong, soCot);
    for (int i = 0; i < soDong; ++i) {
        for (int j = 0; j < soCot; ++j) {
            tong.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return tong;
}

MaTran operator*(const MaTran &other) {
    if (soCot != other.soDong) {
        cout << "Loi: So cot cua ma tran A phai bang so dong cua ma tran B." << '\n';
        return MaTran();  
    }

    MaTran tich(soDong, other.soCot);
    for (int i = 0; i < soDong; ++i) {
        for (int j = 0; j < other.soCot; ++j) {
            tich.data[i][j] = 0;
            for (int k = 0; k < soCot; ++k) {
                tich.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return tich;
}
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
     //freopen("connect.inp", "r", stdin);
    // freopen("connect.out", "w", stdout);
     MaTran A, B;

    cout << "Nhap ma tran A:" << endl;
    A.nhap();

    cout << "Nhap ma tran B:" << endl;
    B.nhap();

    cout << "Tong cua ma tran A va B:" << endl;
    MaTran C = A + B;
    C.xuat();

    cout << "Tich cua ma tran A va B:" << endl;
    MaTran D = A * B;
    D.xuat();

    exit(0);
}
    
   


