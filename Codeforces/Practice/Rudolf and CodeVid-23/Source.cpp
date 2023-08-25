// Author : Prasanna Kumar
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

template<typename t>
using minpq = priority_queue<t, vc<t>, greater<t>>;

template<typename t>
using maxpq = priority_queue<t>;

void solve() {
	int n, m;
	cin >> n >> m;
	
	string s;
	cin >> s;

	auto binToInt = [&](string str) {
		int val(0);
		for (int i = 0; i < n; i++) if (str[i] == '1') {
			val += (1 << (n - i - 1));
		}
		return val;
	};

	int src = binToInt(s);
	int dest = 0;

	vc<array<int, 3>> lst(m);

	for (int i = 0; i < m; i++) {
		int d;
		string cr, sd;
		cin >> d >> cr >> sd;
		lst[i] = {d, binToInt(cr), binToInt(sd)};
	}

	int sz = (1 << n) + 1;

	vc<vc<array<int, 2>>> adj(sz);
	vc<vc<int>> adjMat(sz, vc<int>(sz, INT_MAX));
	vc<bool> vis(sz);

	queue<int> q;
	q.push(src);
	vis[src] = 1;

	while (!q.empty()) {
		int t = q.front();
		q.pop();
		if (!t) 
			continue;
		for (auto &[a, b, c]: lst) {
			int val = t - (t & b);
			val |= c;
			if (adjMat[t][val] > a) {
				adjMat[t][val] = a;
			}
			if (!vis[val]) {
				vis[val] = 1;
				q.push(val);
			}
		}
	}

	for (int i = 0; i < sz; i++) 
		for (int j = 0; j < sz; j++) if (adjMat[i][j] != INT_MAX) 
			adj[i].push_back({j, adjMat[i][j]});

	vc<int> dist(sz, INT_MAX);
	dist[src] = 0;
	minpq<array<int, 2>> pq;

	pq.push({0, src});

	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();

		if (p[0] != dist[p[1]]) continue;
		for (auto &[v, d]: adj[p[1]]) {
			if (dist[v] > dist[p[1]] + d) {
				dist[v] = dist[p[1]] + d;
				pq.push({dist[v], v});
			}
		}
	}

	cout << (dist[0] == INT_MAX ? -1 : dist[0]) << '\n';
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