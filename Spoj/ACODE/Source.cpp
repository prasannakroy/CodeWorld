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
#define int unsigned long long
#define span(a) a.begin(), a.end()

void solve() {
	string s;
	while (cin >> s and s[0] != '0') {
		int n = s.length();
		vector<int> dp(n + 1, 0);
		dp[n] = 1;
		if (s[n - 1] - '0') dp[n - 1] = 1;
		for (signed i = n - 2; i >= 0; i--) {
			if (!(s[i] - '0')) continue; 
			dp[i] = dp[i + 1];
			int val = ((s[i] - '0') * 10) + s[i + 1] - '0';
			if (val < 27) dp[i] += dp[i + 2];
		}
		cout << dp[0] << "\n";
	}
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