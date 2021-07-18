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
  int n, wt;
  cin >> n >> wt;
  vc<int> a(n);
  vc<array<int, 2>> dp((1 << n), {-1, -1});
  for (auto &i: a) cin >> i;
 
  function<array<int, 2>(int)> compute = [&](int val) {
    if (!val) return array<int, 2>({1, 0});
    if (~dp[val][0]) return dp[val];

    int res = INT_MAX;
    int mn = INT_MAX;

    for (int i = 0; i < n; i++) if (val & (1 << i)) {
      val ^= (1 << i);
      auto r = compute(val);
      val ^= (1 << i);
      if (a[i] + r[1] <= wt) r[1] += a[i];
      else {
        r[0]++;
        r[1] = min(r[1], a[i]);
      }
      if (r[0] < res or (r[0] == res and r[1] < mn)) {
        res = r[0];
        mn = r[1];
      }
    }
    return dp[val] = array<int, 2>({res, mn});
  };

  auto res = compute((1 << n) - 1);
  cout << res[0] << '\n';
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