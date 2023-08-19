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
	int n, k;
	cin >> n >> k;

	vc<int> a(n);

	for (auto &i: a) 
		cin >> i;

	vector<int> b;

	int res(0), mx(INT_MAX);

	function<int(int, int)> compute = [&](int idx, int val) {
		if (b[idx] >= val) {
			return 0ll;
		}

		if (idx == n - 1) 
			return mx;

		int cost = compute(idx + 1, val - 1);

		if (b[idx + 1] < val - 1) 
			return mx;

		cost += val - b[idx];

		b[idx] = val;

		return cost;

	};

	for (int i = 0; i < n; i++) {
		int l = a[i], r = a[i] + k + 1;
		while (r - l > 1) {
			int m = (l + r) >> 1;
			b = a;
			int cost = compute(i, m);
			if (cost <= k) 
				l = m;
			else 
				r = m;
		}
		res = max(res, l);
	}

	cout << res << '\n';

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