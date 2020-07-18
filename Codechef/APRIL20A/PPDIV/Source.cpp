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

const i_64 mod = (i_64)1e9 + 7;
const i_64 MAX = (i_64)1e12;

vector<i_64> ppdiv;

void solve() {
    i_64 n, res(0), a;
    cin >> n; 
    i_64 i = 0;
    while (ppdiv[i] <= n and i < ppdiv.size()) {
        (res += ((n / ppdiv[i]) * ppdiv[i]) % mod) %= mod;
        i++;
    }
    cout << res << "\n";
    return;
}

int main() {
    //auto start=std::chrono::steady_clock::now();
    /*#ifndef ONLINE_JUDGE 
        __AnAkLuSmOs
    #endif*/

    __AcHiLlEs
    
    i_64 i = 2;
    ppdiv.push_back(1);
    while (i <= MAX / i) {
        i_64 x = i;
        while (x * i <= MAX) {
            x *= i;
            ppdiv.push_back(x);
        }
        i++;
    }
    sort(ppdiv.begin(), ppdiv.end());
    vector<i_64>::iterator it; 
    it = std::unique(ppdiv.begin(), ppdiv.end());  
    ppdiv.resize(std::distance(ppdiv.begin(), it));
    
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