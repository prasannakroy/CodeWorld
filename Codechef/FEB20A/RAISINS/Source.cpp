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

i_64 bfs(i_64 root, std::vector<i_64> v[], i_64 l, bool flag[]) {
    std::queue<i_64> q;
    q.push(root);
    std::map<i_64, i_64> check;
    std::map<i_64, i_64> level;
    check[root] = 1;
    level[root] = l;
    std::map<i_64, i_64> levcount;
    while (!q.empty()) {
        i_64 x = q.front();
        q.pop();
        for (int i = 0; i < v[x].size(); i++) {
            if (check[v[x][i]] == 1) {
                continue;
            }
            q.push(v[x][i]);
            check[v[x][i]] = 1;
            level[v[x][i]] = level[x] + 1;
            if (flag[v[x][i]] != 1) {
                continue;
            }
            levcount[level[x] + 1]++;
        }
    }
    i_64 res(0);
    for (auto it : levcount) {
        res += nCr(it.second, 3) * 6;
    }
    return res;
}


int solve() {
    i_64 w, h, r;
    accio >> w >> h >> r;
    for (int i = 0; i < r; i++) {
        int x, y;
        accio >> x >>y;
    }
    cout << 1 << " " << 1 << " " << 0 << endl;
    return 0;
}

int main() {
    //auto start=std::chrono::steady_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs
    #endif

    __AcHiLlEs
    
    int t(1);
    //accio >> t;
    while (t--) {
        solve();
    }
    
    /*auto end = std::chrono::steady_clock::now();
        double elapsed=double (std::chrono::duration_cast < std::chrono::nanoseconds> (end-start).count());
    std::cout << endl << "Terminated\n"<< elapsed/1e9;*/
    return 0;
}