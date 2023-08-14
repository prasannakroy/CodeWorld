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


vc<int> dsu, sz;

void init(int n) {
	dsu.resize(n, 0);
	iota(span(dsu), 0);
	sz.assign(n + 1, 1);
}

int root(int a) {
	return a == dsu[a] ? dsu[a] : dsu[a] = root(dsu[a]);
}

void join(int a, int b) {
	a = root(a);
	b = root(b);
	if (a == b) 
		return;

	if (sz[a] < sz[b]) 
		swap(a, b);

	dsu[b] = a;
	sz[a] += sz[b];
}

void solve() {
	int n, m;
	cin >> n >> m;

	init(n);

	vc<int> ht(n);
	vc<array<int, 2>> a(n);

	for (int i = 0; i < n; i++) {
		cin >> ht[i];
		a[i] = {ht[i], i};
	}

	sort(span(a));

	vc<int> adj[n];
	for (int i = 0, x, y; i < m; i++) {
		cin >> x >> y;
		x--;
		y--;
		if (ht[x] < ht[y]) 
			swap(x, y);
		adj[x].push_back(y);
	}

	int q;
	cin >> q;
	vc<array<int, 4>> lst(q);
	for (int i = 0; i < q; i++) {
		cin >> lst[i][0] >> lst[i][1] >> lst[i][2];
		lst[i][0]--;
		lst[i][1]--;
		lst[i][3] = i;
	}

	sort(span(lst), [&](array<int, 4> p, array<int, 4> q) {
		if ((ht[p[0]] + p[2]) < (ht[q[0]] + q[2])) 
			return true;
		return false;
	});

	vc<string> res(q, "NO");

	int idx = 0;
	for (auto &[u, v, e, i]: lst) {
		int nrg = ht[u] + e;
		while (idx < n and a[idx][0] <= nrg) {
			for (auto &j: adj[a[idx][1]]) {
				join(a[idx][1], j);
			}
			idx++;
		}
		if (root(dsu[u]) == root(dsu[v])) 
			res[i] = "YES";
	}

	for (auto &i: res) 
		cout << i << '\n';
	cout << '\n';

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