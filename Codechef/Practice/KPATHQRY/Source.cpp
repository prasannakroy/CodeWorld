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

vc<vc<int>> adj, parent;
vc<int> in, out, level;
int timer, l;

void dfs(int u, int p, int lvl) {
  parent[u][0] = p;
  in[u] = ++timer;
  level[u] = lvl;
  for (int i = 1; i <= l; i++) 
    parent[u][i] = parent[parent[u][i - 1]][i - 1];
  for (auto &v: adj[u]) if (v != p) 
    dfs(v, u, lvl + 1);
  out[u] = ++timer;
}

int isAncestor(int u, int v) {
  return (in[u] <= in[v] and out[u] >= out[v]);
}

int lca(int u, int v) {
  if (isAncestor(u, v)) return u;
  if (isAncestor(v, u)) return v;
  for (int i = l; i >= 0; i--) 
    if (!isAncestor(parent[u][i], v)) 
      u = parent[u][i];
  return parent[u][0];
}

void solve() {
  adj.clear();
  int n;
  cin >> n;

  timer = 0;
  l = ceil(log2(n));
  adj.assign(n + 1, vc<int>());
  in.assign(n + 1, 0);
  out.assign(n + 1, 0);
  level.assign(n + 1, 0);
  parent.assign(n + 1, vc<int>(l + 1, 0));
  
  for (int i = 1, x, y; i < n; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  dfs(1, 1, 0);

  int q;
  cin >> q;

  while (q--) {
    int k;
    cin >> k;
    vc<int> a(k);
    vc<int> vis(k, 0);
    for (auto &i: a) 
      cin >> i;
    sort(span(a), [&](int x, int y){
      return level[x] == level[y] ? x < y : level[x] > level[y];
    });

    int root = a[0];
    for (int i = 1; i < k; i++) 
      root = lca(root, a[i]);
    function<int()> check = [&]() {
      int rt = -1;
      for (int i = 0; i < k; i++) {
        if (rt == -1) {
          if (!vis[i]) {
            rt = a[i];
            vis[i] = 1;
          }
          continue;
        }
untitled        if (isAncestor(a[i], rt)) {
          rt = a[i];
          if (vis[i] and i != k - 1) 
            return 0;
          vis[i] = 1;
        }
        else if (lca(rt, a[i]) != root) 
          return 0;
      }
      return 1;
    };

    int rt = check();
    rt &= check();

    for (int i = 0; i < k; i++) 
      rt &= vis[i];

    if (rt) cout << "YES\n";
    else cout << "NO\n";
  }

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