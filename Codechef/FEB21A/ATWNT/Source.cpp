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
// #define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

vc<vc<int>> tr;
vc<int> rr;
vc<unordered_map<int, int>> mp;

vc<int> dsu;

int gcd(int a, int b) {
    while (b) tie(a, b) = make_tuple(b, a % b);
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int root(int a) {
    return dsu[a] == a? dsu[a] : dsu[a] = root(dsu[a]);
}

int dfs(int u) {
    if (!tr[u].size()) {
        mp[u][1]++;
        return 1;
    }
    int sz = tr[u].size(), r = 1;
    for (auto &v: tr[u]) {
        r = lcm(r, dfs(v));
        if (sz != 1) for (auto &[x, y] : mp[root(v)]) mp[u][x * sz] += y;
        else dsu[u] = v;
    }
    return rr[u] = r * sz;
}

void solve() {
    int n, x;
    cin >> n;
    rr.assign(n + 1, 1);
    dsu.resize(n + 1);
    iota(span(dsu), 0);
    tr.assign(n + 1, vc<int>());
    for (int i = 1; i < n; i++) {
        cin >> x;
        tr[x].push_back(i + 1);
    }
    mp.resize(n + 1);
    dfs(1);
    int q;
    cin >> q;
    while (q--) {
        int idx, val, sum(0);
        cin >> idx >> val;
        if (val % rr[idx] == 0) {
            cout << 0 << "\n";
            continue;
        }
        for (auto &[x, y]: mp[root(idx)]) if (val % x == 0) 
            sum += ((val / x) * y);
        cout << val - sum << "\n";
    }
}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs
    
    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}