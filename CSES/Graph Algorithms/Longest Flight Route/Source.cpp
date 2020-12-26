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
	int n, m, x, y;
	cin >> n >> m;
	vector<int> vis(n + 1, 0), dist(n + 1, 0), parent(n + 1, 0), gph[n + 1], rgph[n + 1];
	for (int i = 0; i < m; i++) cin >> x >> y, gph[x].push_back(y), rgph[y].push_back(x);
	stack<int> st;

	function<void(int)> topological = [&](int u) {
		vis[u] = 1;
		for (auto &v: gph[u]) if (!vis[v]) {
			dist[v] = dist[u] + 1;
			parent[v] = u;
			topological(v);
		}
		st.push(u);
	};

	topological(1ll);
	if (!vis[n]) return void(cout << "IMPOSSIBLE\n");
	while (!st.empty()) {
		int u = st.top();
		st.pop();
		for (auto &v: rgph[u]) if (dist[u] < dist[v] + 1) {
			parent[u] = v;
			dist[u] = dist[v] + 1;
		}
	}
	cout << dist[n] + 1 << "\n";
	vector<int> res;
	res.push_back(n);
	x = n;
	while (x - 1) res.push_back(x = parent[x]);
	reverse(span(res));
	for (auto &i: res) cout << i << " ";
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