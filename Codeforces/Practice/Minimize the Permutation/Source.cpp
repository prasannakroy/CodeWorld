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
	int n;
	cin >> n;
	int cnt(n - 1);
	vc<int> a(n);
	map<int, int> m, mp;
	for (int i = 0; i < n; i++) cin >> a[i], m[a[i]] = i;
	for (int i = 1; i <= n; i++) if (m[i] > i - 1) {
		int idx = m[i];
		while (true) {
			if (idx == i - 1) break;
			if (mp[idx]) break;
			if (a[idx] > a[idx - 1]) break;
			mp[idx] = 1;
			swap(a[idx], a[idx - 1]);
			m[a[idx]] = idx--;
			m[a[idx]] = idx;
		}
	}
	for (auto &i: a) cout << i << " ";
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