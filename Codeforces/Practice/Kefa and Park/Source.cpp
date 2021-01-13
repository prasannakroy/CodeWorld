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

void solve() {
    int n, m, x, y;
    cin >> n >> m;
    vc<int> gph[n + 1], cat(n + 1);
    for (int i = 1; i <= n; i++) cin >> cat[i];
    for (int i = 1; i < n; i++) cin >> x >> y, gph[x].push_back(y), gph[y].push_back(x);

    function<int(int, int, int)> dfs = [&](int u, int p, int c) {
        if (cat[u]) c += 1;
        else c = 0;
        if (c > m) return 0ll;
        int res(0), flag(1);
        for (auto &v: gph[u]) if (v != p) flag = 0, res += dfs(v, u, c);
        return max(res, flag);
    };

    cout << dfs(1, 0, 0) << "\n";
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