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

class DaThuc {
private:
    int bac; 
    vector<double> heso;
public: 
    DaThuc() {
        bac = 0;
        heso.push_back(0);
    }

    DaThuc(int n) {
        bac = n;
        heso.resize(bac + 1, 0); 
    }

    double tinhGiaTri(double x) const {
        double ketqua = 0;
        for (int i = 0; i <= bac; i++) {
            ketqua += heso[i] * pow(x, bac - i); 
        }
        return ketqua;
    }
    
    friend istream& operator>>(istream &is, DaThuc &dathuc) {
        cout << "Nhap bac cua da thuc: ";
        is >> dathuc.bac;
        dathuc.heso.resize(dathuc.bac + 1);
        for (int i = 0; i <= dathuc.bac; i++) {
            cout << "He so bac " << dathuc.bac - i << ": ";
            is >> dathuc.heso[i];
        }
        return is;
    }
 
    friend ostream& operator<<(ostream &os, const DaThuc &dathuc) {
        for (int i = 0; i <= dathuc.bac; i++) {
            if (i > 0 && dathuc.heso[i] >= 0) os << "+";
            os << dathuc.heso[i];
            if (dathuc.bac - i > 0) os << "x^" << dathuc.bac - i;
            os << " ";
        }
        return os;
    }

     friend DaThuc operator+(const DaThuc &dathuc1, const DaThuc &dathuc2) {
        int maxBac = max(dathuc1.bac, dathuc2.bac);
        DaThuc tong(maxBac);

        for (int i = 0; i <= maxBac; i++) {
            double heso1 = (i <= dathuc1.bac) ? dathuc1.heso[dathuc1.bac - i] : 0;
            double heso2 = (i <= dathuc2.bac) ? dathuc2.heso[dathuc2.bac - i] : 0;
            tong.heso[maxBac - i] = heso1 + heso2;
        }
        return tong;
    }

    friend DaThuc operator-(const DaThuc &dathuc1, const DaThuc &dathuc2) {
        int maxBac = max(dathuc1.bac, dathuc2.bac);
        DaThuc hieu(maxBac);

        for (int i = 0; i <= maxBac; i++) {
            double heso1 = (i <= dathuc1.bac) ? dathuc1.heso[dathuc1.bac - i] : 0;
            double heso2 = (i <= dathuc2.bac) ? dathuc2.heso[dathuc2.bac - i] : 0;
            hieu.heso[maxBac - i] = heso1 - heso2;
        }
        return hieu;
    }
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
     //freopen("connect.inp", "r", stdin);
    // freopen("connect.out", "w", stdout);
    DaThuc P, Q;
    cout << "Nhap da thuc P:" << '\n';
    cin >> P;
    cout << "Nhap da thuc Q:" << '\n';
    cin >> Q;
    cout << "Da thuc P: " << P << '\n';
    cout << "Da thuc Q: " << Q << '\n';

    DaThuc tong = P + Q;
    DaThuc hieu = P - Q;

    cout << "Tong P + Q: " << tong << '\n';
    cout << "Hieu P - Q: " << hieu << '\n';

    double x;
    cout << "Nhap gia tri x de tinh P(x): ";
    cin >> x;
    cout << "P(" << x << ") = " << P.tinhGiaTri(x) << '\n';

    exit(0);
}
    
   


