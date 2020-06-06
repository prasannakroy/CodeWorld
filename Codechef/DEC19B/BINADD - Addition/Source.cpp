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

const int mod = (int)1e9 + 7;
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

int nCr(int n, int r) { 
    int C[r + 1]; 
    memset (C, 0, sizeof(C)); 
    C[0] = 1;
    for (int i = 1; i <= n; i++) 
        for (int j = min(i, r); j > 0; j--) 
            C[j] = (C[j] + C[j - 1]) % mod; 
    return C[r]; 
}

int solve() {
    string a, b;
    accio >> a >> b;
    int l1 = a.length();
    int l2 = b.length();
    int x = abs(l1 - l2);
    string aux = "";
    for (int i = 0; i < x; i++)
        aux += "0";
    if (l1 < l2)
        a = aux + a;
    else
        b = aux + b;
    a = "0" + a;
    b = "0" + b;
    int l = a.length();
    //cout << a << " " << b << endl;
    int count(0), flag(0), max(0), flag2(0), carry(0);
    for (int i = l - 1; i >= 0; i--) {
        if (b[i] == '1')
            flag = 1;
        if (a[i] == '1')
            flag2 = 1;
        int n = (a[i] - '0') + (b[i] - '0') + carry;
        if (n == 2) {
            count++;
            carry = 1;
        }
        else if (n == 3) {
            count++;
            if (count > max)
                max = count;
            count = 1;
            carry = 1;
        }
        else if (n == 1 && count != 0) {
            count++;
            if (count > max)
                max = count;
            count = 0;
            carry = 0;
        }
        else {
            carry = 0;
            continue;
        }
    }
    if (count > max)
        max = count;
    if (flag == 0)
        cout << 0 << endl;
    else if (flag2 == 0)
        cout << 1 << endl;
    else if (max == 0)
        cout << 1 << endl;
    else 
        cout << max << endl;
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

