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
	int n, res(0);
	cin >> n;
	vc<int> mnn, mxx;
	int l = n;
	for (int i = 0; i < n; i++) {
		int sz, flag(0), mn(INT_MAX), mx(INT_MIN), x;
		cin >> sz;
		for (int i = 0; i < sz; i++) {
			cin >> x;
			if (i and x > mn) flag = 1;
			mn = min(x, mn);
			mx = max(mx, x);
		}
		if (flag) res += (2 * l) - 1, l--;
		else {
			mnn.push_back(mn);
			mxx.push_back(mx);
		}
	}
	sort(span(mnn), greater<int>());
	sort(span(mxx), greater<int>());
	int cnt(0);
	for (int i = 0, j = 0; i < l; i++) {
		while (j < l and mxx[j] > mnn[i]) cnt++, j++;
		res += cnt;
	}
	cout << res << "\n";
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