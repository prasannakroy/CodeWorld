/*
  "Temp not a desperate man."
                    -William Shakespeare
*/

#include <bits/stdc++.h>
#include <chrono>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);
#define accio cin
#define pb push_back
#define endl "\n"
#define i_64 long long
#define d_64 long double
#define u_64 unsigned long long

const int mod = (int)1e9 + 7;
const i_64 MAX = 1000001;

class BigInt {
private:
    string s;
    vector <int> v;
public:
    BigInt(){s = "";}
    BigInt(string x) {
        int l = x.length();
        for (int i = l - 1; i >= 0; i--) {
            int n = int(x[i] - '0');
            v.pb(n);
        }
    } 
    BigInt operator + (BigInt b) {
        int n1 = v.size();
        int n2 = b.v.size();
        int rem(0), i;
        if (n1 < n2) {
            for (i = 0; i < n1; i++) {
                int res = v[i] + b.v[i] + rem;
                b.v[i] = res % 10;
                rem = res / 10;
            }
            for (int j = i; j < n2; j++) {
                int res = b.v[i] + rem;
                b.v[i] = res % 10;
                rem = res / 10;
            }
            while (rem) {
                b.v.pb(rem  % 10);
                rem /= 10;
            }
        }
        else {
            for (i = 0; i < n2; i++) {
                int res = v[i] + b.v[i] + rem;
                b.v[i] = res % 10;
                rem = res / 10;
            }
            for (int j = i; j < n1; j++) {
                int res = v[i] + rem;
                b.v[i] = res % 10;
                rem = res / 10;
            }
            while (rem) {
                b.v.pb(rem  % 10);
                rem /= 10;
            }
        }
        return b;
    }
    friend ostream & operator << (ostream &output, const BigInt &a);
    friend istream & operator >> (istream &input, BigInt &b);
};

istream & operator >> (istream &input, BigInt &b) {
    input >> b.s;
    int l = b.s.length();
    for (int i = l - 1; i >= 0; i--) {
        int n = int(b.s[i] - '0');
        b.v.pb(n);
    }
    return input;
}

ostream & operator << (ostream &output, const BigInt &a) {
    int x = a.v.size();
    for (int i = x - 1; i >= 0; i--) {
        output << a.v[i];
    }
    return output;
}

bool primeCheck(i_64 n) {
    if (n == 2 || n == 3 || n == 5) return true;
    if (n % 2 == 0 || n % 3 == 0) return false; 
  
    for (i_64 i = 5; i * i <= n; i += 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
           return false; 
    return true; 
}

i_64 power(i_64 x, i_64 y) { 
    if (y == 0) 
        return 1; 
    i_64 p = power(x, y / 2) % mod; 
    p = (p * p) % mod; 
    if (!(y & 1)) 
        return p;
    return (p * x) % mod; 
} 

i_64 Imod(i_64 a) { 
    i_64 res = (power(a, mod - 2)) % mod;
    return res;
}

i_64 nCr(i_64 n, i_64 r) { 
    vector<i_64> v(r + 1);
    i_64 c(1);
    v[0] = c;
    for(i_64 j = 1; j <= r; j++){
        i_64 l = Imod(j);
        v[j] = (((c * (n - j + 1)) % mod )* l) % mod;
        c = v[j];
    }
    return v[r]; 
}

i_64 pwr(i_64 x, int n) {
    i_64 P;    
    while ((n & 1) == 0) {      
        x = x * x;      
        n >>= 1;    
    }    
    P = x;    
    n >>= 1;    
    while (n > 0) {      
        x = x * x;      
        if ((n & 1) != 0)        
            P = P * x;      
        n >>= 1;    
    }    
    return P;  
}

int solve() {
    int n;
    accio >> n;
    if(n == 1) {
        cout << "Hooray" << endl << 1 << endl;
        return 0;
    }
    if (n & 1) {
        cout << "Boo" << endl;
        return 0;
    }
    cout << "Hooray" << endl;
    int res[n][n];
    memset(res, 0, sizeof res);
    int m[n][(2 * n) - 1];
    memset(m, 0, sizeof m);
    int x;
    for (int i = 0; i < (n / 2); i++) {
        for (int j = i; j < n - i; j++) {
            x = 0;
            if (i == j) {
                res[i][j] = n, m[i][n - 1] = 1;
                res[n - 1 - i][n - 1 - i] = n;
                m[n - 1 - i][n - 1] = 1;
            }
            else {
                if (i == 0) {
                    x = res[i][j - 1] + 1;
                    res[i][j] = x;
                    m[i][x - 1] = 1;
                    m[j][x - 1] = 1;
                    x = j;
                    res[j][i] = x;
                    m[i][x - 1] = 1;
                    m[j][x - 1] = 1;
                }
                else {
                    x = res[i - 1][j] + 1;
                    res[i][j] = x;
                    m[i][x - 1] = 1;
                    m[j][x - 1] = 1;
                    x = res[j][i - 1] + 1;
                    res[j][i] = x;
                    m[i][x - 1] = 1;
                    m[j][x - 1] = 1;
                }
            }
        }
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = n - 1; j < 2 * n - 2; j++) {
            if (m[i][j] == 1)
                continue;
            if (i < n / 2) {
                for (int k = n - i; k < n; k++) {
                    if (m[k][j] == 1)
                        continue;
                    if (res[i][k] != 0)
                        continue;
                    res[i][k] = j + 1;
                    m[i][j] = 1;
                    m[k][j] = 1;
                    int r = res[i][k] - n;
                    res[k][i] = r;
                    m[i][r - 1] = 1;
                    m[k][r - 1] = 1;
                    break;
                }
            }
            else {
                for (int k = i + 1; k < n; k++) {
                    if (m[k][j] == 1)
                        continue;
                    if (res[i][k] != 0)
                        continue;
                    res[i][k] = j + 1;
                    m[i][j] = 1;
                    m[k][j] = 1;
                    int r = res[i][k] - n;
                    res[k][i] = r;
                    m[i][r - 1] = 1;
                    m[k][r - 1] = 1;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

int main() {
    //auto start=std::chrono::steady_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs
    #endif

    __AcHiLlEs

    int t(1);
    accio >> t;
    while (t--) {
        solve();
    }
    
    /*auto end = std::chrono::steady_clock::now();
        double elapsed=double (std::chrono::duration_cast < std::chrono::nanoseconds> (end-start).count());
    std::cout << endl << "Terminated\n"<< elapsed/1e9;*/
    return 0;
}