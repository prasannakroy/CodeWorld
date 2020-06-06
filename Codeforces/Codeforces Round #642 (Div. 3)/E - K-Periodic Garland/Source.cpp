/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define i_64 long long

int calc(string s, int cnt) {
    int n = s.length();
    int dp[n], res(cnt), c2(0);
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            dp[i] = 0;
            if (i > 0) dp[i] += min(dp[i - 1], c2);
            c2++;
            res = min(res, dp[i] + cnt - c2);
        }
        else {
            dp[i] = 1;
            if (i > 0) dp[i] += min(dp[i - 1], c2);
            res = min(res, dp[i] + cnt - c2);
        }
    }
    return res;
}

void solve() {
    int n, k, res(INT_MAX), cnt(0);
    cin >> n >> k;
    string s;
    cin >> s;
    std::vector<string> v(k);
    int count[k];
    memset(count, 0, sizeof count);
    for (int i = 0; i < n; i++) { 
        v[i % k] += s[i]; 
        cnt += (s[i] == '1');
        count[i % k] += (s[i] == '1');
    }
    for (int i = 0; i < k; i++) 
        res = min(res, calc(v[i], count[i]) + cnt - count[i]);
    cout << res << "\n";
}

signed main() {
    __AcHiLlEs

    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
