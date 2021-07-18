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
vc<int> sz, lst, tr;

int dfs(int u, int p) {
  sz[u] = 1;
  lst.push_back(u);
  for (auto &v: adj[u]) if (v != p) 
    sz[u] += dfs(v, u);
  return sz[u];
}

void update(int idx, int val, int n) {
  for (; idx <= n; idx |= (idx + 1)) 
    tr[idx] += val;
}

int query(int idx) {
  int sum(0);
  for (; idx >= 0; idx = (idx & (idx + 1)) - 1) sum += tr[idx];
  return sum;
}

void solve() {
  int n, q;
  cin >> n >> q;
  vc<int> a(n + 1);
  adj.assign(n + 1, vc<int>());
  sz.assign(n + 1, 0);
  tr.assign(n + 1, 0);
  lst.push_back(0);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1, x, y; i < n; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  dfs(1, 0);

  vc<int> idx(n + 1);
  for (int i = 1; i <= n; i++) {
    idx[lst[i]] = i;
    update(i, a[lst[i]], n);
  }

  while (q--) {
    char x;
    cin >> x;
    if (x == 'Q') {
      int node;
      cin >> node;
      int l = idx[node];
      int r = l + sz[node] - 1;
      cout << query(r) - query(l - 1) << "\n";
    }
    else {
      int node, val;
      cin >> node >> val;
      update(idx[node], val - a[node], n);
      a[node] = val;
    }
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