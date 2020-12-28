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
#define span(a) a.begin(), a.end()

template<typename t>
using vi = vector<t>;

void solve() {
    int n, m, x, y;
    cin >> n >> m;
    vi<vi<vi<int>>> gph(2, vi<vi<int>>(n + 1));
    vi<int> vis[2];
    vis[0].assign(n + 1, 0);
    vis[1].assign(n + 1, 0);
    for (int i = 0; i < m; i++) cin >> x >> y, gph[0][x].push_back(y), gph[1][y].push_back(x);
    vis[0][1] = vis[1][1] = 1;
    function<void(int, int)> dfs = [&](int u, int t) {
        vis[t][u] = 1;
        for (auto &v: gph[t][u]) if (!vis[t][v]) dfs(v, t);
    };

    dfs(1, 0);
    dfs(1, 1);

    for (int i = 1; i <= n; i++) {
        if (!vis[0][i]) return void(cout << "NO\n" << 1 << " " << i << "\n");
        else if (!vis[1][i]) return void(cout << "NO\n" << i << " " << 1 << "\n");
    }
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