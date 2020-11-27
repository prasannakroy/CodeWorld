/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) a.begin(), a.end()
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)

const int mod = (int)1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m; 
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    vector<vector<int>> dp(n, vector<int> (m + 1, -1));

    function<int(int, int)> compute = [&](int idx, int val) {
        if (idx < 0) return 1ll;
        if (idx < n - 1 and a[idx] and abs(val - a[idx]) > 1) return 0ll;

        if (~dp[idx][val]) return dp[idx][val];
        if (a[idx]) return compute(idx - 1, a[idx]);
        int mn = 1, mx = m;
        if (idx != n - 1) mn = max(a[idx + 1] - 1, 1ll), mx = min(a[idx + 1] + 1, m);
        int res = 0;
        for (int i = mn; i <= mx; i++) a[idx] = i, (res += compute(idx - 1, i)) %= mod;
        a[idx] = 0;
        return dp[idx][val] = res;
    };

    cout << compute(n - 1, 0) << "\n";
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