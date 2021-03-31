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

int power(int a, int b) {
	int res(1);
	while (b) {
		if (b & 1) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;
	map<int, int> m;
	vc<int> lst;
	for (int i = 2; i * i <= n; i++) if (n % i == 0) 
		while (n % i == 0) n /= i, m[i]++;
	if (n > 1) m[n]++;
	for (auto &[x, y]: m) lst.push_back(power(x, y));
	int a(1), b(1), mn(LLONG_MAX);
	for (int i = 0; i < (1 << lst.size()); i++) {
		int x(1), y(1);
		for (int j = 0; j < lst.size(); j++) {
			if (i & (1 << j)) x *= lst[j];
			else y *= lst[j];
		}
		if (max(x, y) < mn) {
			mn = max(x, y);
			a = x;
			b = y;
		}
	}
	cout << a << " " << b << "\n";
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