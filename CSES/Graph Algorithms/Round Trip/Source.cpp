/*****************************
*  Author :: Prasanna Kumar  *
*****************************/
 
/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
using namespace std::chrono;
 
#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) a.begin(), a.end()
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)
 
void solve() {
	int n, m, x, y;
	cin >> n >> m;
	vector<vector<int>> gph(n + 1);
	for (int i = 0; i < m; i++) cin >> x >> y, gph[x].push_back(y), gph[y].push_back(x);
	vector<int> vis(n + 1, 0), parent(n + 1, 0), res;
	function<bool(int, int)> dfs = [&](int u, int p) {
		vis[u] = 1;
		parent[u] = p;
		bool flag = 0;
		for (auto &v: gph[u]) {
			if (vis[v] and v != p) {
			    res.push_back(v);
				while (u != v) res.push_back(u), u = parent[u];
				res.push_back(u);
				return true;
			}
			else if (!vis[v]) flag |= dfs(v, u);
			if (flag) return flag;
		}
		return flag;
	};
	bool flag(0);
	for (int i = 1; i <= n; i++) if (!vis[i]) {
		flag |= dfs(i, 0);
		if (flag) break;
	}
	if (flag) {
	    cout << res.size() << "\n";
	    for (auto &i: res) cout << i << " ";
	    cout << "\n";
	}
	else cout << "IMPOSSIBLE\n";
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