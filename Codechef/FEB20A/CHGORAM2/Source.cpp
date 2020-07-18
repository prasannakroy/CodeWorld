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

void dfs(int u, int p, int **rv, int *lev, int lg, vector<int> *g) { 
    rv[u][0] = p; 
    for (int i = 1; i <= lg; i++) 
        rv[u][i] = rv[rv[u][i - 1]][i - 1]; 
    for (int v : g[u]) { 
        if (v != p) { 
            lev[v] = lev[u] + 1; 
            dfs(v, u, rv, lev, lg, g); 
        } 
    } 
} 

int lca(int u, int v, int lg, int *lev, int **rv) { 
    if (lev[u] < lev[v]) 
        swap(u, v); 
    for (int i = lg; i >= 0; i--) 
        if ((lev[u] - pow(2, i)) >= lev[v]) 
            u = rv[u][i]; 
 
    if (u == v) 
        return u; 
    for (int i = lg; i >= 0; i--) { 
        if (rv[u][i] != rv[v][i]) { 
            u = rv[u][i]; 
            v = rv[v][i]; 
        } 
    } 
    return rv[u][0]; 
} 



int solve() {
    int n;
    accio >> n;
    int lg = (int)ceil(log2(n)); 
    int **rv = new int *[n + 1]; 
    for (int i = 0; i < n + 1; i++) {
        rv[i] = new int[lg + 1]; 
    }
    int *lev = new int[n + 1]; 
    for (int i = 0; i < n + 1; i++) {
        memset(rv[i], -1, sizeof rv[i]); 
    }
    std::vector<int> v[n + 1];
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        accio >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    map<int, int> flag;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        flag[i + 1] = x;
    }

    std::map<int, int> res;
    int dist[n + 1][n + 1];
    memset(dist, 0, sizeof dist);
    dfs(1, 1, rv, lev, lg, v); 
    for (int i = 1; i < n; ++i) {
        if (flag[i] != 1) {
            continue;
        }
        for (int j = i + 1; j <= n; j++) {
            if (flag[j] != 1) {
                continue;
            }
            int x = lca(i, j, lg, lev, rv);
            int d = lev[i] + lev[j] - (2 * lev[x]);
            dist[i][j] = d;
            dist[j][i] = d;
        }
    }
    i_64 result(0);
    for (int i = 1; i < n; i++) {
        if (flag[i] != 1) {
            continue;
        }
        for (int j = i + 1; j <= n; j++) {
            int sol = 0;
            if(flag[j] != 1) {
                continue;
            }
            for (int k = j + 1; k <= n; k++) {
                if (flag[k] != 1) {
                    continue;
                }
                if (k == j) {
                    continue;
                }
                if (dist[i][j] == dist[i][k]) {
                    if (dist[j][k] == dist[i][j]) {
                        sol++;
                    }
                }
            }
            result += (sol * 6);
        }
    }
    cout << result << endl;
    return 0;
}

int main() {
    //auto start=std::chrono::steady_clock::now();
    /*#ifndef ONLINE_JUDGE 
        __AnAkLuSmOs
    #endif*/

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