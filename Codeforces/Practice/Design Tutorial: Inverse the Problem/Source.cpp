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
template<typename t>
using minHeap = priority_queue<t, vc<t>, greater<t>>;

vc<int> dsu, sz;

int root(int a) {
    return a == dsu[a] ? dsu[a] : dsu[a] = root(dsu[a]);
}

bool join(int a, int b) {
    a = root(a), b = root(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    dsu[b] = a, sz[a] += sz[b];
    return true;
}

void solve() {
    int n;
    cin >> n;
    int a[n][n];
    dsu.resize(n + 1);
    sz.assign(n + 1, 1);
    iota(span(dsu), 0);
    for (auto &i: a) for (auto &j: i) cin >> j;
    vc<array<int, 3>> v;
    for (int i = 0; i < n; i++) {
        if (a[i][i] != 0) return void(cout << "NO\n");
        for (int j = i + 1; j < n; j++) {
            if (!a[i][j] or a[j][i] != a[i][j]) return void(cout << "NO\n");
            v.push_back({a[i][j], i + 1, j + 1});
        }
    }
    vc<array<int, 2>> gph[n + 1];
    int m = ((n - 1) * n) >> 1;
    sort(span(v));
    for (auto &[x, y, z] : v) 
        if (join(y, z)) {
            gph[z].push_back({y, x});
            gph[y].push_back({z, x});
        }
    
    vc<vc<int>> dist(n + 1, vc<int>(n + 1, 0));

    function<void(int, int, int)> dfs = [&](int nd, int u, int p) {
        for (auto &v: gph[u]) if (v[0] != p) {
            dist[nd][v[0]] = dist[nd][u] + v[1];
            dfs(nd, v[0], u);
        }
    };

    for (int i = 1; i <= n; i++) 
        dfs(i, i, 0);
    for (int i = 1; i <= n; i++) 
        for (int j = i + 1; j <= n; j++) if (dist[i][j] != a[i - 1][j - 1]) return void(cout << "NO\n");
    cout << "YES\n";
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