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
    adj[y].push_back(x);
  }
  int k;
  cin >> k;
  vc<int> path(k);
  for (auto &i: path) 
    cin >> i;

  vc<int> vis(n + 1, 0), dist(n + 1, 0);

  queue<int> q;
  q.push(path[k - 1]);
  dist[path[k - 1]] = 0;
  vis[path[k - 1]] = 1;

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &v: adj[u]) {
      if (!vis[v]) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
      if (dist[u] + 1 == dist[v]) 
        vis[v]++;
    }
  }

  int mn(0), mx(0);

  for (int i = 1; i < k; i++) {
    if (dist[path[i - 1]] == dist[path[i]] + 1) {
      if (vis[path[i - 1]] > 1) 
        mx++;
    }
    else {
      mn++;
      mx++;
    }
  }
  cout << mn << " " << mx << "\n";
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