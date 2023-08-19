// Author : Prasanna Kumar
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
	
	vc<vc<int>> adj(n);

	for (int i = 1, x; i < n; i++) {
		cin >> x;
		adj[i].push_back(--x);
		adj[x].push_back(i);
	}

	function<array<int, 2>(int, int)> dfs = [&](int u, int p) {
		int sum(0), sz(0);
		vc<int> lst = {0};
		
		for (auto &v: adj[u]) if (v != p) {
			auto resp = dfs(v, u);
			lst.push_back(resp[1]);
			sz += resp[1];
			sum += resp[0];
		}

		int len = lst.size();

		vc<bool> dp(sz + 1, 0);
		dp[0] = 1;

		array<int, 2> res = {0, sz + 1};

		for (int i = 0; i < len; i++) {
			for (int j = sz - lst[i]; j >= 0; j--) if (dp[j]) {
				dp[j + lst[i]] = 1;
				res[0] = max(res[0], (j + lst[i]) * (sz - (j + lst[i])));
			}
		}

		res[0] += sum;
		
		return res;
	};

	cout << dfs(0, 0)[0] << '\n';

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