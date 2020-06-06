/*
  "Temp not a desperate man."
                    -William Shakespeare
*/

#include <bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define accio cin
#define pb push_back
#define endl "\n"
#define i_64 long long
#define d_64 long double
#define u_64 unsigned long long

const i_64 mod = (int)1e9 + 7;
const i_64 MAX = 1000001;
bool prime[MAX] = {true};

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
            v.push_back(n);
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
                b.v.push_back(rem  % 10);
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
                b.v.push_back(rem  % 10);
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
        b.v.push_back(n);
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

i_64 nCr(i_64 n, i_64 r) { 
    i_64 C[r + 1]; 
    memset (C, 0, sizeof(C)); 
    C[0] = 1;
    for (i_64 i = 1; i <= n; i++) 
        for (i_64 j = min(i, r); j > 0; j--) {
            C[j] = (C[j] + C[j - 1]) % mod; 
        }
    return C[r]; 
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

int solve() {
    i_64 n;
    accio >> n;
    string s1, s2;
    accio >> s1 >> s2;
    i_64 s10(0), s11(0), s20(0), s21(0);
    for (i_64 i = 0; i < n; i++) {
        s1[i] == '0' ? s10++ : s11++;
        s2[i] == '0' ? s20++ : s21++;
    }
    //cout << s10 << "<<" << s11 << "<<" << s20 << "<<" << s21 << endl;
    i_64 Max1, Min1, Max0, Min0;
    Max1 = abs((s11 + s21) - n);
    //cout << Max1 << ">>>" << endl;
    Max1 = n - Max1;
    Min1 = abs(s11 - s21);
    Max0 = n - Min1;
    Min0 = n - Max1;
    //cout << Min1 << " : " << Max1 << " : " << Min0 << " : " << Max0 << endl;
    vector<i_64> v(Max1 + 1);
    i_64 c(1);
    v[0] = c;
    for(i_64 j = 1; j <= Max1; j++){
        i_64 l = Imod(j);
        //cout << l << " ";
        v[j] = (((c * (n - j + 1)) % mod )* l) % mod;
        c = v[j];
    }
    //cout << endl;
    //cout << power(1000, 100) << endl;
    i_64 res(0);
    for (i_64 i = Min1; i <= Max1; i += 2) {
        i_64 x = v[i];
        res = (res % mod + x % mod) % mod;
        //cout << res << " ";
    }
    cout << res << endl;
    return 0; 
}

int main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs
    #endif

    __AcHiLlEs

    int t(1);
    accio >> t;
    while (t--) {
        solve();
    }
    return 0;
}

