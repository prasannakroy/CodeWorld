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

int gcd(int a, int b) {
  while (b) tie(a, b) = make_tuple(b, a % b);
  return a;
}

void solve() {
  int n, q, x, y, l, c;
  cin >> n >> q;
  vc<int> adj[n + 1];
  map<array<int, 2>, int> ld, cst;
  for (int i = 1; i < n; i++) {
    cin >> x >> y >> l >> c;
    adj[x].push_back(y);
    adj[y].push_back(x);
    ld[{min(x, y), max(x, y)}] = l;
    cst[{min(x, y), max(x, y)}] = c;
  }
  int res(0);
  function<int(int, int, int)> dfs = [&](int u, int p, int wt) {
    if (u == 1) 
      return 1ll;
    int val(0);
    for (auto &v: adj[u]) if (v != p) {
      val |= dfs(v, u, wt);
      if (val) {
        if (wt >= ld[{min(u, v), max(u, v)}]) res = gcd(res, cst[{min(u, v), max(u, v)}]);
        break;
      }
    }
    return val;
  };


  while (q--) {
    res = 0;
    cin >> x >> y;
    dfs(x, -1, y);
    cout << res << " ";
  }
  cout << "\n";
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