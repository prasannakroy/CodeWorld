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

int power(int a, int b) {
	int res(1);
	while (b) {
		if (b & 1) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

void solve() {
	int a, b;
	vector<vector<int>> dp(10, vector<int>(10, 0));
	for (int i = 0; i < 10; i++) {
		if (i > 0) fill(dp[i].begin(), dp[i].end(), dp[i - 1][9]);
		for (int j = 1; j < 10; j++) 
			dp[i][j] += dp[i][j - 1] + (power(10, i) * j);
	}

	function<int(int)> compute = [&](int a) {
		int res(0), c(0), val(-1);
		while (a) {
			int t = a % 10;
			a /= 10;
			res += ((val + 1) * t);
			if (~val) val = (t * power(10, c)) + val;
			else val = t;
			if (c) t--;
			if (~t) res += dp[c][t];
			c++;
		}
		return res;
	};

	while (cin >> a >> b and ~a and ~b) {
		int r1(0), r2(0), c(0), val(-1);
		a--;
		cout << compute(b) - compute(a) << "\n";
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