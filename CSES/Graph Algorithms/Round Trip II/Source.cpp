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
  int n, m, x, y;
  cin >> n >> m;
  vector<vector<int>> gph(n + 1);
  for (int i = 0; i < m; i++) cin >> x >> y, gph[x].push_back(y);
  vector<int> vis(n + 1, 0), check(n + 1, 0), parent(n + 1, 0), res;
 
  function<bool(int, int)> dfs = [&](int u, int p) {
    check[u] = 1;
    parent[u] = p;
    bool flag = 0;
    for (auto &v: gph[u]) {
      if (check[v] == 1) {
        res.push_back(v);
        while (u != v) res.push_back(u), u = parent[u];
        res.push_back(u);
        return true;
      }
      else if (!check[v]) flag |= dfs(v, u);
      if (flag) return flag;
    }
    check[u] = 2;
    parent[u] = 0;
    return flag;
  };
  bool flag(0);
  for (int i = 1; i <= n; i++) if (!check[i]) {
    flag |= dfs(i, 0);
    if (flag) break;
  }
  if (flag) {
      cout << res.size() << "\n";
      reverse(span(res));
      for (auto &i: res) cout << i << " ";
      cout << "\n";
  }
  else cout << "IMPOSSIBLE\n";
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