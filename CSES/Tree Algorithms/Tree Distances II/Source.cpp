#include<bits/stdc++.h>
using namespace std;
 
#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define span(a) a.begin(), a.end()
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)
 
void solve() {
    int n, x, y;
    cin >> n;
    vector<vector<int>> tr(n + 1, vector<int>());
    for (int i = 1; i < n; i++) cin >> x >> y, tr[x].push_back(y), tr[y].push_back(x);
 
    vector<int> res(n + 1, 0), sz(n + 1, 1);
    
    function<int(int, int)> dfs = [&] (int u, int p) {
        for (auto &v: tr[u]) if (v != p) {
            sz[u] += dfs(v, u);
            res[u] += (res[v] + sz[v]);
        }
        return sz[u];
    };
 
    function<void(int, int)> dfs2 = [&] (int u, int p) {
        if (p) res[u] = res[p] - sz[u] + n - sz[u];
        for (auto &v: tr[u]) if (v != p) dfs2(v, u);
    };
 
    dfs(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) cout << res[i] << " ";
    cout << "\n";
}
 
signed main() {
 
    __AcHiLlEs
 
    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}