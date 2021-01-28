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
    return dsu[a] == a? dsu[a] : dsu[a] = root(dsu[a]);
}

void join(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    dsu[b] = a;
}

void solve() {
    int n, p, x, y;
    cin >> n >> p;
    dsu.resize(n, 0);
    sz.assign(n, 1);
    iota(span(dsu), 0);
    for (int i = 0; i < p; i++) cin >> x >> y, join(x, y);
    int sze(0), res(0);
    for (int i = 0; i < n; i++) if (dsu[i] == i) res += (sze * sz[i]), sze += sz[i];
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