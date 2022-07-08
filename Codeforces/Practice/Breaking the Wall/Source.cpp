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
	int n;
	cin >> n;
	vc<int> a(n);
	for (auto &i: a) 
		cin >> i;
	int res(INT_MAX);
	int mn1(INT_MAX), mn2(INT_MAX);
	for (int i = 0; i < n; i++) {
		int cnt = (a[i] + 1) / 2;
		if (cnt < mn2) {
			if (cnt < mn1) {
				mn2 = mn1;
				mn1 = cnt;
			} 
			else 
				mn2 = cnt;
		}
		int l = INT_MAX, r = INT_MAX;
		if (i) {
			l = a[i - 1];
			if (l > cnt and l <= a[i]) 
				res = min(res, (a[i] + l + 2) / 3);
		}
		if (i < n - 1) {
			r = a[i + 1];
			if (r > cnt and r <= a[i]) 
				res = min(res, (a[i] + r + 2) / 3);
		}
		int mn = min({l, r, cnt});
		l -= mn;
		r -= mn;
		cnt = max(0ll, a[i] - (mn * 2));
		int sum = mn;
		if ((l <= r and l >= cnt) or (l >= r and l <= cnt)) 
			res = min(res, sum + ((l + 1) / 2));
		else if ((r <= l and r >= cnt) or (r >= l and r <= cnt)) 
			res = min(res, sum + ((r + 1) / 2));
		else 
			res = min(res, sum + ((cnt + 1) / 2));
	}
	res = min(res, mn1 + mn2);
	cout << res << '\n';
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