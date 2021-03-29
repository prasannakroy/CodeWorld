/*****************************
* Author :: Πρασαννα Κ. Ροι  *
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
	int sum = ((n * (n + 1)) / 2) - 1;
	if (k < n - 1 or k > sum) return void(cout << "IMPOSSIBLE\n");
	vector<int> a(n), lst;
	iota(span(a), 1);
	for (int i = 0; i < n - 1; i++) {
		int sz = n - i - 2;
		int dif = k - sz;
		dif = min(n - i, dif);
		k -= dif;
		lst.push_back(dif);
	}
	if (k) return void(cout << "IMPOSSIBLE\n");
	for (int i = n - 2; i >= 0; i--) 
		reverse(begin(a) + i, begin(a) + i + lst[i]);
	for (auto &i: a) cout << i << " ";
	cout << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; cout << "Case #" << i << ": ", solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}
