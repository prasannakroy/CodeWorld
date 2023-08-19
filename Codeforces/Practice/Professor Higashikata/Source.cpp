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

vc<int> dsu, tr;

void init(int n) {
    dsu.resize(n, 0);
    iota(span(dsu), 0);
}

int root(int a) {
    return a == dsu[a] ? dsu[a] : dsu[a] = root(dsu[a]);
}

void join(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) 
        return;

    if (a < b) 
    	swap(a, b);

    dsu[b] = a;
}

void update(int p, int l, int r, int idx) {
	if (l > r) 
		return;
	if (l == r) 
		return void(tr[p] ^= 1);

	int m = (l + r) >> 1;
	if (idx <= m) 
		update(p << 1, l, m, idx);
	else 
		update((p << 1) | 1, m + 1, r, idx);
	tr[p] = tr[p << 1] + tr[(p << 1) | 1];
}

int query(int p, int l, int r, int s, int e) {
	if (l > r or s > r or l > e) 
		return 0;
	if (s <= l and e >= r) 
		return tr[p];

	int m = (l + r) >> 1;
	return query(p << 1, l, m, s, e) + query((p << 1) | 1, m + 1, r, s, e);
}

void solve() {
	int n, m, q;
	cin >> n >> m >> q;

	string s;
	cin >> s;

	vc<array<int, 2>> a;

	vc<int> vis(n, 0);

	init(n);
	int len = 0;

	for (int i = 0, x, y; i < m; i++) {
		cin >> x >> y;
		x--, y--;
		int r = -1, l = -1;
		for (int j = x; j <= y; j++) {
			if (!vis[j]) {
				if (r != -1) join(r, j);
				else l = j;
				vis[j] = 1;
				r = j;
			} else {
				if (r != -1) {
					a.push_back({l, r});
					len += (r + 1 - l);
				}
				r = -1;
				j = root(j);
			}
		}
		if (r != -1) {
			len += (r + 1 - l);
			a.push_back({l, r});
		}
	}

	tr.assign(4 * (n + 1), 0);

	int cnt(0);

	vc<int> idx(n, -1);

	for (auto &[x, y]: a) {
		for (int i = x; i <= y; i++) {
			if (s[i] == '1') 
				update(1, 0, len, cnt);
			idx[i] = cnt++;
		}
	}

	cnt = 0;
	for (auto &i: s) if (i == '1') 
		cnt++;

	auto flip = [&](char x) {
		if (x == '0') 
			return '1';
		return '0';
	};

	while (q--) {
		int x;
		cin >> x;
		x--;

		s[x] = flip(s[x]);
		if (s[x] == '0') cnt--;
		else cnt++;

		if (idx[x] != -1) update(1, 0, len, idx[x]);

		int limit = min(cnt, len);
		cout << limit - query(1, 0, len, 0, limit - 1) << '\n';
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