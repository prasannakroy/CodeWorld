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
	int n, mx(0);
	cin >> n;
	vc<array<int, 3>> a(n);
	for (auto &i: a) cin >> i[0] >> i[1] >> i[2], mx = max(mx, i[0] + i[1]);
	sort(span(a));
	vc<int> dp(mx + 1, 0);
	int j = 0;
	for (int i = 0; i <= mx; i++) {
		if (i > 0) dp[i] = max(dp[i], dp[i - 1]);
		while (j < n and a[j][0] == i) {
			dp[i + a[j][1]] = max(dp[i + a[j][1]], dp[i] + a[j][2]);
			j++;
		}
	}
	cout << dp[mx] << "\n";
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1);
  cin >> t;
  for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}