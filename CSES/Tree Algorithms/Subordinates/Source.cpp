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

void solve() {
    int n, x;
    cin >> n;
    vector<vector<int>> tr(n + 1, vector<int>());
    for (int i = 2; i <= n; i++) {
        cin >> x;
        tr[x].push_back(i);
    }
    
    vector<int> res(n + 1, 0);
    
    function<int(int)> dfs = [&] (int u) {
        int cnt(0);
        for (auto &v: tr[u]) 
            cnt += dfs(v);
        res[u] = cnt;
        return (int)(cnt + 1);
    };
    
    dfs(1);
    
    for (int i = 1; i <= n; i++) cout << res[i] << " ";
    cout << "\n";
}

signed main() {
    // #ifndef ONLINE_JUDGE 
    //     __AnAkLuSmOs    
    // #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case #" << i << ": ",*/ solve(), i++);
    return 0;
}