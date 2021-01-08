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
using vc = vector<t>;

void solve() {
    int n, m, x, y;
    cin >> n >> m;
    vc<int> gph[n + 1];
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        gph[x].push_back(y);
    }
    vc<int> dst(n + 1, 1e18);
    queue<int> q;
    q.push(1);
    dst[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &v: gph[u]) if (dst[v] == 1e18) dst[v] = dst[u] + 1, q.push(v);
    }
    vc<int> dp(n + 1, 1e18);

    function<void(int)> dfs = [&](int u) {
        dp[u] = dst[u];
        for (auto &v: gph[u]) {
            if (dst[v] > dst[u]) {
                if (dp[v] == 1e18) 
                    dfs(v);
                dp[u] = min(dp[u], dp[v]);
            }
            else dp[u] = min(dp[u], dst[v]);
        }
    };
    dfs(1);
    for (int i = 1; i <= n; i++) cout << dp[i] << " ";
    cout << "\n";

}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}