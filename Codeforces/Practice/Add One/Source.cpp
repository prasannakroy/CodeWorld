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

const int mx = 200001;
int dp[mx][10];
const int mod = 1e9 + 7;

void compute() {
	for (int i = 0; i < 10; i++) dp[0][i] = 1;
	for (int i = 1; i < mx; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 9) dp[i][j] = (dp[i - 1][1] + dp[i - 1][0]) % mod;
			else dp[i][j] = dp[i - 1][j + 1];
		}
	}
}

void solve() {
	int m;
	string s;
	cin >> s >> m;
	int res(0);
	for (auto &i: s) 
		(res += dp[m][i - '0']) %= mod;
	cout << res << "\n";
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  memset(dp, 0, sizeof dp);
  compute();
  int t(1);
  cin >> t;
  for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}