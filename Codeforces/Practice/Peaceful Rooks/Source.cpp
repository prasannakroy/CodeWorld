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

vc<int> dsu, sz;

int root(int a) {
    return a == dsu[a] ? dsu[a] : dsu[a] = root(dsu[a]);
}

int join(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return 2;
    if (sz[a] < sz[b]) swap(a, b);
    dsu[b] = a, sz[a] += sz[b];
    return 1;
}

void solve() {
    int n, m, x, y, res(0);
    cin >> n >> m;
    dsu.resize(n + 1);
    iota(span(dsu), 0);
    sz.assign(n + 1, 1);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        if (x == y) continue;
        res += join(x, y);
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
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}