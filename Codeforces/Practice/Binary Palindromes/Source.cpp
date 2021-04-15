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
	int n, res(0), c1(0), c0(0), cnt(0);
	cin >> n;
	vc<string> a(n);
	for (auto &i: a) {
		cin >> i;
		for (auto &j: i) j == '0' ? c0++ : c1++;
		if (i.length() & 1) cnt++;
	}
	while (cnt--) {
		if (c1 & 1) c1--;
		else if (c0 & 1) c0--;
		else if (c1) c1--;
		else c0--;
	}
	if (c1 & 1 or c0 & 1) cout << n - 1 << "\n";
	else cout << n << "\n";
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