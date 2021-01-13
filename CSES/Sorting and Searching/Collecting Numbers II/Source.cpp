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
    int n, q, x, y;
    cin >> n >> q;
    vc<int> a(n), idx(n);
    for (int i = 0; i < n; i++) cin >> a[i], a[i]--, idx[a[i]] = i;

    auto compute = [&](int l, int r) {
        int c = 0;
        while (l <= r) {
            while (l + 1 <= r and idx[l] < idx[l + 1]) l++;
            l++;
            c++;
        }
        return c;
    };

    int cnt = compute(0, n - 1);

    while (q--) {
        cin >> x >> y;
        if (x == y) {
            cout << cnt << "\n";
            continue;
        }
        x--, y--;
        if (x > y) swap(x, y);
        if (abs(a[y] - a[x]) < 3) {
            int l = max(0ll, min(a[y], a[x]) - 1);
            int r = min(n - 1, max(a[y], a[x]) + 1);
            cnt -= compute(l, r);
            swap(a[x], a[y]);
            idx[a[x]] = x;
            idx[a[y]] = y;
            cnt += compute(l, r);
        }
        else {
            int l1 = max(0ll, a[x] - 1);
            int r1 = min(n - 1, a[x] + 1);
            int l2 = max(0ll, a[y] - 1);
            int r2 = min(n - 1, a[y] + 1);
            cnt -= compute(l1, r1);
            cnt -= compute(l2, r2);
            swap(a[x], a[y]);
            idx[a[x]] = x;
            idx[a[y]] = y;
            cnt += compute(l1, r1);
            cnt += compute(l2, r2);
        }
        cout << cnt << "\n";
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