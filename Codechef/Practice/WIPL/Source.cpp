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
#define int int64_t
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

void solve() {
    int n, k;
    cin >> n >> k;
    int total(0);
    vc<int> a(n);
    for (auto &i: a) cin >> i, i = min(i, k), total += i;
    if ((total >> 1) < k) return void(cout << "-1\n");
    sort(span(a), greater<int>());
    total = 0;
    int sz;
    for (int i = 0; i < n; i++) {
        total += a[i];
        if (total >= 3 * k or i == n - 1) {
            sz = i + 1;
            break;
        }
    }

    // credits geeksforgeeks minimum subset difference
    bool dp[sz + 1][total + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i <= sz; i++) 
        dp[i][0] = 1;
    for (int i = 1; i <= sz; i++) 
        for (int j = 1; j < total; j++) {
            dp[i][j] = dp[i - 1][j];
            if (a[i - 1] <= j) 
                dp[i][j] |= dp[i - 1][j - a[i - 1]];
        }
    total = 0;
    for (int i = 0; i < sz; i++) {
        total += a[i];
        if (total / 2 < k) continue;
        for (int j = total / 2; j >= 0; j--) 
            if (dp[i + 1][j]) {
                if (j >= k) return void(cout << i + 1 << "\n");
                break;
            }
    }
    cout << -1 << "\n";
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