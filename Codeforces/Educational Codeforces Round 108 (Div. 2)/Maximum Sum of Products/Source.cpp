/*****************************
*  Author :: Πρασαννα Κ. Ροι *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

void solve() {
	int n;
	cin >> n;
	vc<int> a(n), b(n);
	for (auto &i: a) cin >> i;
	for (auto &i: b) cin >> i;
	vc<vc<int>> dp(n, vc<int>(n, 0));
	for (int i = 0; i < n; i++) {
		int x = i - 1, y = i + 1;
		dp[i][i] = a[i] * b[i];
		if (i + 1 < n) dp[i][i + 1] = (a[i] * b[i + 1]) + (a[i + 1] * b[i]);
		for (; x >= 0 and y < n; x--, y++) 
			dp[x][y] = dp[x + 1][y - 1] + (a[x] * b[y]) + (a[y] * b[x]);
		x = i - 1, y = i + 2;
		for (; x >= 0 and y < n; x--, y++) 
			dp[x][y] = dp[x + 1][y - 1] + (a[x] * b[y]) + (a[y] * b[x]);
	}

	vc<int> prod(n);
	for (int i = 0; i < n; i++) {
		prod[i] = a[i] * b[i];
		if (i) prod[i] += prod[i - 1];
	}
	
	int res = prod[n - 1];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int sum = dp[i][j];
			if (i - 1 >= 0) sum += prod[i - 1];
			sum += prod[n - 1] - prod[j];
			res = max(res, sum);
		}
	}
	cout << res << "\n";
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1);
  // cin >> t;
  for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}