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

void solve() {
	int n, x;
	cin >> n;
	vc<int> res(n, 0);
	vc<array<int, 2>> st(n);
	vc<vc<int>> univ(n);
	for (auto &i: st) cin >> i[0];
	for (auto &i: st) cin >> i[1];
	for (int i = 0; i < n; i++) 
		univ[st[i][0] - 1].push_back(st[i][1]);
	sort(span(univ), [&](vc<int> p, vc<int> q) {
		return p.size() > q.size();
	});
	for (auto &i: univ) {
		sort(span(i), greater<int>());
		for (int j = 1; j < i.size(); j++) i[j] += i[j - 1];
	}
	for (int i = 1; i <= n; i++) {
		for (auto &j: univ) {
			int sz = j.size();
			if (sz < i) break;
			int cnt = ((sz / i) * i) - 1;
			res[i - 1] += j[cnt];
		}
		cout << res[i - 1] << " ";
	}
	cout << "\n";
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