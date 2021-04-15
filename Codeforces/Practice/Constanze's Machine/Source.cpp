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

const int mod = 1e9 + 7;

void solve() {
	string s;
	cin >> s;
	int n = s.length(), res = 0;
	vc<int> dp(n + 1, 0);
	dp[0] = dp[1] = 1;
	if (s[0] == 'm' or s[0] == 'w') return void(cout << 0 << "\n");
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (s[i - 1] == 'm' or s[i - 1] == 'w') return void(cout << 0 << "\n");
		if ((s[i - 1] == 'u' or s[i - 1] == 'n') and s[i - 1] == s[i - 2]) (dp[i] += dp[i - 2]) %= mod;
	}
	cout << dp[n] << "\n";
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