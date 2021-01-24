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

const int mod = 1e9 + 7;

template<typename t>
class BIT {
public:
    t n;
    vc<t> tr;

    BIT(t n) : n(n) {
        tr.assign(n, 0);
    }

    void update(t idx, t val) {
        for (; idx < n; idx |= (idx + 1)) (tr[idx] += val) %= mod;
    }

    int query(t r, t l = -1) {
        if (~l) return query(r) - query(l - 1);
        t sum(0);
        for (; r >= 0; r = (r & (r + 1)) - 1) (sum += tr[r]) %= mod;
        return sum;
    }
};

void solve() {
    int n, k, mx(0);
    cin >> n >> k;
    vc<array<int, 2>> a(n);
    for (auto &i: a) cin >> i[0] >> i[1], i[1]--, mx = max(mx, i[0]);
    vector<BIT<int>> tree(128, BIT<int>(mx + 1));
    tree[0].update(0, 1);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < (1 << k); j++) 
            if (j & (1 << a[i][1]))
                tree[j].update(a[i][0], (tree[j].query(a[i][0] - 1) + tree[j ^ (1 << a[i][1])].query(a[i][0] - 1)) % mod);
    cout << tree[(1 << k) - 1].query(mx) << "\n";
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
