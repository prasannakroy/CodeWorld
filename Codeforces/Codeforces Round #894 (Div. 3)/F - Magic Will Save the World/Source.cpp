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
	int w, f;
	cin >> w >> f;
	int n, sum(0);
	cin >> n;
	vc<int> a(n);
	for (auto &i: a) {
		cin >> i;
		sum += i;
	}

	vc<bool> dp(sum + 1, 0);
	dp[0] = 1;

	for (int i = 0; i < n; i++) 
		for (int j = sum; j >= a[i]; j--) if (dp[j - a[i]])
			dp[j] = 1;

	vc<int> lst;

	for (int i = 0; i <= sum; i++) if (dp[i]) 
		lst.push_back(i);

	function<bool(int)> compute = [&](int val) {
		int x = w * val, y = f * val;
		int idx1 = --upper_bound(span(lst), y) - lst.begin();
		if (x >= sum - lst[idx1]) 
			return true;
		int idx2 = --upper_bound(span(lst), x) - lst.begin();
		if (y >= sum - lst[idx2])
			return true;
		return false;
	};

	int l = 0, r = 1e9;

	while (r - l > 1) {
		int m = (r + l) / 2;
		if (compute(m)) 
			r = m;
		else 
			l = m;
	}

	cout << r << '\n';

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