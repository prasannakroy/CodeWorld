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
	int n, m;
	cin >> n >> m;
	vc<string> a(n);

	for (auto &i: a) 
		cin >> i;

	map<char, int> mp;
	for (int i = 0; i < m; i++) {
		bool V, I, K;
		V = I = K = false;
		for (int j = 0; j < n; j++) {
			if (a[j][i] == 'v') 
				V = true;
			else if (a[j][i] == 'i' and mp['v']) 
				I = true;
			else if (a[j][i] == 'k' and mp['i']) 
				K = true;
			else if (a[j][i] == 'a' and mp['k']) 
				return void(cout << "YES\n");
		}
		mp['v'] += V;
		mp['i'] += I;
		mp['k'] += K;
	}
	cout << "NO\n";

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