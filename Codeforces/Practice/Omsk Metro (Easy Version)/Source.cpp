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

template<typename t>
using minpq = priority_queue<t, vc<t>, greater<t>>;

template<typename t>
using maxpq = priority_queue<t>;

void solve() {
    int n;
    cin >> n;

    int len = 1;
    vc<vc<array<int, 2>>> adj(len);
    vc<array<int, 3>> a;
    
    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        if (x == '+') {
            int u, w;
            cin >> u >> w;
            u--;
            adj[u].push_back({len, w});
            adj.push_back({});
            len++;
        } else {
            int u, v, k;
            cin >> u >> v >> k;
            a.push_back({--u, --v, k});
        }
    }

    vc<array<int, 4>> lst(len, {INT_MIN, INT_MAX, 0, 0});

    lst[0][0] = 1;
    lst[0][1] = 0;
    lst[0][2] = 1;
    lst[0][3] = 0;

    function<void(int)> dfs = [&](int u) {
        for (auto &[v, w]: adj[u]) {
            lst[v][2] = max(0ll, lst[u][2] + w);
            lst[v][3] = min(0ll, lst[u][3] + w);
            lst[v][0] = max(lst[v][2], lst[u][0]);
            lst[v][1] = min(lst[v][3], lst[u][1]);
            dfs(v);
        }
    };

    dfs(0);
    
    for (auto &[u, v, k]: a) {
        if (k >= lst[v][1] and k <= lst[v][0]) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
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