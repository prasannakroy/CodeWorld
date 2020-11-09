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

const int MAX_VAL = (int)1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    vector<vector<int>> dp(n + 1, vector<int>((n * 2) + 1, -1));
    sort(span(a));

    function<int(int, int)> compute = [&](int idx, int t) {
        if (idx < 0) return 0ll;
        if (t <= 0) return MAX_VAL; 
        if (dp[idx][t] != -1) return dp[idx][t];
        dp[idx][t] = min(abs(t - a[idx]) + compute(idx - 1, t - 1), compute(idx, t - 1));
        return dp[idx][t];
    };

    cout << compute(n - 1, n * 2) << "\n";
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}