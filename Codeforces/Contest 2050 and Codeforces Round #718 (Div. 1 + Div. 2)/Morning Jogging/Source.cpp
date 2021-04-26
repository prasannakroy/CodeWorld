/*****************************
*  Author :: Πρασαννα Κ. Ροι *
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

template<typename t>
using minpq = priority_queue<t, vc<t>, greater<t>>;

void solve() {
	int n, m, x;
	cin >> n >> m;
	minpq<array<int, 2>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x;
			q.push({x, i});
		}
	}
	vc<vc<int>> res(n, vc<int>(m, -1));
	int cnt(0), c(0);
	while (!q.empty()) {
		auto t = q.top();
		q.pop();
		while (res[t[1]][cnt] != -1) 
			(cnt += 1) %= m;
		res[t[1]][cnt] = t[0];
		(cnt += 1) %= m;;
	}
	for (auto &i: res) {
		for (auto &j: i) cout << j << " ";
		cout << '\n';
	}
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