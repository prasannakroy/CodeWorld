/*****************************
*  Author :: Πρασαννα Κ. Ροι  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

vc<vc<int>> gph;
vc<int> dsu, sz, dmtr, vis;

int root(int a) {
    return a == dsu[a] ? dsu[a] : dsu[a] = root(dsu[a]);
}

void join(int a, int b) {
    a = root(a), b = root(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    dsu[b] = a, sz[a] += sz[b];
    dmtr[a] = max({dmtr[b], dmtr[a], (((dmtr[b] + 1) / 2) + (dmtr[a] + 1) / 2) + 1});
}

array<int, 2> dfs(int u, int t) {
    vis[u] = t;
    array<int, 2> a = {u, -1};
    for (auto &v: gph[u]) if (vis[v] != t) {
        auto x = dfs(v, t);
        if (x[1] > a[1]) a = x;
    }
    a[1]++;
    return a;
}

void solve() {
    int n, m, q, x, y, mx(0);
    cin >> n >> m >> q;
    dmtr.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    gph.resize(n + 1);
    dsu.resize(n + 1);
    sz.assign(n + 1, 1);
    iota(span(dsu), 0);
    for (int i = 0; i < m; i++) cin >> x >> y, gph[x].push_back(y), gph[y].push_back(x), join(x, y);
    for (int i = 1; i <= n; i++) if (dsu[i] == i) {
        auto t = dfs(i, 1);
        t = dfs(t[0], 2);
        dmtr[i] = t[1];
        mx = max(mx, dmtr[i]);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            cin >> x;
            cout << dmtr[root(x)] << "\n";
        }
        else {
            cin >> x >> y;
            join(x, y);
        }
    }
}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}