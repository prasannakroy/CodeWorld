// Author : Prasanna Kumar
#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

template<typename t>
using minpq = priority_queue<t, vc<t>, greater<t>>;

template<typename t>
using maxpq = priority_queue<t>;

void solve() {
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	vc<array<int, 2>> prefCnt(n, {0, 0});
	int ct(0);
	for (int i = 0; i < n; i++) {
		if (i) 
			prefCnt[i] = prefCnt[i - 1];
		prefCnt[i][s[i] - '0']++;
	}

	vc<vc<array<int, 2>>> prefMx(k + 1, vc<array<int, 2>>(n, {0, 0}));
	auto sufMx = prefMx;

	vc<int> cnt(n + 1, -1);

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			array<int, 2> cost = {prefCnt[j][1], prefCnt[j][0]};
			if (i) {
				cost[0] -= prefCnt[i - 1][1];
				cost[1] -= prefCnt[i - 1][0];
			}
			if (cost[0] <= k) {
				cnt[j + 1 - i] = 0;
				prefMx[cost[0]][j][0] = max(prefMx[cost[0]][j][0], j + 1 - i);
				sufMx[cost[0]][i][0] = max(sufMx[cost[0]][i][1], j + 1 - i);
			}
			if (cost[1] <= k) {
				prefMx[cost[1]][j][1] = max(prefMx[cost[1]][j][1], j + 1 - i);
				sufMx[cost[1]][i][1] = max(sufMx[cost[1]][i][1], j + 1 - i);
			}
		}
	}

	for (int i = 0; i <= k; i++) {
		for (int j = 1; j < n; j++) {
			prefMx[i][j][0] = max(prefMx[i][j][0], prefMx[i][j - 1][0]);
			prefMx[i][j][1] = max(prefMx[i][j][1], prefMx[i][j - 1][1]);
			if (i)
				prefMx[i][j][1] = max(prefMx[i][j][1], prefMx[i - 1][j][1]);
		}
		for (int j = n - 2; j >= 0; j--) {
			sufMx[i][j][0] = max(sufMx[i][j][0], sufMx[i][j + 1][0]);
			sufMx[i][j][1] = max(sufMx[i][j][1], sufMx[i][j + 1][1]);
			if (i) 
				sufMx[i][j][1] = max(sufMx[i][j][1], sufMx[i - 1][j][1]);
		}
	}

	cnt[0] = prefMx[k][n - 1][1];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			if (i < n - 1)
				cnt[prefMx[j][i][0]] = max(cnt[prefMx[j][i][0]], sufMx[k - j][i + 1][1]);
			if (i)
				cnt[sufMx[j][i][0]] = max(cnt[sufMx[j][i][0]], prefMx[k - j][i - 1][1]);
		}
	}

	for (int i = 1; i <= n; i++) {
		int res(0);
		for (int j = 0; j <= n; j++) if (cnt[j] != -1) {
			res = max(res, (j * i) + cnt[j]);
		}
		cout << res << ' ';
	}
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