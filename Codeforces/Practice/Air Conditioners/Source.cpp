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
  vc<array<int, 2>> a(k);
  for (auto &i: a) 
    cin >> i[0];
  for (auto &i: a) 
    cin >> i[1];
  sort(span(a));
  vc<int> mnp(k), mns(k);
  for (int i = 0; i < k; i++) {
    mnp[i] = a[i][1] - a[i][0];
    if (i) 
      mnp[i] = min(mnp[i], mnp[i - 1]);
  }
  for (int i = k - 1; i >= 0; i--) {
    mns[i] = a[i][1] + a[i][0];
    if (i < k - 1) 
      mns[i] = min(mns[i], mns[i + 1]);
  }

  int l = -1, r = 0;
  vc<int> res(n, INT_MAX);
  for (int i = 0; i < n; i++) {
    while (l + 1 < k and a[l + 1][0] <= i + 1) 
      l++;
    r = l + 1;
    if (l >= 0) 
      res[i] = min(res[i], mnp[l] + i + 1);
    if (r < k) 
      res[i] = min(res[i], mns[r] - i - 1);
  }
  for (auto &i: res) 
    cout << i << " ";
  cout << "\n";
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