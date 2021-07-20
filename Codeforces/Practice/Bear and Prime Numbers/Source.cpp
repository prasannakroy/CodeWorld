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
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

const int sz = 1e7 + 1;

int a[sz], cnt[sz];
bool vis[sz];

void solve() {
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a[x]++;
  }
  for (int i = 2; i < sz; i++) if (!vis[i]) {
    for (int j = i; j < sz; j += i) {
      vis[j] = 1;
      cnt[i] += a[j];
    }
  }
  for (int i = 2; i < sz; i++) 
    cnt[i] += cnt[i - 1];
  int m;
  cin >> m;
  while (m--) {
    int l, r;
    cin >> l >> r;
    l = min(l - 1, sz - 1);
    r = min(r, sz - 1);
    cout << cnt[r] - cnt[l] << "\n";
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