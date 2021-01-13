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

const int mod = 1e8;

void solve() {
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    int dp[n1 + 1][n2 + 1][k1 + 1][k2 + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i <= k1; i++) 
        for (int j = 0; j <= k2; j++) 
            dp[0][0][i][j] = 1;
    for (int i = 0; i <= n1; i++) 
        for (int j = 0; j <= n2; j++) 
            for (int k = 0; k <= k1; k++) 
                for (int l = 0; l <= k2; l++) {
                    if (i > 0 and k > 0) (dp[i][j][k][l] += dp[i - 1][j][k - 1][k2]) %= mod;
                    if (j > 0 and l > 0) (dp[i][j][k][l] += dp[i][j - 1][k1][l - 1]) %= mod;
                }

    cout << dp[n1][n2][k1][k2] << "\n";
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