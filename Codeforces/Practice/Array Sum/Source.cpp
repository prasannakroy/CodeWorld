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
	int n, k;
	cin >> n >> k;
	int cnt(0);
	vc<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0 or a[i] != a[i - 1]) cnt++;
	}
	if (k == 1) {
		if (cnt == 1) return void(cout << "1\n");
		return void(cout << "-1\n");
	}
	int res(1);
	cnt = max(0ll, cnt - k);
	k--;
	res += ((cnt + k - 1) / k);
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