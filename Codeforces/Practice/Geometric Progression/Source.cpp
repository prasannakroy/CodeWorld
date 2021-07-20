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

void solve() {
  int n, k;
  cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) 
    cin >> a[i];
  int dp[n + 1][3];
  memset(dp, 0, sizeof dp);
  map<int, int> m;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[m[a[i]]][0] + 1;
    dp[i][1] = dp[m[a[i]]][1];
    if (a[i] % k == 0) {
      int d = a[i] / k;
      dp[i][1] += dp[m[d]][0];
      dp[i][2] += dp[m[d]][1];
    }
    m[a[i]] = i;
  }
  int res(0);
  for (int i = 1; i <= n; i++) 
    res += dp[i][2];
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