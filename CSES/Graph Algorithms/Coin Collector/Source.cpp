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
	vc<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	vc<vc<vc<int>>> gph(2, vc<vc<int>>(n + 1));
	for (int i = 0; i < m; i++) cin >> x >> y, gph[0][x].push_back(y), gph[1][y].push_back(x);
	vc<int> lst, vis(n + 1, 0), comp(n + 1, 0), cost(n + 1, 0);
	int cnt(1);

	function<void(int, int)> dfs = [&](int u, int t) {
		vis[u] = 1;
		for (auto &v: gph[t][u]) if (!vis[v]) dfs(v, t);
		if (t) comp[u] = cnt, cost[cnt] += a[u];
		else lst.push_back(u);
	};

	for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i, 0);
	reverse(span(lst));
	fill(span(vis), 0);
	for (auto &i: lst) if (!vis[i]) dfs(i, 1), cnt++;
	cost.resize(cnt);
	vc<int> deg(cnt, 0);
	set<pair<int, int>> cgph[cnt];
	for (int i = 1; i <= n; i++) 
		for (auto &j: gph[0][i]) if (comp[i] != comp[j]) 
			cgph[min(comp[i], comp[j])].insert({max(comp[i], comp[j]), cost[max(comp[i], comp[j])]});
	for (int i = 1; i < cnt; i++) 
		for (auto &j: cgph[i]) deg[j.first]++;
	priority_queue<pair<int, int>> q;
	vector<int> dist(cnt, INT_MIN);
	for (int i = 1; i < cnt; i++) if (!deg[i]) q.push({cost[i], i}), dist[i] = cost[i];
	int res(0);
	while (!q.empty()) {
		auto u = q.top();
		q.pop();
		if (dist[u.second] != u.first) continue;

		for (auto &v: cgph[u.second]) 
			if (dist[v.first] < u.first + v.second) dist[v.first] = u.first + v.second, q.push({dist[v.first], v.first});
	}

	for (int i = 1; i < cnt; i++) 
		res = max(res, dist[i]);

	cout << res << "\n";
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