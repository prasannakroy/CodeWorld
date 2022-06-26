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

int n;
vc<int> a, nxtG, nxtS;
vc<array<int, 2>> tr;

array<int, 2> join(array<int, 2> p, array<int, 2> q) {
	array<int, 2> res;
	if (p[0] == -1) 
		res[0] = q[0];
	else if (q[0] == -1) 
		res[0] = p[0];
	else if (p[1] == -1) 
		res[1] = q[1];
	else if (q[1] == -1) 
		res[1] = p[1];
	if (~p[0] and ~q[0]) {
		if (a[p[0]] < a[q[0]]) 
			res[0] = p[0];
		else 
			res[0] = q[0];
	}
	if (~p[1] and ~q[1]) {
		if (a[p[1]] > a[q[1]]) 
			res[1] = p[1];
		else 
			res[1] = q[1];
	}
	return res;
}

void build(int p, int l, int r) {
	if (l > r) 
		return;

	if (l == r) 
		return void(tr[p] = {l, l});

	int m = (l + r) >> 1;
	build(p << 1, l, m);
	build((p << 1) | 1, m + 1, r);
	tr[p] = join(tr[p << 1], tr[(p << 1) | 1]);
}

array<int, 2> query(int p, int l, int r, int s, int e) {
	// cout << l << ' ' << r << ":\n";
	if (l > e or s > r or l > r) 
		return {-1, -1};
	if (s <= l and e >= r) 
		return tr[p];
	int m = (l + r) >> 1;
	if (m >= e) 
		return query(p << 1, l, m, s, e);
	else if (m < s) 
		return query((p << 1) | 1, m + 1, r, s, e);
	else 
		return join(query(p << 1, l, m, s, e), query((p << 1) | 1, m + 1, r, s, e));
}

void getNextGreater() {
	stack<int> s;
  for (int i = 0; i < n; i++) {
    if (s.empty()) {
    	s.push(i);
    	continue;
    }
    while (s.empty() == false and a[s.top()] < a[i]) {
    	nxtG[s.top()] = i;
    	s.pop();
    }
    s.push(i);
  }
  while (s.empty() == false) {
    nxtG[s.top()] = -1;
    s.pop();
  }
}

void getNextSmaller() {
	stack<int> s;
	for (int i = 0; i < n; i++) {
    if (s.empty()) {
    	s.push(i);
    	continue;
    }
    while (s.empty() == false and a[s.top()] > a[i]) {
    	nxtS[s.top()] = i;
    	s.pop();
    }
    s.push(i);
  }
  while (s.empty() == false) {
    nxtS[s.top()] = -1;
    s.pop();
  }
}

void solve() {
	cin >> n;
	a.assign(n, 0);
	nxtG.assign(n, 0);
	nxtS.assign(n, 0);
	tr.assign(4 * (n + 1), {-1, -1});
	for (auto &i: a) 
		cin >> i;
	build(1, 0, n - 1);
	getNextGreater();
	getNextSmaller();

	vc<int> adj[n + 1];

	for (int i = 0; i < n - 1; i++) {
		int idx = nxtG[i];
		int mn = idx;
		// cout << idx << ":\n";
		if (idx == -1) {
			mn = query(1, 0, n - 1, i, n - 1)[0];
		}
		else {
			// if (i == 2) {
				// cout << i << " " << idx << '\n';
				mn = query(1, 0, n - 1, i, idx)[0];
				// cout << "min in range " << mn << '\n';
			// }
		}
		if (mn != i) {
			adj[i + 1].push_back(mn + 1);
			adj[mn + 1].push_back(i + 1);
		}
		idx = nxtS[i];
		mn = idx;
		// cout << idx << "-\n";
		if (idx == -1) {
			mn = query(1, 0, n - 1, i, n - 1)[1];
		}
		else {
			mn = query(1, 0, n - 1, i, idx)[1];
		}
		if (mn != i) {
			adj[i + 1].push_back(mn + 1);
			adj[mn + 1].push_back(i + 1);
		} 
	}

	vc<int> dist(n + 1, -1);

	function<void()> bfs = [&]() {
		queue<int> q;
		vc<int> vis(n + 1, 0);
		dist[1] = 0;
		q.push(1);
		vis[1] = 1;
		while (!q.empty()) {
			auto u = q.front();
			q.pop();
			for (auto &v: adj[u]) if (!vis[v]) {
				q.push(v);
				vis[v] = 1;
				dist[v] = dist[u] + 1;
				if (v == n) 
					return;
			}
		}
	};

	bfs();
	cout << dist[n] << '\n';

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