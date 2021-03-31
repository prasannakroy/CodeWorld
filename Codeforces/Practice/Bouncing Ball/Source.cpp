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
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

void solve() {
	int n, p, k, res(INT_MAX), x, y;
	cin >> n >> p >> k;
	vc<int> vis(n, 0), cnt(n, 0);
	string s;
	cin >> s;
	cin >> x >> y;
	for (int i = n - 1; i >= p - 1; i--) {
		int c(0);
		for (int j = i; j < n; j += k) {
			if (vis[j]) {
				c += cnt[j];
				break;
			}
			vis[j] = 1;
			if (s[j] == '0') c += x;
		}
		cnt[i] = c;
		c += ((i + 1 - p) * y);
		res = min(res, c);
	}
	cout << res << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}