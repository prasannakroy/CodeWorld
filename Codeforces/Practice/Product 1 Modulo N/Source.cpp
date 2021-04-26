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

int gcd(int a, int b) {
	while (b) tie(a, b) = make_tuple(b, a % b);
	return a;
}

void solve() {
	int n;
	cin >> n;
	int val(1);
	vc<int> res;
	for (int i = 1; i < n; i++) if (gcd(n, i) == 1) (val *= i) %= n, res.push_back(i);
	if (val == 1) {
		cout << res.size() << "\n";
		for(auto &i: res) cout << i << " ";
		cout << "\n";
	}
	else {
		res.pop_back();
		cout << res.size() << "\n";
		for (auto &i: res) cout << i << " ";
		cout << "\n";
	}
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