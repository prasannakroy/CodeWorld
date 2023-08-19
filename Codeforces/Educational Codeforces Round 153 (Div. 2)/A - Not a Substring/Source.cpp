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
	string a;
	cin >> a;

	if (a == "()") 
		return void(cout << "NO\n");

	cout << "YES\n";

	int n = a.length();
	string s = "", t = "";
	for (int i = 0; i < 2 * n; i++) {
		if (i & 1) 
			s += ')';
		else 
			s += '(';
	}
	for (int i = 0; i < 2 * n; i++) {
		if (i < n) 
			t += '(';
		else 
			t += ')';
	}
	for (int i = 1; i < n; i++) if (a[i] == a[i - 1]) {
		return void(cout << s << '\n');
	}
	cout << t << '\n';

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