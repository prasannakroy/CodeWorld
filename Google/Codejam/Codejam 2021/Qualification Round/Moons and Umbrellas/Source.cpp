/*****************************
* Author :: Πρασαννα Κ. Ροι  *
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
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

void solve() {
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    int n = s.length();
    vc<vc<int>> dp(n, vc<int>(2, -1));
    function<int(int, int)> compute = [&](int idx, int nxt) {
        if (idx < 0) 
            return 0ll;
        if (~dp[idx][nxt]) return dp[idx][nxt];

        int res(0);
        if (s[idx] != '?') {
            if (s[idx] == 'C' and s[idx + 1] == 'J') res += x;
            else if (s[idx] == 'J' and s[idx + 1] == 'C') res += y;
            int t = (s[idx] == 'C' ? 0 : 1);
            res += compute(idx - 1, t);
        }
        else {
            int a(0), b(0);
            s[idx] = 'C';
            if (nxt == 1) a += x;
            a += compute(idx - 1, 0);
            s[idx] = 'J';
            if (nxt == 0) b += y;
            b += compute(idx - 1, 1);
            res = min(a, b);
            s[idx] = '?';
        }
        return dp[idx][nxt] = res;
    };

    int res(INT_MAX);
    if (s[n - 1] == '?') {
        s[n - 1] = 'C';
        res = compute(n - 2, 0);
        s[n - 1] = 'J';
        int val = compute(n - 2, 1);
        res = min(res, val);
    }
    else {
        int t = (s[n - 1] == 'C' ? 0 : 1);
        res = compute(n - 2, t);
    }
    cout << res << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; cout << "Case #" << i << ": ", solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}
