/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) a.begin(), a.end()
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)

void solve() {
    int n, k, p;
    cin >> n >> k >> p;
    vector<vector<int>> a(n, vector<int>(k + 1, 0));
    vector<vector<int>> dp(n, vector<int>(p + 1, -1));
    for (auto &i: a) for (int j = 1; j <= k; j++) cin >> i[j];
    for (int i = 0; i < n; i++) for (int j = 1; j <= k; j++) a[i][j] += a[i][j - 1];

    function<int(int, int)> compute = [&](int idx, int plt) {
        if (idx < 0 or plt <= 0) return 0ll;
        if (~dp[idx][plt]) return dp[idx][plt];
        int res(0);
        for (int i = 0; i <= min(k, plt); i++) 
            res = max(res, compute(idx - 1, plt - i) + a[idx][i]);
        return dp[idx][plt] = res;
    };

    cout << compute(n - 1, p) << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    // #ifndef ONLINE_JUDGE 
    //     __AnAkLuSmOs    
    // #endif

    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; cout << "Case #" << i << ": ", solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}