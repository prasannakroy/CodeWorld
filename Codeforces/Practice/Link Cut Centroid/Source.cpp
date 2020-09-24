/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long

std::vector<int> sz;
vector<int> tr[100001];

void solve() {
    int n, x, y;
    cin >> n;
    sz.assign(n + 1, 1);
    for (int i = 0; i <= n; i++) tr[i].clear();
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        tr[x].push_back(y);
        tr[y].push_back(x);
    }
    if (n & 1) {
        cout << x << " " << y << "\n";
        cout << x << " " << y << "\n";
        return;
    }
    vector<int> cent;
    function<void(int, int)> dfs = [&](int u, int p) {
        bool flag(1);
        for (int &v: tr[u]) if (v != p) {
            dfs(v, u);
            sz[u] += sz[v];
            if (sz[v] > n / 2) flag = 0;
        }
        if (n - sz[u] > n / 2) flag = 0;
        if (flag) cent.push_back(u);
    }; 
    dfs(1, 0);
    if (cent.size() == 1) {
        cout << x << " " << y << "\n";
        cout << x << " " << y << "\n";
        return;
    }
    for (int &i: tr[cent[0]]) if (i != cent[1]) x = i;
    cout << x << " " << cent[0] << "\n";
    cout << x << " " << cent[1] << "\n";
}

signed main() {
    __AcHiLlEs
  
    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
