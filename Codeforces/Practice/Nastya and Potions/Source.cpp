// Author : Prasanna Kumar
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

template<typename t>
using minpq = priority_queue<t, vc<t>, greater<t>>;

template<typename t>
using maxpq = priority_queue<t>;

void solve() {
    int n, k;
    cin >> n >> k;

    vc<int> a(n);
    map<int, int> mp;
    
    for (auto &i: a) 
        cin >> i;

    for (int i = 0, x; i < k; i++) {
        cin >> x;
        mp[x - 1] = 1;
    }

    vc<vc<int>> adj(n, vc<int>());

    vc<int> res(n, INT_MAX);

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0, x; j < m; j++) {
            cin >> x;
            x--;
            adj[i].push_back(x);
        }
    }

    vc<int> vis(n, 0);


    function<void(int)> dfs = [&](int u) {
        vis[u] = 1;
        int sum = 0;
        if (adj[u].size() == 0) {
            if (mp[u]) 
                res[u] = 0;
            else
                res[u] = a[u];
            return;
        }
        for (auto &v: adj[u]) {
            if (!vis[v]) 
                dfs(v);
            sum += res[v];
        }

        sum = min(sum, a[u]);
        if (mp[u]) 
            sum = 0;
        res[u] = sum;

    };

    for (int i = 0; i < n; i++) if (!vis[i]) {
        dfs(i);
    }

    for (auto &i: res) 
        cout << i << ' ';
    cout << '\n';


}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1), st(0);
  cin >> t;
  for (int i = st; i < t + st; /*cout << "Case #" << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}