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
    int n, m;
    cin >> n >> m;
    vc<int> a;
    a.push_back(0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    if (a.back() != m) a.push_back(m);
    n = a.size();
    vc<int> dif;
    dif.push_back(0);
    for (int i = 1; i < n; i++) dif.push_back(a[i] - a[i - 1]);
    vc<int> pref(n, 0), suf(n, 0);
    pref[0] = dif[0];
    pref[1] = dif[1];
    for (int i = 2; i < n; i++) pref[i] = dif[i] + pref[i - 2];
    suf[n - 1] = dif[n - 1];
    suf[n - 2] = dif[n - 2];
    for (int i = n - 3; i >= 0; i--) suf[i] = dif[i] + suf[i + 2];
    int flag = 1;
    int res = (n & 1) ? pref[n - 2] : pref[n - 1];
    for (int i = 1; i < n; i++) {
        if (i & 1) {
            int p = 0, s = 0;
            if (i > 1) p = pref[i - 2];
            if (i < n - 1) s = suf[i + 1];
            res = max(res, p + s + dif[i] - 1);
        }
        else {
            int p = 0, s = 0;
            p = pref[i - 1];
            if (i < n - 2) s = suf[i + 2];
            res = max(res, p + s + dif[i] - 1);
        }
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
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}