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
	for (auto &i: a) 
		cin >> i;

	vc<int> res;
	res.push_back(a[0]);
	for (int i = 1; i < n; i++) {
		if (a[i] < res.back()) 
			res.push_back(a[i]);
		res.push_back(a[i]);
	}
	cout << res.size() << '\n';
	for (auto &i: res) 
		cout << i << ' ';
	cout << '\n';
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