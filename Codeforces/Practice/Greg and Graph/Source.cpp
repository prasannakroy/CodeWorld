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
  int n;
  cin >> n;
  int dist[n][n];
  for (auto &i: dist) 
    for (auto &j: i) 
      cin >> j;

  vc<int> a(n);
  for (auto &i: a) 
    cin >> i;

  bool vis[n]{};

  int res[n]{};
  for (int i = n - 1; i >= 0; i--) {
    vis[--a[i]] = 1;
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        dist[j][k] = min(dist[j][k], dist[j][a[i]] + dist[a[i]][k]);
        if (vis[j] and vis[k]) 
          res[i] += dist[j][k];
      }
    }
  }
  for (const auto &i: res) 
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