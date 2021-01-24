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
    int n, r, m, x, y;
    cin >> n >> r >> m;
    vc<int> gph[n + 1];
    for (int i = 0; i < r; i++) cin >> x >> y, gph[x].push_back(y), gph[y].push_back(x);
    vector<array<int, 2>> vis(n + 1, {-1, -1});
    queue<int> q;
    for (int i = 0; i < m; i++) cin >> x >> y, vis[x] = {x, y}, q.push(x);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (!vis[u][1]) continue;
        for (auto &v: gph[u]) {
            if (~vis[v][0]) {
                if (vis[u][0] == vis[v][0]) continue;
                else return void(cout << "No\n");
            }
            else {
                vis[v] = vis[u];
                vis[v][1]--;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) if (vis[i][0] == -1) return void(cout << "No\n");
    cout << "Yes\n";
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