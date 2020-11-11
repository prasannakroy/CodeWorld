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
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)

void solve() {
	int n, x;
	cin >> n;
	vector<int> a(n), b(n), res, m(64, 0);

	function<int(int)> factorTwo = [&] (int val) {
		int a = val, cnt(0);
		while (!(a & 1)) cnt++, a >>= 1;
		return cnt;
	};
	int mx(0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m[b[i] = factorTwo(a[i])]++;
		if (m[b[i]] > m[mx]) mx = b[i];
	}
	
	for (int i = 0; i < n; i++) if (b[i] != mx) res.push_back(a[i]);
	cout << res.size() << "\n";
	for (auto &i: res) cout << i << " ";
	cout << "\n";
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}