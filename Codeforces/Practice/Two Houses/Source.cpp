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
	int n;
	cin >> n;
	vc<int> a(n);
	for (auto &i: a) cin >> i;
	priority_queue<array<int, 3>> q;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) if (j != i) 
			if (a[j] >= a[i]) q.push({a[j] - a[i], j + 1, i + 1});
	while (!q.empty()) {
		auto t = q.top();
		q.pop();
		cout << "? " << t[1] << " " << t[2] << endl;
		string s;
		cin >> s;
		if (s == "Yes") 
			return void(cout << "! " << t[1] << " " << t[2] << endl);
	}
	cout << "! " << 0 << " " << 0 << endl;
}

signed main() {
    // auto start = high_resolution_clock::now();
    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}