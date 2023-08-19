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
	int n, m, d;
	cin >> n >> m >> d;
	
	vc<int> a(m);
	for (auto &i: a) 
		cin >> i;

	vc<int> suf(m);

	int r = n + 1;

	for (int i = m - 1; i >= 0; i--) {
		int dif = (r - 1 - a[i]) / d;
		suf[i] = dif + 1;
		r = a[i];
		if (i < m - 1) 
			suf[i] += suf[i + 1];
	}

	int res(INT_MAX), cnt(0);

	int pref = 1, l = 1;
	for (int i = 0; i < m; i++) {
		int lsum(pref), rsum(0);
		if (i < m - 1) {
			rsum = suf[i + 1];
			lsum += ((a[i + 1] - 1 - l) / d);
		} else {
			lsum += ((n - l) / d);
		} 

		if (lsum + rsum < res) {
			res = lsum + rsum;
			cnt = 1;
		} else if (lsum + rsum == res) 
			cnt++;

		if (a[i] == 1) 
			continue;

		int sum = ((a[i] - l) / d);
		if (l + (sum * d) != a[i]) 
			sum++;
		pref += sum;
		l = a[i];
	}
	cout << res << ' ' << cnt << '\n';

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