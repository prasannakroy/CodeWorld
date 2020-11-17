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
    function<int(int, int)> dfs = [&](int u, int p) {
        int mx1(0), mx2(0);
        for (auto &v: tr[u]) if (v != p) {
            int val = dfs(v, u);
            if (val > mx2) {
                if (val > mx1) mx2 = mx1, mx1 = val;
                else mx2 = val;
            }
        }
        res = max(mx1 + mx2, res);
        return mx1 + 1;
    };
 
    dfs(1, 0);
    cout << res << "\n";
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