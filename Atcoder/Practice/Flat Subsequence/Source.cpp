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

class SegmentTree {
public:
    int n;
    vc<int> tr;
    SegmentTree(int n) : n(n) {
        tr.assign(4 * n + 1, 0);
    }

    void update(int idx, int val, int l, int r, int p = 1) {
        if (l > r) return;
        if (l == r) return void(tr[p] = val);
        int m = (l + r) >> 1;
        if (idx <= m) update(idx, val, l, m, p << 1);
        else update(idx, val, m + 1, r, (p << 1) | 1);
        tr[p] = max(tr[p << 1], tr[(p << 1) | 1]);
    }

    int query(int s, int e, int l, int r, int p = 1) {
        if (s > r or e < l or s > e or l > r) return INT_MIN;
        if (s <= l and e >= r) return tr[p];
        int m = (l + r) >> 1;
        return max(query(s, e, l, m, p << 1), query(s, e, m + 1, r, (p << 1) | 1));
    }
};

void solve() {
    int n, k, mx(0);
    cin >> n >> k;
    vc<int> a(n);
    for (auto &i: a) cin >> i, mx = max(mx, i);
    SegmentTree tree(mx + 1);
    for (int i = 0; i < n; i++) 
        tree.update(a[i], tree.query(max(0ll, a[i] - k), min(mx, a[i] + k), 0, mx) + 1, 0, mx);
    cout << tree.query(0, mx, 0, mx) << "\n";
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