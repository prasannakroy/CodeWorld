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
  int n, m, l, r;
  cin >> n >> m >> l >> r;
  vc<string> a(n);
  vc<int> cnt(m + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < m; j++) if (a[i][j] == '#') 
      cnt[j + 1]++;
  }

  for (int i = 1; i <= m; i++) 
    cnt[i] += cnt[i - 1];


  int dp[m + 1][2];
  dp[0][0] = 0;
  dp[0][1] = 0;

  for (int i = 1; i <= m; i++) {
    dp[i][0] = INT_MAX;
    dp[i][1] = INT_MAX;
    for (int j = l; j <= r; j++) if (l <= i) {
      dp[i][0] = min(dp[i][0], dp[i - j][1] + cnt[i] - cnt[i - j]);
      int req = n * j;
      req -= cnt[i] - cnt[i - j];
      dp[i][1] = min(dp[i][1], dp[i - j][0] + req);
    }
  }

  cout << min(dp[m][0], dp[m][1]) << "\n";

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