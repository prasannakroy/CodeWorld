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

	for (int i = 0, x; i < n; i++) {
		cin >> x;
		vc<int> lst(x);
		for (auto &i: lst) 
			cin >> i;
		sort(span(lst));
		a[i][0] = lst[0];
		a[i][1] = lst[1];
	}

	sort(span(a), [&](array<int, 2> p, array<int, 2> q){
		return p[0] < q[0];
	});

	vc<int> pref(n, 0);
	vc<int> suf(n, 0);

	pref[0] = a[0][1];
	suf[n - 1] = a[n - 1][1];

	for (int i = 1; i < n; i++) {
		pref[i] = pref[i - 1] + a[i][1];
	}

	for (int i = n - 2; i >= 0; i--) {
		suf[i] = suf[i + 1] + a[i][1];
	}
	int res(0);
	for (int i = 0; i < n; i++) {
		int prefSum(0), sufSum(0);
		if (i) 
			prefSum = pref[i - 1];
		if (i < n - 1) 
			sufSum = suf[i + 1];
		res = max(res, prefSum + sufSum);
	}
	cout << res + a[0][0] << '\n';
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