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
        gph[y].push_back(x);
    }
    if (m < n - 1) return void(cout << "NO\n");
    vc<int> vis(n + 1, 0), res(n + 1, 0);
    deque<int> q;
    q.push_back(1);
    int c(0);
    vis[1] = res[1] = 1;
    while (!q.empty()) {
        int u = q.front();
        if (res[u]) {
            c++;
            q.pop_front();
            for (auto &v: gph[u]) vis[v] = 1, res[v] = 0, q.push_back(v);
        }
        else {
            bool flag = 0;
            for (auto &v: gph[u]) if (!vis[v]) {
                res[v] = 1;
                vis[v] = 1;
                q.push_front(v);
                flag = 1;
                break;
            }
            if (!flag) q.pop_front();
        }
    }
    int flag(1);
    for (int i = 1; i <= n; i++) flag &= vis[i];
    if (!flag) return void(cout << "NO\n");
    cout << "YES\n";
    cout << c << "\n";
    for (int i = 1; i <= n; i++) if (res[i]) cout << i << " ";
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