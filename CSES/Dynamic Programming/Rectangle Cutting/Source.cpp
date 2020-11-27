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

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));

    for (int i = 1; i <= n; i++) dp[i][1] = i - 1, dp[i][0] = 0;
    for (int i = 1; i <= m; i++) dp[1][i] = i - 1, dp[0][i] = 0;
    for (int i = 1; i <= min(n, m); i++) dp[i][i] = 0;

    for (int i = 2; i <= n; i++) 
        for (int j = 2; j <= m; j++) 
            if (i != j) for (int k = 1; k < max(i, j); k++) {
                if (k < i) dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
                if (k < j) dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
            }

    cout << dp[n][m] << "\n";
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