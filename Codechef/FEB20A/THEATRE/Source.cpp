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

int bigRes(0);

int solve() {
    int n, mx(-INT_MAX);
    accio >> n;
    if (n == 0) {
        i_64 res = -400;
        bigRes += res;
        cout << res << endl;
        return 0;
    }
    i_64 idx[4][4];
    memset(idx, 0, sizeof idx);
    for (int i = 0; i < n; ++i) {
        char m_name;
        int m_time;
        accio >> m_name >> m_time;
        int x = int(m_name - 'A');
        m_time /= 3;
        m_time--;
        idx[x][m_time]++;
    }
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            if (i == j) {
                continue;
            }
            for(int k = 0; k < 4; ++k) {
                if (i == k or j == k) {
                    continue;
                }
                for(int l = 0; l < 4; ++l) {
                    if(i == l or j == l or k == l) {
                        continue;
                    }
                    int plan[4];
                    plan[0] = idx[i][0];
                    plan[1] = idx[j][1];
                    plan[2] = idx[k][2];
                    plan[3] = idx[l][3];
                    sort(plan, plan + 4);
                    int res(0), cost(100);
                    for(int m = 3; m >= 0; --m) {
                        if(plan[m] == 0) {
                            res -= ((m + 1) * 100);
                            break;
                        }
                        else {
                            res += (plan[m] * cost);
                            cost -= 25;
                        }
                    }
                    mx = max(res, mx);
                }
            }
        }
    }
    bigRes += mx;
    cout << mx << endl;
    return 0;
}

int main() {
    //auto start=std::chrono::steady_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs
    #endif

    __AcHiLlEs

    bigRes = 0;
    int t(1);
    accio >> t;
    while (t--) {
        solve();
    }
    cout << bigRes << endl;
    /*auto end = std::chrono::steady_clock::now();
        double elapsed=double (std::chrono::duration_cast < std::chrono::nanoseconds> (end-start).count());
    std::cout << endl << "Terminated\n"<< elapsed/1e9;*/
    return 0;
}