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
#define span(a) a.begin(), a.end()

template<typename t>
using vc = vector<t>;

void solve() {
    int n, m;
    cin >> n;
    vc<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0) a[i] += a[i - 1];
    }
    cin >> m;
    vc<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        if (i > 0) b[i] += b[i - 1];
    }
    int res(0);
    for (int sz = 1; sz <= n + m; sz++) {
        if (sz - 1 < n) res = max(res, a[sz - 1]);
        if (sz - 1 < m) res = max(res, b[sz - 1]);
        int i = min(sz - 2, n - 1);
        int j = 0;
        while (i + j + 2 != sz) j++;
        for (; i >= 0 and j < min(sz - 1, m); i--, j++) res = max(res, a[i] + b[j]);
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