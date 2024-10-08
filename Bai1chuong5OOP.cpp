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
class Complex {
private:
    double real; 
    double imag; 

public:
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    friend Complex operator + (const Complex& a, const Complex& b) {
        return Complex(a.real + b.real, a.imag + b.imag);
    }

    friend Complex operator - (const Complex& a, const Complex& b) {
        return Complex(a.real - b.real, a.imag - b.imag);
    }


    friend Complex operator * (const Complex& a, const Complex& b) {
        return Complex(a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real);
    }


    friend Complex operator / (const Complex& a, const Complex& b) {
        double mau= b.real * b.real + b.imag * b.imag;
        return Complex((a.real * b.real + a.imag * b.imag) / mau, 
                       (a.imag * b.real - a.real * b.imag) / mau);
    }


    friend bool operator == (const Complex& a, const Complex& b) {
        return (a.real == b.real) && (a.imag == b.imag);
    }


    friend ostream& operator << (ostream& out, const Complex& c) {
        out << c.real << (c.imag >= 0 ? " + " : " - ") << abs(c.imag) << "i";
        return out;
    }

    friend istream& operator >> (istream& in, Complex& c) {
        in >> c.real >> c.imag;
        return in;
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
     //freopen("connect.inp", "r", stdin);
    // freopen("connect.out", "w", stdout);
    Complex A(1, 2), B(3, 4);
    
    cout << "A + B = " << A + B << '\n';
    cout << "A - B = " << A - B << '\n';
    cout << "A * B = " << A * B << '\n';
    cout << "A / B = " << A / B << '\n';

    Complex C;
    cout << "nhap so phuc C: ";
    cin >> C;
    cout << "C = " << C << '\n';
    (A==B)?cout<<"A bang B": cout<<"A khong bang B";
    cout<<'\n';
    exit(0);
}
    
   


