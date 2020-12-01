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

struct project {
	int s, e, val;
	project() {
		s = e = val = 0;
	}
	bool operator < (project x) {
		return e < x.e;
	}
};

void solve() {
	int n;
	cin >> n;
	vector<project> a(n);
	for (auto &i: a) cin >> i.s >> i.e >> i.val;
	sort(span(a));
	
	function<int(int)> lowerBound = [&](int idx) {
		int l = 0, r = idx - 1, res = -1;
		while (l <= r) {
			int m = (l + r) >> 1;
			if (a[m].e < a[idx].s) res = m, l = m + 1;
			else r = m - 1; 
		}
		return res;
	};

	vector<int> dp(n, 0);
	dp[0] = a[0].val;
	for (int i = 1; i < n; i++) {
		int idx = lowerBound(i);
		dp[i] = max(dp[i - 1], a[i].val);
		if (~idx) dp[i] = max(dp[i], dp[idx] + a[i].val);	
	}
	cout << dp[n - 1] << "\n";
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