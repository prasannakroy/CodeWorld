/*****************************
*  Author :: Πρασαννα Κ. Ροι  *
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
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

vc<vc<int>> gph1;
vc<vc<int>> d, dp;
unordered_map<int, int> id;
int cnt(0);

void bfs(int u, int n) {
    queue<int> q;
    vc<int> dist(n + 1, -1);
    dist[u] = 0;
    q.push(u);
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (auto &i: gph1[v]) if (dist[i] == -1) {
            dist[i] = dist[v] + 1;
            q.push(i);
        }
    }
    for (int i = 1; i <= n; i++) if (id[i]) 
        d[id[u]][id[i]] = d[id[i]][id[u]] = dist[i];
}

int compute(int u, int vis, int k) {
    int res(1e18);
    if (vis == (1 << k) - 1) return 0;
    if (~dp[u][vis]) return dp[u][vis];

    dp[u][vis] = 0;
    for (int i = 0; i < k; i++) if (!(vis & (1 << i)))
        res = min(res, compute(i + 1, vis | (1 << i), k) + d[u][i + 1]);
    return dp[u][vis] = res;
}

void solve() {
    id.reserve(1 << 20);
    id.max_load_factor(0.25);
    int n, m, x, y;
    cin >> n >> m;
    gph1.assign(n + 1, vc<int>());
    for (int i = 0; i < m; i++) cin >> x >> y, gph1[x].push_back(y), gph1[y].push_back(x);
    int k, cnt(0);
    cin >> k;
    vc<int> a(k);
    d.assign(k + 1, vc<int>(k + 1, -1));
    for (auto &i: a) cin >> i, id[i] = ++cnt;
    if (k == 1) return void(cout << 1 << "\n");
    for (auto &i: a) bfs(i, n);
    for (int i = 1; i <= k; i++) 
        for (int j = 1; j <= k; j++) if (d[i][j] == -1) return void(cout << -1 << "\n");
    dp.assign(k + 1, vc<int>(1 << k, -1));
    int res(LLONG_MAX);
    for(int i = 1; i <= k; i++) 
        res = min(res, compute(i, 1 << (i - 1), k));
    cout << res + 1 << "\n";
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