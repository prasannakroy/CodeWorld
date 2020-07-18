/****************************************
  "Temp not a desperate man."
                    -William Shakespeare
 ****************************************/

/*****************************
 PRASANNA_K_ROY (prasanna2425)
 *****************************/

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

int SakamotoAlgo(int y, int m, int d) { 
    int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };  
    if (m < 3) 
        y -= 1; 
    return ((y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7); 
} 

bool checkLeap(int y) {
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    if (y % 4 == 0) return true;
    return false;
}

int solve() {
    int m1, y1, m2, y2, res(0), aux1, aux2, res1(0), res2(0);
    accio >> m1 >> y1 >> m2 >> y2;
    aux1 = (y1 - 1) / 400;
    if (aux1 != 0) {
        res1 += (aux1 * 100) + aux1;
    }
    for (int i = (aux1 * 400) + 1; i < y1; i++) {
        if (i <= 0) {
            continue;
        }
        if (SakamotoAlgo(i, 2, 1) == 6 or (SakamotoAlgo(i, 2, 1) == 0 and !(checkLeap(i)))) {
            res1++;
        }
    }
    aux2 = y2 / 400;
    if (aux2 != 0) {
        res2 += (aux2 * 100) + aux2;
    }
    for (int i = (aux2 * 400) + 1; i <= y2; i++) {
        if (i <= 0) {
            continue;
        }
        if (SakamotoAlgo(i, 2, 1) == 6 or (SakamotoAlgo(i, 2, 1) == 0 and !(checkLeap(i)))) {
            res2++;
        }
    }
    if (y1 == y2) {
        if (m1 > 2 or m2 < 2) {
            if (SakamotoAlgo(y1, 2, 1) == 6 or (SakamotoAlgo(y1, 2, 1) == 0 and !(checkLeap(y1)))) {
                res2--;
            }
        }
    }
    else {
        if (m1 > 2) {
            if (SakamotoAlgo(y1, 2, 1) == 6 or (SakamotoAlgo(y1, 2, 1) == 0 and !(checkLeap(y1)))) {
                res2--;
            }
        }
        if (m2 < 2) {
            if (SakamotoAlgo(y2, 2, 1) == 6 or (SakamotoAlgo(y2, 2, 1) == 0 and !(checkLeap(y2)))) {
                res2--;
            }
        }
    }
    cout << res2 - res1 << endl;
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