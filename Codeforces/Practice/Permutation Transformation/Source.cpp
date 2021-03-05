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

vc<int> tr, a;

int merge(int x, int y) {
    if (x == -1) return y;
    else if (y == -1) return x;
    if (a[x] > a[y]) return x;
    else return y;
}

void build(int l, int r, int p = 1) {
    if (l > r) return;
    if (l == r) return void(tr[p] = l);
    int m = (l + r) >> 1;
    build(l, m, p << 1);
    build(m + 1, r, (p << 1) | 1);
    tr[p] = merge(tr[p << 1], tr[(p << 1) | 1]);
}

int query(int l, int r, int s, int e, int p = 1) {
    if (l > r or s > e or l > e or s > r) return -1;
    if (s <= l and e >= r) return tr[p];
    int m = (l + r) >> 1;
    return merge(query(l, m, s, e, p << 1), query(m + 1, r, s, e, (p << 1) | 1));
}

void solve() {
    int n;
    cin >> n;
    a.assign(n, 0);
    tr.assign(4 * n + 1, 0);
    for (auto &i: a) cin >> i;
    build(0, n - 1);
    vc<int> res(n + 1);
    
    function<void(int, int, int)> compute = [&](int l, int r, int d) {
        if (l > r) return;
        if (l == r) return void(res[a[l]] = d);

        int idx = query(0, n - 1, l, r);
        res[a[idx]] = d;
        compute(l, idx - 1, d + 1);
        compute(idx + 1, r, d + 1);
    };

    compute(0, n - 1, 0);
    for (auto &i: a) cout << res[i] << " ";
    cout << "\n";
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