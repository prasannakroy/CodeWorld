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
  int n, w, h;
  cin >> n >> w >> h;
  vc<array<int, 3>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i][0] >> a[i][1];
    a[i][2] = i;
  }

  sort(span(a));

  int dp[n + 1]{};
  dp[0] = 0;

  int parent[n + 1];
  memset(parent, -1, sizeof parent);
  int res(0), idx(-1);

  for (int i = 1; i <= n; i++) {
    if (a[i][0] <= w or a[i][1] <= h) {
      dp[i] = 0;
      continue;
    }
    dp[i] = 1;
    for (int j = i - 1; j > 0; j--) if (a[j][0] < a[i][0] and a[j][1] < a[i][1] and dp[j]) {
      if (dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
        parent[i] = j;
      }
    }
    if (dp[i] > res) {
      res = dp[i];
      idx = i;
    }
  }

  cout << res << "\n";
  int ar[res];
  while (idx > 0) {
    ar[--res] = a[idx][2];
    idx = parent[idx];
  }
  for (auto &i: ar) 
    cout << i << " ";
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