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
	
	for (int i = 1, x, y; i < n; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	int l = ceil(log2(n));

	vc<vc<int>> anc(n + 1, vc<int>(l + 1, 0));
	vc<int> tin(n + 1, 0), tout(n + 1, 0), depth(n + 1, 0);
	int timer(0);

	function<void(int, int)> dfs = [&](int u, int p) {
		tin[u] = ++timer;
		anc[u][0] = p;
		depth[u] = depth[p] + 1;

		for (int i = 1; i <= l; i++) {
			anc[u][i] = anc[anc[u][i - 1]][i - 1];
		}

		for (auto &v: adj[u]) if (v != p) 
			dfs(v, u);
		tout[u] = ++timer;
	};

	function<bool(int, int)> isAncestor = [&](int a, int b) {
		return (tin[a] <= tin[b] and tout[a] >= tout[b]);
	};

	function<int(int, int)> lca = [&](int a, int b) {
		if (isAncestor(a, b)) 
			return a;
		if (isAncestor(b, a)) 
			return b;

		for (int i = l; i >= 0; i--) {
			if (!isAncestor(anc[a][i], b)) 
				a = anc[a][i];
		}

		return anc[a][0];
	};

	function<int(int, int)> dist = [&](int a, int b) {
		int p = lca(a, b);
		return depth[a] + depth[b] - (depth[p] * 2);
	};

	dfs(1, 1);

	int q;
	cin >> q;

	while (q--) {
		int k;
		cin >> k;
		vc<int> lst(k);
		int u, v, dpth(0);
		for (auto &i: lst) {
			cin >> i;
			if (depth[i] > dpth) {
				dpth = depth[i];
				u = i;
			}
		}
		int dst = INT_MIN;

		for (auto &i: lst) {
			int d = dist(u, i);
			if (d > dst) {
				dst = d;
				v = i;
			}
		}

		bool check = true;

		for (auto &i: lst) if (i != u and i != v) {
			if (dist(u, i) + dist(i, v) != dst) {
				check = false;
				break;
			}
		}

		cout << (check ? "YES": "NO" ) << '\n';
	}

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