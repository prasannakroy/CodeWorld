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
	int n, m, d;
	cin >> n >> m >> d;

	minpq<int> q;
	int sum(0), res(0);

	for (int i = 0, x; i < n; i++) {
		cin >> x;
		if (x < 0) 
			continue;
		q.push(x);
		sum += x;
		if (q.size() > m) {
			x = q.top();
			q.pop();
			sum -= x;
		}
		res = max(res, sum - ((i + 1) * d));
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