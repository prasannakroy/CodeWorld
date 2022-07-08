/*****************************
*  Author :: Πρασαννα Κ. Ροι *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
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

const int p = 29;
const int mod = 1e9 + 7;


void solve() {
	int n, m;
	cin >> n >> m;
	vc<vc<int>> a(n, vc<int>(m, 1));
	int rc = 1, v = 1;
	for (int i = 0; i < n; i++) {
		int c = 1;
		if (rc % 2 == 0) 
			v ^= 1;
		int val = v;
		rc++;
		for (int j = 0; j < m; j++) {
			a[i][j] = val;
			c++;
			if (c % 2 == 0) 
				val ^= 1;
		}
	}
	for (auto &i: a) {
		for (auto &j: i) 
			cout << j << ' ';
		cout << '\n';
	}
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