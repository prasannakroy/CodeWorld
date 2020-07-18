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
#define pb push_back
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

void solve() {
    i_64 n, res(0), end, ptr, flag(0), c(0);
    cin >> n;
    i_64 a[n];
    for (i_64 &i : a) cin >> i; 
    end = ptr = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] & 1) {
            c++;
        }
        else {
            res += (c * (c + 1)) >> 1;
            c = 0;
            if (a[i] % 4 == 0) {
                i_64 total = end - i;
                i_64 sub = i;
                res += (total + 1) * (sub + 1);
                end = i - 1;
                flag = 0;
            }
            else {
                if (!flag) {
                    ptr = i;
                    flag = 1;
                }
                else {
                    i_64 total = end - ptr;
                    i_64 sub = i;
                    res += (total + 1) * (sub + 1);
                    end = ptr - 1;
                    ptr = i;
                }
            }
        }
    }
    res += ((c * (c + 1)) >> 1);
    cout << res << "\n";
}

int main() {
    //auto start=std::chrono::steady_clock::now();
    /*#ifndef ONLINE_JUDGE 
        __AnAkLuSmOs
    #endif*/

    __AcHiLlEs

    int t(1);
    cin >> t;
    while (t--) {
        solve();
    }
    
    /*auto end = std::chrono::steady_clock::now();
        double elapsed=double (std::chrono::duration_cast < std::chrono::nanoseconds> (end-start).count());
    std::cout << endl << "Terminated\n"<< elapsed/1e9;*/
    return 0;
}