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
	vc<vc<vc<int>>> gph(2, vc<vc<int>>(n + 1));
	for (int i = 0; i < m; i++) cin >> x >> y, gph[0][x].push_back(y), gph[1][y].push_back(x);
	vc<int> vis(n + 1, 0), res(n + 1, 0), lst;
	int cnt(0);
	function<void(int, int)> dfs = [&](int u, int t) {
		vis[u] = 1;
		for (auto &v: gph[t][u]) if (!vis[v]) dfs(v, t);
		if (!t) lst.push_back(u);
		else res[u] = cnt;
	};

	for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i, 0);
	fill(span(vis), 0);
	reverse(span(lst));
	for (auto &i: lst) if (!vis[i]) cnt++, dfs(i, 1);
	cout << cnt << "\n";
	for (int i = 1; i <= n; i++) cout << res[i] << " ";
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