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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    vector<vector<array<int, 2>>> dp(n, vector<array<int, 2>>(n, array<int, 2>{-1, -1}));

    function<array<int, 2>(int, int, int)> compute = [&] (int s, int e, int t) {
        if (s > e) {
            array<int, 2> res = {0, 0};
            return res;
        }
        if (~dp[s][e][t]) return dp[s][e];
        array<int, 2> x = compute(s + 1, e, t ^ 1);
        array<int, 2> y = compute(s, e - 1, t ^ 1);

        if (x[t] + a[s] > y[t] + a[e]) {
            x[t] += a[s];
            return dp[s][e] = x;
        }
        else {
            y[t] += a[e];
            return dp[s][e] = y;
        }
    };

    cout << compute(0, n - 1, 1)[1] << "\n";
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