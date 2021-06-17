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
  vc<array<int, 3>> a(n);
  for (int i = 0; i < n; a[i - 1][2] = i++) 
    cin >> a[i][0] >> a[i][1];
  sort(span(a), [&](array<int, 3> x, array<int, 3> y) {
    return x[1] == y[1] ? x[0] < y[0] : x[1] > y[1];
  });
  auto b = a;
  vc<bool> res1(n, 0), res2(n, 0);
  for (int i = n - 2; i >= 0; i--) {
    if (a[i + 1][0] >= a[i][0]) res1[a[i][2]] = 1;
    a[i][0] = max(a[i + 1][0], a[i][0]);
  }

  for (int i = 1; i < n; i++) {
    if (b[i - 1][0] <= b[i][0]) res2[b[i][2]] = 1;
    b[i][0] = min(b[i][0], b[i - 1][0]);
  }
  for (int i = 0; i < n; i++) cout << res1[i] << " ";
  cout << "\n";
  for (int i = 0; i < n; i++) cout << res2[i] << " ";
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