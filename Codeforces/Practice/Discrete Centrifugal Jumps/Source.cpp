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
	vc<int> a(n), lg(n, -1), rg(n, -1), ls(n, -1), rs(n, -1);
	for (auto &i: a) cin >> i;
	stack<int> s;
	s.push(0);
	for (int i = 1; i < n; i++) {
		while (!s.empty() and a[s.top()] < a[i]) s.pop();
		if (!s.empty()) lg[i] = s.top();
		s.push(i);
	}
	while (!s.empty()) s.pop();
	s.push(0);
	for (int i = 1; i < n; i++) {
		while (!s.empty() and a[s.top()] > a[i]) s.pop();
		if (!s.empty()) ls[i] = s.top();
		s.push(i);
	}
	while (!s.empty()) s.pop();
	s.push(n - 1);
	for (int i = n - 2; i >= 0; i--) {
		while (!s.empty() and a[s.top()] < a[i]) s.pop();
		if (!s.empty()) rg[i] = s.top();
		s.push(i);
	}
	while (!s.empty()) s.pop();
	s.push(n - 1);
	for (int i = n - 2; i >= 0; i--) {
		while (!s.empty() and a[s.top()] > a[i]) s.pop();
		if (!s.empty()) rs[i] = s.top();
		s.push(i);
	}
	vc<int> dp(n, INT_MAX);
	vc<int> gph[n];
	for (int i = 0; i < n; i++) {
		if (~rg[i]) gph[i].push_back(rg[i]);
		if (~rs[i]) gph[i].push_back(rs[i]);
		if (~lg[i]) gph[lg[i]].push_back(i);
		if (~ls[i]) gph[ls[i]].push_back(i);
	}
	dp[0] = 0;
	for (int i = 0; i < n; i++) 
		for (auto &j: gph[i]) dp[j] = min(dp[j], dp[i] + 1);
	cout << dp[n - 1] << "\n";
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