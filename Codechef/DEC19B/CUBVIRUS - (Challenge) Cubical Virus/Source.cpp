/*
  "Temp not a desperate man."
                    -William Shakespeare
*/

#include <bits/stdc++.h>
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
        v[j] = (((c * (n - j + 1)) % mod) * l) % mod;
        c = v[j];
    }
    return v[r]; 
}

int solve() {
    int n;
    accio >> n;
    std::vector<string> v;
    for (int i = 0; i < n * n; i++) {
        string s;
        accio >> s;
        v.pb(s);
    }
    int a[n][n][n];
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                string s = v[k * n + j];
                a[i][j][k] = s[i] - '0';
            }
        }
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cout << a[i][j][k];
            }
            cout << endl;
        }
    }*/

    int min(n + 1), x, y, z;
    vector<int> p, q, r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum(0);
            for (int k = 0; k < n; k++) {
                sum += a[i][j][k];
            }
            if (sum < min) {
                min = sum;
                x = i;
                y = j;
            }
        }
    }
    p.pb(x + 1);
    q.pb(y + 1);
    min = n + 1;
    for (int k = 0; k < n; k++) {
        int sum(0);
        if (a[x][y][k] == 1)
            continue;
        for (int j = 0; j < n; j++) {
            sum += a[x][j][k];
        }
        if (sum < min) {
            min = sum;
            z = k;
        }
    }
    r.pb(z + 1);
    for (int k = 0; k < n; k++) {
        if (k == z)
            continue;
        if (a[x][y][k] == 0) 
            r.pb(k + 1);
    }
    for (int k = 0; k < n; k++) {
        if (k == z)
            continue;
        if (a[x][y][k] == 1) {
            r.pb(k + 1);
        }
    }

    for (int j = 0; j < n; j++) {
        if (j == y)
            continue;
        if (a[x][j][z] == 0) 
            q.pb(j + 1);
    }
    for (int j = 0; j < n; j++) {
        if (j == y)
            continue;
        if (a[x][j][z] == 1) {
            q.pb(j + 1);
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == x)
            continue;
        if (a[i][y][z] == 0) 
            p.pb(i + 1);
    }
    for (int i = 0; i < n; i++) {
        if (i == x)
            continue;
        if (a[i][y][z] == 1) 
            p.pb(i + 1);
    }
    /*for (int i = 1; i <= n; i++) {
        if (i == y + 1)
            continue;
        q.pb(i);
    }*/
    for (int i = 0; i < n; i++) 
        cout << p[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) 
        cout << q[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) 
        cout << r[i] << " ";
    return 0; 
}

int main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs
    #endif

    __AcHiLlEs

    int t(1);
    //accio >> t;
    while (t--) 
        solve();
    return 0;
}
