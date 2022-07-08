/*****************************
*  Author :: Πρασαννα Κ. Ροι *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

template<typename t>
using minpq = priority_queue<t, vc<t>, greater<t>>;

template<typename t>
using maxpq = priority_queue<t>;

void solve() {
	int n;
	cin >> n;
	vc<vc<int>> adj(n + 1);
	vc<int> deg(n + 1, 0);
	vc<array<int, 2>> dp(n + 1, {0, 0});
	int rt = -1;
	for (int i = 1, x, y; i < n; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		deg[x]++;
		deg[y]++;
		if (deg[x] >= 2) 
			rt = x;
		if (deg[y] >= 2) 
			rt = y;
	}
	int mx(n - 1), mn(1);

	function<void(int, int)> dfs = [&](int u, int p) {
		int odd = 0, even = 0, cnt = 0;
		for (auto &v: adj[u]) if (v != p) {
			if (deg[v] == 1) {
				dp[v] = {1, 0};
				cnt++;
			} else dfs(v, u);
			if (dp[v][0]) 
				even = 1;
			if (dp[v][1]) 
				odd = 1;
		}
		if (cnt) 
			mx -= (cnt - 1);
		if (odd and even) {
			// cout << u << '\n';
			mn = 3;
		}
		if (odd) 
			dp[u][0] = 1;
		if (even) 
			dp[u][1] = 1;
	};

	dfs(rt, 0);
	cout << mn << ' ' << mx << '\n';

}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1), st(0);
  // cin >> t;
  for (int i = st; i < t + st; /*cout << "Case #" << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}