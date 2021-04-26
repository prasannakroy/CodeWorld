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
	int n, sum(0);
	cin >> n;
	vc<int> a(n);
	for (auto &i: a) cin >> i, sum += i;
	if (sum & 1) return void(cout << 0 << "\n");
	
	int dp[n + 1][sum + 1];
	memset(dp, 0, sizeof dp);
	for (int i = 0; i <= n; i++) dp[i][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (a[i - 1] > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] |= dp[i - 1][j] | dp[i - 1][j - a[i - 1]];
		}
	}
	if (!dp[n][sum / 2]) return void(cout << 0 << "\n");
	
	cout << 1 << "\n";
	while (true) {
		for (int i = 0; i < n; i++) {
			if (a[i] & 1) return void(cout << i + 1 << "\n");
			a[i] >>= 1;
		}
	}
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