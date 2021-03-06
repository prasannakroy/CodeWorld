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
    vc<string> a(n);
    for (auto &i: a) cin >> i;
    vc<vc<int>> dp(n + 1, vc<int>(2, 0));
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i - 1] == "AND") {
            dp[i][1] = dp[i - 1][1];
            dp[i][0] = (2 * dp[i - 1][0]) + dp[i - 1][1];
        }
        else {
            dp[i][1] = (2 * dp[i - 1][1]) + dp[i - 1][0];
            dp[i][0] = dp[i - 1][0];
        }
    }
    cout << dp[n][1] << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}