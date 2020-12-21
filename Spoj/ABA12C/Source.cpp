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

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(k);
	for (auto &i: a) cin >> i;
	vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(k + 1, vector<int>(n + 1, -1)));

	function<int(int, int, int)> compute = [&](int idx, int wt, int cnt) {
		if ((!idx or !cnt) and wt) return (int)INT_MAX;
		if (!idx or !cnt) return 0ll;
		if (~dp[idx][wt][cnt]) return dp[idx][wt][cnt];
		int res = compute(idx - 1, wt, cnt);
		if (idx <= wt and ~a[idx - 1]) res = min(res, compute(idx, wt - idx, cnt - 1) + a[idx - 1]);
		return dp[idx][wt][cnt] = res;
	};

	int res = compute(k, k, n);
	if (res >= INT_MAX) res = -1;
	cout << res << "\n";
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