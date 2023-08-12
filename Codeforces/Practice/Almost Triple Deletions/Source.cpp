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

	vc<int> a(n);

	for (auto &i: a) 
		cin >> i;

	vc<vc<bool>> check(n + 1, vc<bool>(n + 1, 1));

	for (int i = 0; i < n; i++) {
		vc<int> cnt(n + 1, 0);
		int mx = 0;
		for (int j = i; j < n; j++) {
			cnt[a[j]]++;
			mx = max(cnt[a[j]], mx);
			int len = j + 1 - i;
			if (len & 1) 
				check[i][j] = 0;
			else if (mx * 2 > len) 
				check[i][j] = 0;
		}
	}

	vc<int> dp(n + 1, 0);
	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		if (dp[i] == 0) {
			if (!check[0][i - 1]) 
				continue;
			dp[i] = 1;
		}
		for (int j = i + 1; j < n; j++) if (a[j] == a[i] and check[i + 1][j - 1]) 
			dp[j] = max(dp[j], dp[i] + 1);

		if (check[i + 1][n - 1]) 
			dp[n] = max(dp[n], dp[i]);
	}

	cout << dp[n] << '\n';

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