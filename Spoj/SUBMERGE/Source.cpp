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

vc<vc<int>> adj;
vc<int> tin, low, sz;
int timer;

int dfs(int u, int n) {
  tin[u] = ++timer;
  low[u] = tin[u];
  int cnt(0), res(0);
  sz[u] = 1;
  for (auto &v: adj[u]) {
    if (tin[v]) 
      low[u] = min(low[u], tin[v]);
    else {
      res += dfs(v, n);
      sz[u] += sz[v];
      low[u] = min(low[u], low[v]);
      if (low[v] > tin[u]) 
        cnt++;
      else if (low[v] == tin[u]) 
        if (sz[v] < n - 1) cnt++;
    }
  }
  res += (cnt > 0);
  return res;
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int n, m;
  while (cin >> n >> m and (n != 0 or m != 0)) {
    adj.assign(n + 1, vc<int>());
    tin.assign(n + 1, 0);
    low.assign(n + 1, 0);
    sz.assign(n + 1, 0);
    timer = 0;

    for (int i = 0, x, y; i < m; i++) {
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }

    cout << dfs(1, n) << '\n';
  }

  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}