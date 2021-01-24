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
#define lc(a) (a << 1)
#define rc(a) ((a << 1) | 1)


template<typename t>
using vc = vector<t>;

vc<array<int, 2>> tr;
vc<int> a;

auto join(array<int, 2> x, array<int, 2> y) {
    x[0] = min(x[0], y[0]);
    x[1] = max(x[1], y[1]);
    return x;
}

void build(int l, int r, int p = 1) {
    if (l > r) return;
    if (l == r) return void(tr[p] = {a[l], a[r]});
    int m = (l + r) >> 1;
    build(l, m, lc(p));
    build(m + 1, r, rc(p));
    tr[p] = join(tr[lc(p)], tr[rc(p)]);
}

auto query(int l, int r, int s, int e, int p = 1) {
    array<int, 2> res = {INT_MAX, INT_MIN};
    if (l > r or r < s or e < l or s > e) return res;
    if (s <= l and e >= r) 
        return tr[p];
    int m = (l + r) >> 1;
    res = join(query(l, m, s, e, lc(p)), query(m + 1, r, s, e, rc(p)));
    return res;
}

void solve() {
    int n, m, cnt(0);
    cin >> n >> m;
    tr.assign(4 * (n + 1), {INT_MAX, INT_MIN});
    string s;
    cin >> s;
    a.clear();
    a.push_back(0);
    for (auto &i: s) {
        if (i == '+') cnt++;
        else cnt--;
        a.push_back(cnt);
    }
    build(0, n);
    while (m--) {
        int l, r;
        cin >> l >> r;
        int sum = a[r] - a[l - 1];
        array<int, 2> res = {INT_MAX, INT_MIN};
        if (r < n) res = query(0, n, r + 1, n);
        if (res[0] != INT_MAX) {
            res[0] -= sum;
            res[1] -= sum;
        }
        if (l > 1) res = join(res, query(0, n, 1, l - 1));
        if (res[0] > res[1]) cout << 1 << "\n";
        else if (res[0] * res[1] <= 0) cout << abs(res[0]) + abs(res[1]) + 1 << "\n";
        else cout << max(abs(res[0]), abs(res[1])) + 1 << "\n";
    }
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