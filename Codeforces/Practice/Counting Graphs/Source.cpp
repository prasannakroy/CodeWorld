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

const int mod = 998244353;
vc<int> dsu, sz, res;

int power(int a, int b) {
    int res(1);
    while (b) {
        if (b & 1) {
            (res *= a) %= mod;
        } 
        (a *= a) %= mod;
        b >>= 1;
    }
    return res;
}

void init(int n) {
	dsu.assign(n + 1, 0);
	iota(span(dsu), 0);
	sz.assign(n + 1, 1);
	res.assign(n + 1, 1);
}

int root(int a) {
    if (dsu[a] == a) 
        return dsu[a];
    
    return dsu[a] = root(dsu[a]);
}

void join(int a, int b, int w, int s) {
    a = root(a);
	b = root(b);

	if (a == b) 
		return;

	if (sz[a] < sz[b]) {
		swap(a, b);
	}

	int dif = s + 1 - w;
	int val = ((sz[a] - 1) * (sz[b] - 1)) + (sz[a] - 1) + (sz[b] - 1);

	int ed = power(dif, val);

	dsu[b] = a;
	sz[a] += sz[b];
	(res[a] *= res[b]) %= mod;
	(res[a] *= ed) %= mod;
}

void solve() {
	int n, s;
	cin >> n >> s;

	vc<array<int, 3>> edges(n - 1);

	for (auto &i: edges) {
		cin >> i[0] >> i[1] >> i[2];
	}

	sort(span(edges), [&](array<int, 3> p, array<int, 3> q) {
		return p[2] < q[2];
	});

	init(n);

	for (auto &[a, b, c]: edges) {
		join(a, b, c, s);
	}

	cout << res[root(n)] << '\n';

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