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

i_64 dp[2000001], res[2000001];
i_64 mod = (i_64)1e9 + 7;

void solve() {
    i_64 n;
    cin >> n;
    n -= 2;
    cout << (res[n] * 4) % mod << "\n";
}

signed main() {
    __AcHiLlEs
    
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < 2000001; i++) 
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % mod;
    res[0] = 0;
    res[1] = 1;
    res[2] = 1;
    for (int i = 3; i < 2000001; i++) 
        (res[i] +=(dp[i] + res[i - 3])) %= mod;
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}