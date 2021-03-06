/*****************************
*  Author :: Prasanna Kumar  *
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

void solve() {
	int n;
	cin >> n;
	vector<int> gph(n + 1), rgph[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> gph[i];
		rgph[gph[i]].push_back(i);
	}
	vector<int> vis(n + 1, 0), cycle(n + 1, 0), tin(n + 1, 0), tout(n + 1, 0), dist(n + 1, INT_MAX), root(n + 1, 0);
    int timer(0);

    function<int(int)> dbfs = [&](int u) {
        vis[u] = 1;
        int c = gph[u];
        if (!vis[gph[u]]) c = dbfs(gph[u]);
        return (vis[u] = 0), c;
    };

    function<void(int, int)> bdfs = [&](int u, int p) {
        vis[u] = 1;
        root[u] = p;
        tin[u] = ++timer;
        for (auto &v: rgph[u]) if (!vis[v]) {
            if (!cycle[v]) dist[v] = dist[u] + 1;
            bdfs(v, p);
        }
        tout[u] = ++timer;
    };
    
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        int r = dbfs(i);
        int y = gph[r], cnt(1);
        while (y != r) cnt++, y = gph[y];
        y = gph[r], cycle[r] = cnt;
        while (y != r) cycle[y] = cnt, dist[y] = cnt, y = gph[y];
        dist[r] = cnt;
        bdfs(r, r);
    }

    for (int i = 1; i <= n; i++) cout << dist[i] << " ";
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