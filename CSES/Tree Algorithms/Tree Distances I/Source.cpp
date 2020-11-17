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
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        tr[x].push_back(y);
        tr[y].push_back(x);
    }
    int res(0);
    vector<int> dstmx(n + 1, 0), dstmx2(n + 1, 0), nmx(n + 1, 0);
    function<int(int, int)> dfs = [&](int u, int p) {
        for (auto &v: tr[u]) if (v != p) {
            int val = dfs(v, u);
            if (val > dstmx2[u]) {
                if (val > dstmx[u]) dstmx2[u] = dstmx[u], dstmx[u] = val, nmx[u] = v;
                else dstmx2[u] = val;
            }
        }
        res = max(dstmx[u] + dstmx2[u], res);
        return dstmx[u] + 1;
    };
 
    function<void(int, int)> dfs2 = [&](int u, int p) {
        if (p) {
            if (nmx[p] != u) {
                if (dstmx[u] > dstmx[p] + 1) dstmx2[u] = max(dstmx[p] + 1, dstmx2[u]);
                else dstmx[u] = dstmx2[u] = dstmx[p] + 1;
            }
            else {
                if (dstmx[u] > dstmx2[p] + 1) dstmx2[u] = max(dstmx2[p] + 1, dstmx2[u]);
                else dstmx[u] = dstmx2[u] = dstmx2[p] + 1;
            }
        }
        for (auto &v: tr[u]) if (v != p) dfs2(v, u);
    };
 
    dfs(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) cout << dstmx[i] << " ";
    cout << "\n";
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