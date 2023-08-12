// Author : Prasanna Kumar
#include<bits/stdc++.h>
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

	vc<int> a(n);
	iota(span(a), 1);

	int res(0);
	for (int i = 0; i < n; i++) {
		int st = n - i - 1;
		auto lst = a;
		reverse(lst.begin() + st, lst.end());
		int sum(0), mx(0);
		for (int i = 0; i < n; i++) {
			sum += (lst[i] * (i + 1));
			mx = max(mx, lst[i] * (i + 1));
		}
		sum -= mx;
		res = max(res, sum);
	}
	cout << res << '\n';
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