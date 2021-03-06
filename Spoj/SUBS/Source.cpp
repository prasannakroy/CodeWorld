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
	string x, y;
	cin >> x >> y;
	int n = x.length();
	int m = y.length();
	int l = 0, r = (m / n) + 1;

	auto check = [&](int p) {
		int len = p * n;
		int j = 0;
		for (int i = 0; i < m and j < len; i++) 
			if (x[j / p] == y[i]) j++;
		return j == len;
	};

	while (r - l > 1) {
		int mid = (r + l) >> 1;
		if (check(mid)) l = mid;
		else r = mid;
	}
	cout << l << "\n";
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