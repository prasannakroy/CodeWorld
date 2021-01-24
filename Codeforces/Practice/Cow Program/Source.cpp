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
    int n;
    cin >> n;
    vc<int> a(n + 1);
    for (int i = 2; i <= n; i++) cin >> a[i];

    vc<vc<int>> dp(n + 1, vc<int>(2, -1));

    function<int(int, int)> compute = [&](int idx, int t) {
        if (idx <= 0 or idx > n) return 0ll;
        if (dp[idx][t] == 0) return -2ll;
        if (~dp[idx][t]) return dp[idx][t];

        dp[idx][t] = 0;
        int val;
        if (t) val = compute(idx - a[idx], 0ll);
        else val = compute(idx + a[idx], 1ll);
        return dp[idx][t] = (val == -2 ? val : val + a[idx]);
    };
    
    for (int i = 1; i < n; i++) {
        a[1] = i;
        int val = compute(1, 0);
        cout << ((val == -2) ? val + 1 : val) << "\n";
        dp[1][0] = -1;
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