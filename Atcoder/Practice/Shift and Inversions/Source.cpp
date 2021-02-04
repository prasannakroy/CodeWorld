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

vc<int> a, tr;

int query(int l, int r, int s, int e, int p = 1) {
    if (l > r or s > e or l > e or s > r) return 0;
    if (s <= l and r <= e) return tr[p];
    int m = (l + r) >> 1;
    return (query(l, m, s, e, p << 1) + query(m + 1, r, s, e, (p << 1) | 1));
}

void update(int l, int r, int idx, int val, int p = 1) {
    if (l > r) return;
    if (l == r) return void(tr[p] = val);
    int m = (l + r) >> 1;
    if (idx <= m) update(l, m, idx, val, p << 1);
    else update(m + 1, r, idx, val, (p << 1) | 1); 
    tr[p] = tr[p << 1] + tr[(p << 1) | 1];
}

void solve() {
    int n, res(0);
    cin >> n;
    a.resize(n);
    tr.assign((4 * n) + 1, 0);
    vc<int> cnt(n, 0);
    for (auto &i: a) cin >> i;
    for (int i = 0; i < n; i++) {
        res += query(0, n - 1, a[i] + 1, n - 1);
        update(0, n - 1, a[i], 1);
    }
    for (int i = 0; i < n; i++) {
        cout << res << "\n"; 
        res += query(0, n - 1, a[i] + 1, n - 1);
        res -= query(0, n - 1, 0, a[i] - 1);
        update(0, n - 1, a[i], 1, 1);
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