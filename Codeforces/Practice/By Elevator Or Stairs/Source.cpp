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

const int mx = 1e9;

void solve() {
  int n, c;
  cin >> n >> c;
  vc<int> a(n - 1), b(n - 1);
  for (auto &i: a) 
    cin >> i;
  for (auto &i: b) 
    cin >> i;
  int dp[n][2];
  dp[0][0] = 0;
  dp[0][1] = c;

  for (int i = 1; i < n; i++) {
    dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + a[i - 1];
    dp[i][1] = min(dp[i - 1][0] + c, dp[i - 1][1]) + b[i - 1];
  }

  for (int i = 0; i < n; i++) 
    cout << min(dp[i][0], dp[i][1]) << " ";
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