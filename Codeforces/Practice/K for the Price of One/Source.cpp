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
	int n, p, k, res(0), sum(0);
	cin >> n >> p >> k;
	vc<int> a(n, 0);
	for (auto &i: a) cin >> i;
	sort(span(a));
	for (int i = 0; i < k; i++) {
		if (sum > p) break;
		int m(p - sum), cnt(i);
		for (int j = i + k - 1; j < n; j += k) {
			if (a[j] > m) break;
			cnt += k;
			m -= a[j];
		}
		res = max(res, cnt);
		sum += a[i];
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