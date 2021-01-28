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

vc<int> dsu, sz, v;

int root(int a) {
    return a == dsu[a] ? dsu[a] : dsu[a] = root(dsu[a]);
}

void join(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    dsu[b] = a;
    sz[a] += sz[b];
    v[a] |= v[b];
}

void solve() {
    int n, k, x, res(0);
    cin >> n >> k;
    vc<array<int, 3>> a(n - 1);
    dsu.resize(n);
    sz.assign(n, 1);
    iota(span(dsu), 0);
    for (auto &i: a) cin >> i[0] >> i[1] >> i[2];
    v.assign(n, 0);
    for (int i = 0; i < k; i++) cin >> x, v[x] = 1;
    sort(span(a), [&](array<int, 3> p, array<int, 3> q) {
        return p[2] > q[2];
    });
    for (auto &i: a) {
        if (v[root(i[0])] == v[root(i[1])] and v[root(i[1])]) res += i[2];
        else join(i[0], i[1]);
    }
    cout << res << "\n";
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