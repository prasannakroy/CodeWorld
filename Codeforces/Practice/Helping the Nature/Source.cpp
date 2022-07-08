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

void solve() {
	int n;
	cin >> n;
	vc<int> a(n);
	for (auto &i: a) 
		cin >> i;
	int res(0);

	function<int()> makeNonDecreasing = [&]() {
		int cost(0);
		vc<int> b(n, 0);
		for (int i = 1; i < n; i++) if (a[i] < a[i - 1]) {
			int val = a[i - 1] - a[i];
			cost += val;
			b[0] -= val;
			b[i] += val;
		}
		for (int i = 1; i < n; i++) 
			b[i] += b[i - 1];
		for (int i = 0; i < n; i++) 
			a[i] += b[i];
		return cost;
	};

	res += makeNonDecreasing();
	reverse(span(a));
	res += makeNonDecreasing();
	for (int i = 1; i < n; i++) 
		assert(a[i] == a[i - 1]);
	res += abs(a[0]);
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