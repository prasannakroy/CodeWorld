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

	sort(span(a));

	vc<int> b, c;
	c.push_back(a[n - 1]);
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] == a[n - 1]) 
			c.push_back(a[i]);
		else 
			b.push_back(a[i]);
	}

	if (b.size() == 0) 
		return void(cout << -1 << '\n');

	cout << b.size() << ' ' << c.size() << '\n';

	for (auto &i: b) 
		cout << i << ' ';
	cout << '\n';
	for (auto &i: c) 
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