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
const int mod = (int)1e9 + 7;

int root(int a) {
    return a == dsu[a] ? dsu[a] : dsu[a] = root(dsu[a]);
}

bool join(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return 0;
    if (sz[a] < sz[b]) swap(a, b);
    dsu[b] = a;
    sz[a] += sz[b];
    return 1;
}

void solve() {
    int n, m, k, x, y, cnt(1);
    cin >> n >> m;
    dsu.resize(m + 2);
    sz.assign(m + 2, 1);
    iota(span(dsu), 0);
    vc<int> a(m, 0), res;
    for (int i = 0; i < n; i++) {
        cin >> k >> x;
        y = m + 1;
        if (k - 1) cin >> y;
        if (join(x, y)) res.push_back(i + 1), (cnt += cnt) %= mod; 
    }
    cout << cnt << " " << res.size() << "\n";
    for (auto &i: res) cout << i << " ";
    cout << "\n";
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