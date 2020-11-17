/*****************************
*  Author :: Prasanna Kumar  *
*****************************/
 
/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;
 
#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) a.begin(), a.end()
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)
 
void solve() {
    int n, x, y;
    cin >> n;
    vector<vector<int>> tr(n + 1, vector<int>());
    vector<bool> vis(n + 1, 0);
 
    for (int i = 1; i < n; i++) cin >> x >> y, tr[x].push_back(y), tr[y].push_back(x);
    int cnt(0);
    function<void(int, int)> dfs = [&] (int u, int p) {
        for (auto &v: tr[u]) if (v != p) {
            dfs(v, u);
            if (!vis[v] and !vis[u]) vis[v] = 1, vis[u] = 1, cnt++;
        }
    };
    dfs(1, 0);
    cout << cnt << "\n";
}
 
signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif
 
    __AcHiLlEs
 
    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}