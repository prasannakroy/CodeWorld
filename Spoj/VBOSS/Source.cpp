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

vc<int> tr;
vc<array<int, 3>> a;

void build(int l, int r, int p = 1) {
    if (l > r) return;
    if (l == r) return void(tr[p] = a[l][2]);
    int m = (l + r) >> 1;
    build(l, m, p << 1);
    build(m + 1, r, (p << 1) | 1);
    tr[p] = max(tr[p << 1], tr[(p << 1) | 1]);
}

int query(int l, int r, int s, int e, int val, int p = 1) {
    if (l > r or s > r or e < l) return -1;
    if (l == r) return (tr[p] >= val ? l : -1);
    int m = (l + r) >> 1;
    int res = -1;
    if (tr[p << 1] >= val) res = query(l, m, s, e, val, p << 1);
    if (tr[(p << 1) | 1] >= val and res == -1) res = query(m + 1, r, s, e, val, (p << 1) | 1);
    return res;
}


void solve() {
    int n, q, cnt(1);
    cin >> n >> q;
    a.resize(n);
    tr.assign((n << 2) + 1, 0);
    map<int, int> m;
    for (auto &i: a) cin >> i[0] >> i[1] >> i[2], m[i[0]] = cnt++;
    sort(span(a), [&](array<int, 3> x, array<int, 3> y) {
        return x[1] < y[1];
    });
    build(0, n - 1);
    int dp[cnt] = {0}, boss[cnt];
    for (int i = 0; i < n; i++) {
        int idx = query(0, n - 1, i + 1, n - 1, a[i][2]);
        if (idx == -1) boss[m[a[i][0]]] = 0;
        else {
            boss[m[a[i][0]]] = a[idx][0];
            dp[m[a[idx][0]]] += dp[m[a[i][0]]] + 1;
        }
    } 
    while (q--) {
        int id;
        cin >> id;
        cout << boss[m[id]] << " " << dp[m[id]] << "\n";
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