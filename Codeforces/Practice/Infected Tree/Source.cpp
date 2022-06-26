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
	vc<int> adj[n + 1];

	for (int i = 1, x, y; i < n; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	vc<int> dp(n + 1, -1);

	function<int(int, int)> dfs = [&](int u, int p) {
		vc<int> res, child;
		int sz(1);
		dp[u] = 0;
		for (auto &v: adj[u]) if (v != p) {
			child.push_back(v);
			int val = dfs(v, u);
			sz += val;
			res.push_back(val);
		}
		if (res.size() == 1) 
			dp[u] = res[0] - 1;
		else if (res.size() == 2) 
			dp[u] = max(dp[child[0]] + res[1] - 1, dp[child[1]] + res[0] - 1);
		return sz;
	};

	dfs(1, -1);
	cout << dp[1] << '\n';

}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1), st(0);
  cin >> t;
  for (int i = st; i < t + st; /*cout << "Case #" << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}