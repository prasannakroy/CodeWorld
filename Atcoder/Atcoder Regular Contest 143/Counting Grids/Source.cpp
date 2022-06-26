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

const int mod = 998244353;

int factorial(int n) {
	if (n <= 0) 
		return 1;
	int res(1);
	while (n) 
		(res *= n--) %= mod;
	return res;
}

void solve() {
	int n;
	cin >> n;
	int res(0);
	res = factorial(n * n);
	int cnt = (n * n) - ((2 * n) - 1);
	cnt = factorial(cnt);
	for (int i = 1; i <= n * n; i++) {
		if (i < n or (n * n) - i < n - 1) 
			continue;
		int a(1);
		int b(1);
		for (int j = 1, val = i - 1; j < n; j++, val--) 
			(a *= val) %= mod;
		for (int j = 1, val = (n * n) - i; j < n; j++, val--) 
			(b *= val) %= mod;
		(a *= b) %= mod;
		(a *= (n * n)) %= mod;
		(a *= cnt) %= mod;
		res -= a;
		(res += mod) %= mod;
	}
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