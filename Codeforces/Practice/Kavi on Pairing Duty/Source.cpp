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

const int mod = 998244353;
vector<int> dp;

void compute(int sz) {
  for (int i = 1; i <= sz; i++) 
    for (int j = i; j <= sz; j += i) dp[j] += 1;
}

void solve() {
  int n;
  cin >> n;
  int sum(1);
  dp.assign(n + 1, 0);
  compute(n);
  for (int i = 2; i <= n; i++) (dp[i] += sum) %= mod, (sum += dp[i]) %= mod;
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