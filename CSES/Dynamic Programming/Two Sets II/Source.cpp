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
    int n;
    cin >> n;

    int sm = (n * (n + 1)) / 2;
    if (sm & 1) {
        cout << 0 << "\n";
        return;
    }

    sm /= 2;
    vector<vector<int>> dp(sm + 1, vector<int>(n, 0));
    fill(span(dp[0]), 1);
    for (int i = 1; i <= sm; i++) 
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i][j - 1];
            if (j <= i) (dp[i][j] += dp[i - j][j - 1]) %= mod;
        }
    cout << dp[sm][n - 1] << "\n";
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