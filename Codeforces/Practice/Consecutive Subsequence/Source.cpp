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
  int n;
  cin >> n;
  int a[n + 1];
  map<int, int> m;
  for (int i = 1; i <= n; i++) 
    cin >> a[i];

  int dp[n + 1]{};
  int res(0), val;
  for (int i = 1; i <= n; i++) {
    m[a[i]] = i;
    dp[i] = dp[m[a[i] - 1]] + 1;
    if (dp[i] > res) {
      res = dp[i];
      val = a[i];
    }
  }
  cout << res << "\n";
  int lst[res];
  for (int i = n; i > 0; i--) if (a[i] == val) {
    lst[--res] = i;
    val--;
  }
  for (auto &i: lst) 
    cout << i << " ";
  cout << "\n";
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