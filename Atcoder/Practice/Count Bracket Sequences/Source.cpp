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

const int mod = 998244353;

void solve() {
	string s;
	cin >> s;

	int n = s.length();

	if (s[0] == '?') {
		s[0] = '(';
	} 
	if (s[n - 1] == '?') {
		s[n - 1] = ')';
	}

	if (n & 1 or s[0] == ')' or s[n - 1] == '(') {
		return void(cout << 0 << '\n');
	}

	vc<vc<int>> dp(n + 1, vc<int>(n + 1, 0));

	dp[1][0] = 0;
	dp[1][1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			int val1(0), val2(0);
			if (s[i - 1] != ')' and j) 
				val1 = dp[i - 1][j - 1];
			if (s[i - 1] != '(' and j < n) 
				val2 = dp[i - 1][j + 1];
			dp[i][j] = (val1 + val2) % mod;
		}
	}

	cout << dp[n][0] << '\n';

}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1), st(0);
  // cin >> t;
  for (int i = st; i < t + st; /*cout << "Case #" << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}