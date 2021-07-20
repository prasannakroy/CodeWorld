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
  string s;
  cin >> s;
  int n;
  cin >> n;
  vc<int> res;
  int dp[n + 1][11][11];
  memset(dp, -1, sizeof dp);

  function<int(int, int, int)> compute = [&](int prev, int dif, int cnt) {
    if (cnt == n) 
      return 1ll;

    if (~dp[cnt][prev][dif]) 
      return dp[cnt][prev][dif];

    int flag = 0;
    for (int i = 0; i < 10; i++) if (s[i] == '1' and i != prev - 1 and i >= dif) {
      flag |= compute(i + 1, i - dif + 1, cnt + 1);
      if (flag) {
        res.push_back(i + 1);
        return flag;
      }
    }
    return dp[cnt][prev][dif] = flag;
  };

  if (compute(0, 0, 0)) {
    cout << "YES\n";
    reverse(span(res));
    for (auto &i: res) 
      cout << i << " ";
  }
  else 
    cout << "NO\n";

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