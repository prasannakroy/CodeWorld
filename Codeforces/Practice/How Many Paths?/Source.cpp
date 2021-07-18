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
  int n, m;
  cin >> n >> m;
  vc<int> adj[n + 1];
  for (int i = 0, x, y; i < m; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
  }

  vc<int> vis(n + 1, 0);
  vc<int> res(n + 1, 0);

  vc<int> lst[4];

  function<void(int)> dfs1 = [&](int u) {
    vis[u] = 2;
    res[u] = 1;
    for (auto &v: adj[u]) {
      if (vis[v] == 2) 
        lst[0].push_back(v);
      else if (vis[v] == 1 and res[v] != -1) {
        lst[3].push_back(v);
        res[v] = 2;
      }
      else {
        lst[2].push_back(v);
        dfs1(v);
      }
    }
    vis[u] = 1;

  };

  function<void(int, int)> dfs2 = [&](int u, int val) {
    vis[u] = 1;
    res[u] = val;
    for (auto &v: adj[u]) if (!vis[v]) 
      dfs2(v, val);
  };

  dfs1(1);
  vis.assign(n + 1, 0);

  for (auto &i : {-1, 2, 1}) {
    for (auto &j: lst[i + 1]) if (!vis[j]) 
      dfs2(j, i);
  }

  for (int i = 1; i <= n; i++) 
    cout << res[i] << " ";
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