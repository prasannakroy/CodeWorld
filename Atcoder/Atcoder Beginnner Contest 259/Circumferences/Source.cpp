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
	int n, s[2], t[2];
	cin >> n;
	
	cin >> s[0] >> s[1] >> t[0] >> t[1];
	
	vc<array<int, 3>> a(n);
	
	for (auto &i: a) 
		cin >> i[0] >> i[1] >> i[2];
	// for (auto &i: a) 
	// 	cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';

	vc<int> dsu(n + 2, 0), sz(n + 2, 1);
	iota(span(dsu), 0);

	function<int(int)> root = [&](int u) {
		return dsu[u] == u? dsu[u] : dsu[u] = root(dsu[u]);
	};

	function<void(int, int)> join = [&](int u, int v) {
		u = root(u);
		v = root(v);
		if (u == v) 
			return;
		if (sz[u] < sz[v]) 
			swap(u, v);
		dsu[v] = u;
		sz[u] += sz[v];
	};

	function<int(int)> square = [&](int x) {
		return x * x;
	};

	function<int(int, int, int, int)> distance = [&](int sx, int sy, int tx, int ty) {
		return square(sx - tx) + square(sy - ty);
	};


	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int dist = distance(a[i][0], a[i][1], a[j][0], a[j][1]);
			if (dist < square(max(a[i][2], a[j][2]))) {
				int dif = square(abs(a[i][2] - a[j][2]));
				if (dif <= dist) 
					join(i, j);
			}
			else if (dist <= square(a[i][2] + a[j][2])) {
				// cout << i << ' ' << j << '\n';
				join(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int dist = distance(a[i][0], a[i][1], s[0], s[1]);
		if (dist == square(a[i][2])) 
			join(i, n);
	}

	for (int i = 0; i < n; i++) {
		int dist = distance(a[i][0], a[i][1], t[0], t[1]);
		if (dist == square(a[i][2])) 
			join(i, n + 1);
	}

	if (root(n) == root(n + 1)) 
		cout << "Yes\n";
	else 
		cout << "No\n";

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