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
  cin >> n >> m;
  int a[n];
  for (int i = 0; i < n; i++) 
    cin >> a[i];

  int peak[n], valley[n];
  for (int i = n - 1; i >= 0; i--) {
    peak[i] = i;
    while (i - 1 >= 0 and a[i - 1] <= a[i]) {
      i--;
      peak[i] = peak[i + 1];
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    valley[i] = i;
    while (i - 1 >= 0 and a[i] <= a[i - 1]) {
      i--;
      valley[i] = valley[i + 1];
    }
  }

  for (int i = 0; i < m; i++) {
    cin >> l >> r;
    l--;
    r--;
    if (valley[peak[l]] >= r) 
      cout << "Yes\n";
    else 
      cout << "No\n";
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