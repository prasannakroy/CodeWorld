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
    if (a == b) return 0;
    if (sz[a] < sz[b]) swap(a, b);
    dsu[b] = a;
    int res = sz[a] * sz[b];
    sz[a] += sz[b];
    return res;
}

void solve() {
    int n, q;
    cin >> n >> q;
    dsu.resize(n + 1);
    sz.assign(n + 1, 1);
    iota(span(dsu), 0);
    vc<array<int, 3>> a(n);
    vc<int> res, idx;
    res.push_back(0), idx.push_back(0);
    for (int i = 1; i < n; i++) cin >> a[i][1] >> a[i][2] >> a[i][0];
    sort(span(a));
    for (int i = 1; i < n; i++) 
        idx.push_back(a[i][0]), res.push_back(join(a[i][1], a[i][2]));
    for (int i = 1; i < n; i++) res[i] += res[i - 1];
    while (q--) {
        int l, r;
        cin >> l >> r;
        int idxl = upper_bound(span(idx), l - 1) - begin(idx) - 1;
        int idxr = upper_bound(span(idx), r) - begin(idx) - 1;
        cout << res[idxr] - res[idxl] << "\n";
    }
}

signed main() {
    // auto start = high_resolution_clock::now();
    // #ifndef ONLINE_JUDGE 
    //     __AnAkLuSmOs    
    // #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}