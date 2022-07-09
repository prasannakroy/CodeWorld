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

	vc<vc<int>> adj(n + 1);

	for (int i = 0; i < n; i++) {
		int l = ((i + 1) / (a[i] + 1)) + 1;
		adj[l].push_back(i);
	}

	minpq<array<int, 2>> q;
	vc<int> res(n, 0);

	for (int i = 1; i <= n; i++) {
		for (auto &j: adj[i]) {
			int r;
			if (a[j]) 
				r = (j + 1) / a[j];
			else 
				r = n;
			q.push({r, j});
		}
		assert(!q.empty());
		res[q.top()[1]] = i;
		q.pop();
	}



	for (int i = 0; i < n; i++) 
		cout << res[i] << ' ';

	for (int i = 0; i < n; i++) 
		assert(a[i] == ((i + 1) / res[i]));

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