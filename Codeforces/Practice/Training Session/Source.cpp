/*****************************
*  Author :: Πρασαννα Κ. Ροι *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

template<typename t>
using minpq = priority_queue<t, vc<t>, greater<t>>;

template<typename t>
using maxpq = priority_queue<t>;

void solve() {
	int n;
	cin >> n;
	vc<array<int, 2>> a(n);
	vc<int> cnt1(n + 1, 0), cnt2(n + 1, 0);
	for (auto &i: a) {
		cin >> i[0] >> i[1];
		cnt1[i[0]]++;
		cnt2[i[1]]++;
	}
	int res = n * (n - 1) * (n - 2);
	res /= 6;
	for (auto &[x, y]: a) {
		int r = (cnt1[x] - 1) * (cnt2[y] - 1);
		res -= r;
	}
	cout << res << "\n";
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1), st(0);
  cin >> t;
  for (int i = st; i < t + st; /*cout << "Case #" << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}