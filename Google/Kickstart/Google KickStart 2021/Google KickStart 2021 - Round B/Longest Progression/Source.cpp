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
  int n, flag(0);
  cin >> n;
  vc<int> a(n), dif(n - 1), cntl(n, 2), cntr(n, 2);
  for (auto &i: a) cin >> i;
  for (int i = 0; i < n - 1; i++) dif[i] = a[i + 1] - a[i];
  int res(2);
  for (int i = 2; i < n; i++) 
    if (dif[i - 1] == dif[i - 2]) cntl[i] = cntl[i - 1] + 1, res = max(res, cntl[i]);
  for (int i = n - 3; i >= 0; i--) 
    if (dif[i] == dif[i + 1]) cntr[i] = cntr[i + 1] + 1, res = max(res, cntr[i]);
  cntl[0] = cntr[n - 1] = 1;
  res = max({res, cntl[n - 2] + 1, cntr[1] + 1});
  for (int i = 1; i < n - 1; i++) if (dif[i] != dif[i - 1]) {
    int sum = dif[i] + dif[i - 1];
    if (sum % 2 == 0) {
      int l(INT_MAX), r(INT_MAX), f(0);
      if (i > 1) {
        f++;
        l = dif[i - 2];
      }
      if (i + 1 < n - 1) {
        f++;
        r = dif[i + 1];
      }
      if (f <= 1) {
        if (l == r) res = max(res, cntl[i - 1] + cntr[i + 1] + 1);
        else if (l != INT_MAX) {
          if (sum / 2 == dif[i - 2]) res = max(res, cntl[i - 1] + cntr[i + 1] + 1);
          else res = max({res, cntl[i - 1] + 1, cntr[i + 1] + 1});
        }
        else {
          if (sum / 2 == dif[i + 1]) res = max(res, cntl[i - 1] + cntr[i + 1] + 1);
          else res = max({res, cntl[i - 1] + 1, cntr[i + 1] + 1});
        } 
      }
      else {
        if (l == r and sum / 2 == l) res = max(res, cntl[i - 1] + cntr[i + 1] + 1);
        else if (sum / 2 == l) res = max({res, cntl[i - 1] + 2, cntr[i + 1] + 1});
        else if (sum / 2 == r) res = max({res, cntl[i - 1] + 1, cntr[i + 1] + 2});
        else res = max({res, cntl[i - 1] + 1, cntr[i + 1] + 1});
      }
    }
    else res = max({res, cntl[i - 1] + 1, cntr[i + 1] + 1});
  }
  cout << res << "\n";
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1);
  cin >> t;
  for (int i = 1; i <= t; cout << "Case #" << i << ": ", solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}