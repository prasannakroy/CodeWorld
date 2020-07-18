/****************************************
  "Temp not a desperate man."
                    -William Shakespeare
 ****************************************/

/*****************************
 PRASANNA_K_ROY (prasanna2425)
 *****************************/

#include <bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);
#define accio cin
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
#define i_64 long long
#define d_64 long double
#define u_64 unsigned long long

const int mod = (int)1e9 + 7;
const i_64 MAX = 1000001;


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

i_64 isPerfectSquare(i_64 num) {
    if (num < 1) { 
        return false;
    }
    if (num == 1) {
        return true;
    }
    i_64 t = num / 2;
    while (t * t > num) {
        t = (t + num / t) / 2;
    }
    return t * t == num; 
}

int solve() {
    i_64 n, countl(0), countr(0), res(0);
    accio >> n;
    string s;
    accio >> s;
    for (int i = 0; i < n; i++) {
        countl = 0;
        countr = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == '(') {
                countl++;
            }
            else if (s[j] == ')') {
                countr++;
            }
            if (countr - countl > 0) {
                res += n - j;
                countr--;
                countl++;
            }
        }
    }
    i_64 t = (n * (n + 1)) / 2;
    cout << ((res % mod) * (Imod(t))) % mod << endl;
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