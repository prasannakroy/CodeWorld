// Author : Prasanna Kumar
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int unsigned long long
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

	auto compute = [&](int val, int k) {
		int res(1);
		for (int i = 1; i < k; i++) 
			(res *= val) += 1;
		return res;
	};
	
	for (int i = 3; i <= 61; i++) {
		int l = 1;
		int r = pow(n, 1.0 / (i - 1)) + 1;

		while (r - l > 1) {
			int m = (l + r) >> 1;
			int sum = compute(m, i);
			if (sum < n) 
				l = m;
			else 
				r = m;
		}
		if (compute(r, i) == n) {
			return void(cout << "YES\n");
		}
	}
	cout << "NO\n";
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