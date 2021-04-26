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
#define double long double
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

double pi = 3.141592653589793238462;

void solve() {
	int n, f;
	double mx = 0.0;
	cin >> n >> f;
	f++;
	vc<double> a(n);
	for (auto &i: a) cin >> i, mx = max(i, mx);

	auto check = [&](double r) {
		int cnt(0);
		for (auto &i: a) cnt += (int)((i * i) / (r * r));
		return cnt >= f;
	};

	double l = 0, r = mx + 1;
	int cnt(150);
	while (cnt--) {
		double m = (l + r) / 2;
		if (check(m)) l = m;
		else r = m;
	}
	double area = pi * l * l;
	cout << fixed << setprecision(4) << area << "\n";
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