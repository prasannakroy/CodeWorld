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

	vc<int> a(n), b(n);
	
	for (auto &i: a) 
		cin >> i;

	for (auto &i: b) 
		cin >> i;

	vc<array<int, 2>> dif(n);

	for (int i = 0; i < n; i++) {
		dif[i][0] = a[i] - b[i];
		dif[i][1] = i + 1;
	}

	sort(span(dif));

	vc<int> res;

	res.push_back(dif[n - 1][1]);

	for (int i = n - 2; i >= 0; i--) {
		if (dif[i][0] == dif[i + 1][0]) 
			res.push_back(dif[i][1]);
		else 
			break;
	}

	sort(span(res));

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