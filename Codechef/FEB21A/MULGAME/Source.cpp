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

void solve() {
    int n, q, m;
    cin >> n >> q >> m;
    vc<int> a(n), cnt(m + 1, 0);
    for (auto &i: a) cin >> i;
    map<array<int, 2>, int> mp;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        mp[{x, y}]++;
    }
    for (auto &[x, y]: mp) {
        int l = a[x[0] - 1];
        int r = l + a[x[1] - 1];
        int dif = r - l;
        while (l <= m) {
            cnt[l] += y;
            if (r <= m) cnt[r] -= y;
            l = r + a[x[0] - 1];
            r = l + dif;
        }
    }
    int val = 0, res = 0;
    for (int i = 1; i <= m; i++) {
        val += cnt[i];
        res = max(res, val);
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