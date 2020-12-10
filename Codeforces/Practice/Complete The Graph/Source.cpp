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
#define sum(a) ((int)a * (int)(a + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)

const int inf = (int)1e9 + 1;

void solve() {
	int n, m, l, s, e, x, y, z;
	cin >> n >> m >> l >> s >> e;
	vector<vector<int>> gph(n);
	map<pair<int, int>, int> dd;
	set<pair<int, int>> lst;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		if (z == 0) lst.insert({min(x, y), max(x, y)}), z = inf;
		gph[x].push_back(y);
		gph[y].push_back(x);
		dd[{min(x, y), max(x, y)}] = z;
	}

	vector<int> dst(n, INT_MAX), parent(n, -1);

	function<void()> dijkstra = [&]() {
		dst[s] = 0;
		priority_queue<pair<int, int>> q;
		q.push({0, s});
		while (!q.empty()) {
			pair<int, int> p = q.top();
			q.pop();
			p.first *= -1;
			if (dst[p.second] != p.first) continue;
			for (auto &v: gph[p.second]) {
				int dis = dd[{min(v, p.second), max(v, p.second)}];
				if (dst[v] > p.first + dis) {
					parent[v] = p.second;
					dst[v] = p.first + dis;
					q.push({-dst[v], v});
				}
			}
		}
	};

	dijkstra();
	if (dst[e] < l) {
		cout << "NO\n";
		return;
	}
	gph.assign(n, vector<int>());
	for (auto &[u, v] : dd) {
		if (v == inf) v = 1;
		gph[u.first].push_back(u.second);
		gph[u.second].push_back(u.first);
	}
	dst.assign(n, INT_MAX);
	dijkstra();
	if (dst[e] > l) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	map<pair<int, int>, int> mp;
	int node(e);
	while (~parent[node]) {
		mp[{node, parent[node]}] = 1;
		mp[{parent[node], node}] = 1;
		node = parent[node];
	}
	for (auto &i : lst) 
		if (mp.find(i) == mp.end()) dd[i] = l + 1;

	while (!lst.empty()) {
		if (!mp[*lst.begin()]) {
			lst.erase(lst.begin());
			continue;
		}
		dd[*lst.begin()] += (l - dst[e]);
		lst.erase(lst.begin());
		dst.assign(n, INT_MAX);
		dijkstra();
		node = e;
		while (~parent[node]) {
			mp[{node, parent[node]}] = 1;
			mp[{parent[node], node}] = 1;
			node = parent[node];
		}
	}

	for (auto &[u, d]: dd) 
		cout << u.first << " " << u.second << " " <<  d << "\n";
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