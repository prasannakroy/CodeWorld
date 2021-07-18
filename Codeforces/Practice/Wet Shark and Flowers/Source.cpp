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
  int n, p;
  cin >> n >> p;
  vc<int> a(n), t(n);
  for (int i = 0, l, r; i < n; i++) {
    cin >> l >> r;
    a[i] = r - l + 1;
    t[i] = (r / p) - ((l - 1) / p);
  }

  double res = 0.0;
  for (int i = 0, j = 1; i < n; i++, j++) {
    if (j >= n) 
      j -= n;
    double r = ((double)t[i] / a[i]);
    r += ((double)t[j] / a[j]);
    r -= ((double)(t[i] * t[j]) / (a[i] * a[j]));
    r *= 2000;
    res += r;
  }
  cout << fixed << setprecision(8) << res << "\n";
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