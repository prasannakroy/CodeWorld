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

void build(int l, int r, int p = 1) {
    if (l > r) return;
    if (l == r) return void(tr[p] = 1);
    int m = (l + r) >> 1;
    build(l, m, p << 1);
    build(m + 1, r, (p << 1) | 1);
    tr[p] = tr[p << 1] + tr[(p << 1) | 1];
}

void update(int idx, int l, int r, int p = 1) {
    if (l > r or idx > r or idx < l) return;
    if (l == r) return void(tr[p] = 0);
    int m = (l + r) >> 1;
    if (idx <= m) update(idx, l, m, p << 1);
    else update(idx, m + 1, r, (p << 1) | 1);
    tr[p] = tr[p << 1] + tr[(p << 1) | 1];
}

int query(int k, int l, int r, int p = 1) {
    if (l > r) return -1;
    if (l == r) {
        if (tr[p] == 1) return l;
        else return -1;
    }
    int m = (l + r) >> 1;
    if (tr[p << 1] < k) return query(k - tr[p << 1], m + 1, r, (p << 1) | 1);
    else return query(k, l, m, p << 1);
}

void solve() {
    int n, k;
    cin >> n >> k;
    k++;
    int cnt(n);
    tr.assign(4 * n + 1, 0);
    build(0, n - 1);
    int a = 0;
    a += k;
    if (a > cnt) a %= cnt;
    if (!a) a = min(cnt, k);
    vc<int> res;
    while (cnt) {
        int idx = query(a, 0, n - 1);
        update(idx, 0, n - 1);
        res.push_back(idx + 1);
        cnt--;
        a += k - 1;
        if (a > cnt and cnt) {
            a %= cnt;
            if (!a) a = min(k, cnt);
        }
    }
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