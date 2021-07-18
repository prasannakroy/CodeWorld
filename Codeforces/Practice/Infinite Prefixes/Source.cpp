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
  string s;
  cin >> s;
  int sum[n + 1]{};
  for (int i = 1; i <= n; i++) 
    sum[i] = sum[i - 1] + (s[i - 1] == '1' ? -1 : 1);

  int res(0);
  for (int i = 0; i <= n; i++) {
    if (sum[i] == k) 
      if (sum[n] == 0)
        return void(cout << -1 << "\n");
    int d = k - sum[i];
    if (i != n and sum[n] and d % sum[n] == 0 and d / sum[n] >= 0) 
      res++;
  }
  cout << res << "\n";
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1);
  cin >> t;
  for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}