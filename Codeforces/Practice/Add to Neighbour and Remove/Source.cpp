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
	int n, sum(0);
	cin >> n;
	vc<int> a(n);
	int res = n - 1;
	for (auto &i: a) cin >> i, sum += i;
	for (int i = 0; i < n; i++) if ((sum % (n - i)) == 0) {
		int val = sum / (n - i), k(0);
		bool flag(1);
		for (int i = 0; i < n; i++) {
			if (k + a[i] > val) {
				flag = 0;
				break;
			}
			else if (k + a[i] < val) k += a[i];
			else k = 0;
		}
		if (flag) {
			res = i;
			break;
		}
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