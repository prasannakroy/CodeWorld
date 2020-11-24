/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) a.begin(), a.end()
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    
    vector<int> dsu(n + 1, 0), sz(n + 1, 1);
    iota(span(dsu), 0);
    
    function<int(int)> root = [&](int x) {
        return dsu[x] == x ? dsu[x] : dsu[x] = root(dsu[x]);
    };
    
    function<void(int, int)> join = [&](int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        dsu[y] = x;
        sz[x] += sz[y];
    };
    int x, y;
    while (m--) cin >> x >> y, join(x, y);
    int res(0);
    for (int i = 1; i <= n; i++) {
        if (dsu[i] == i) {
            res += a;
            res += ((sz[i] - 1) * min(b, a));
        }
    }
    cout << res << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    // #ifndef ONLINE_JUDGE 
    //     __AnAkLuSmOs    
    // #endif

    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}