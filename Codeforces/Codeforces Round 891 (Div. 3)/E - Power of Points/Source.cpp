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

	vc<array<int, 2>> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i][0];
		a[i][1] = i;
	}

	vc<int> res(n, 0);

	sort(span(a));

	vc<int> difl, difr;

	int lsum(1), rsum(0);

	for (int i = 1; i < n; i++) {
		int val = a[i][0] + 1 - a[0][0];
		difr.push_back(val);
		rsum += val;
	}

	res[a[0][1]] = lsum + rsum;

	for (int i = 1; i < n; i++) {
		int val = difr.back();
		int dif = a[i][0] - a[i - 1][0];
		lsum -= (a[i - 1][0] * i);
		lsum -= (a[i][0] - 1);
		lsum += (a[i][0] * (i + 1));

		rsum += (a[i - 1][0] * (n - i));
		rsum -= (a[i][0] + 1);
		rsum -= (a[i][0] * (n - (i + 1)));

		res[a[i][1]] = rsum + lsum;

	}

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