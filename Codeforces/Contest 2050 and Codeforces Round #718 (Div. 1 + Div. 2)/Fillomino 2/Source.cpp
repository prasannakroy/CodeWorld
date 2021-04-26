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

void solve() {
  int n;
  cin >> n;
  int a[n][n], res[n][n];
  memset(a, -1, sizeof a);
  for (int i = 0; i < n; i++) cin >> a[i][i], res[i][i] = a[i][i];
  int cnt(0);
  while (true) {
    bool flag = 1;
    for (int i = 0; i + cnt < n; i++) if (a[i + cnt][i] > 1) {
      flag = 0;
      if (i - 1 >= 0 and a[i + cnt][i - 1] == -1) 
        a[i + cnt][i - 1] = a[i + cnt][i] - 1, res[i + cnt][i - 1] = res[i + cnt][i];
      else if (i + cnt + 1 < n and a[i + cnt + 1][i] == -1) 
        a[i + cnt + 1][i] = a[i + cnt][i] - 1, res[i + cnt + 1][i] = res[i + cnt][i];
      else return void(cout << -1 << "\n");
    }
    if (flag) break;
    cnt++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) cout << res[i][j] << " ";
    cout << "\n";
  }
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