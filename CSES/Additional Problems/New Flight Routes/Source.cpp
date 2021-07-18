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

vc<vc<int>> adj[2];
vc<int> lst, vis, v;

void dfs(int u, int t, int val = 0) {
  vis[u] = 1;
  v[u] = val;
  for (auto &v: adj[t][u]) if (!vis[v]) dfs(v, t, val);
  if (t == 0) lst.push_back(u);
}

void solve() {
  int n, m;
  cin >> n >> m;
  
  adj[0].assign(n + 1, vc<int>());
  adj[1] = adj[0];
  vis.assign(n + 1, 0);
  lst.clear();
  v.assign(n + 1, 0);
  vc<array<int, 2>> edges;
  
  for (int i = 0, x, y; i < m; i++) {
    cin >> x >> y;
    edges.push_back({x, y});
    adj[0][x].push_back(y);
    adj[1][y].push_back(x);
  }

  for (int i = 1; i <= n; i++) if (!vis[i]) 
    dfs(i, 0);
  
  vis.assign(n + 1, 0);
  reverse(span(lst));
  int c(0);
  for (auto &i: lst) if (!vis[i]) {
    c++;
    dfs(i, 1, i);
  }
  if (c == 1) return void(cout << 0 << "\n");

  map<array<int, 2>, int> mp;
  vc<int> degi(n + 1, 0), dego(n + 1, 0);
  
  for (int i = 1; i <= n; i++) {
    adj[0][i].clear(); 
    adj[1][i].clear();
  }
  
  for (auto &i: edges) {
    int x = v[i[0]];
    int y = v[i[1]];
    if (x != y and !mp[{x, y}]) {
      mp[{x, y}] = 1;
      adj[0][x].push_back(y);
      dego[x]++;
      degi[y]++;
    }
  }

  vis.assign(n + 1, 0);

  vc<array<int, 2>> el;
  vc<int> lf, rt;

  function<int(int)> dfs2 = [&](int u) {
    vis[u] = 1;
    if (dego[u] == 0) 
      return u;
    int flag = -1;
    for (auto &v: adj[0][u]) if (vis[v] != 1) {
      flag = dfs2(v);
      if (~flag) return flag;
    } 
    return flag;
  };
  
  for (int i = 1; i <= n; i++) if (i == v[i] and !degi[i]) {
    int val = dfs2(i);
    if (val != -1) el.push_back({i, val});
    else rt.push_back(i);
  }
  for (int i = 1; i <= n; i++) if (i == v[i] and !dego[i] and degi[i] and !vis[i]) 
    lf.push_back(i);

  vc<array<int, 2>> edge;

  int ss = el.size();
  for (int i = 0; i < ss; i++) {
    int x = el[i][1];
    int y = el[(i + 1) % ss][0];
    degi[y]++;
    dego[x]++;
    edge.push_back({x, y});
  }

  for (int i = 0; i < min(lf.size(), rt.size()); i++) if (lf[i] != rt[i]) {
    int x = lf[i];
    int y = rt[i];
    dego[x]++;
    degi[y]++;
    edge.push_back({x, y});
  }

  int rr, ll;
  if (!edge.empty()) rr = edge[0][1], ll = edge[0][0];

  for (int i = 1; i <= n; i++) if (i == v[i]) {
    if (degi[i] == 0 and ll != i) 
      edge.push_back({ll, i});
    if (dego[i] == 0 and rr != i) 
      edge.push_back({i, rr});
  }

  cout << edge.size() << '\n';
  for (auto &i: edge) cout << i[0] << " " << i[1] << "\n";

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