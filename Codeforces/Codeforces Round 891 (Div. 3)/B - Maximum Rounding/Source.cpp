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
	string s;
	cin >> s;

	int n = s.length();

	string res("");

	int cnt(0), mx(-1);
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] - '0' + cnt >= 5) {
			mx = i;
			cnt = 1;
		} else {
			cnt = 0;
		}
	}

	if (mx == -1) 
		return void(cout << s << '\n');

	if (mx == 0) {
		res += '1';
		for (int i = 0; i < n; i++) 
			res += '0';
	} else {
		for (int i = mx - 1; i >= 0; i--) {
			if (s[i] != '9') {
				s[i] += 1;
				break;
			} else {
				s[i] = '0';
			}
		}
		for (int i = 0; i < mx; i++) 
			res += s[i];
		for (int j = mx; j < n; j++) 
			res += '0';
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