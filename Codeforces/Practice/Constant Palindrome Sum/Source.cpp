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
    int n, k;
    cin >> n >> k;
    vc<int> a(n), cnt((2 * k) + 1), pref(2 * (k + 1));
    for (auto &i: a) cin >> i;
    for (int i = 0; i < n / 2; i++) cnt[a[i] + a[n - i - 1]]++;
    for (int i = 0; i < n / 2; i++) {
        auto [x, y] = minmax(a[i], a[n - i - 1]);
        pref[x + 1]++;
        pref[y + k + 1]--;
    }
    for (int i = 1; i < 2 * (k + 1); i++) pref[i] += pref[i - 1];
    int res(INT_MAX);
    for (int i = 2; i <= 2 * k; i++) 
        res = min(res, n - cnt[i] - pref[i]);
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