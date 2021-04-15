/*****************************
*  Author :: Πρασαννα Κ. Ροι *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

const int mod = 1e9 + 7;

int power(int a, int b) {
	int res(1);
	while (b) {
		if (b & 1) (res *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return res;
}

void solve() {
	int h, w;
	cin >> h >> w;
	vc<vc<int>> a(h, vc<int>(w, 0));
	vc<int> r(h), c(w);
	for (int i = 0; i < h; i++) {
		cin >> r[i];
		if (r[i]) for (int j = 0; j < r[i]; j++) {
				if (a[i][j] == -1) return void(cout << 0 << "\n");
				a[i][j] = 1;
			}
		if (r[i] < w) {
			if (a[i][r[i]] == 1) return void(cout << 0 << "\n");
			a[i][r[i]] = -1;
		}
	}
	for (int i = 0; i < w; i++) {
		cin >> c[i];
		if (c[i]) for (int j = 0; j < c[i]; j++) {
			if (a[j][i] == -1) return void(cout << 0 << "\n");
			a[j][i] = 1;
		}
		if (c[i] < h) {
			if (a[c[i]][i] == 1) return void(cout << 0 << "\n");
			a[c[i]][i] = -1;
		}
	}
	int cnt(0);
	for (auto &i: a) for (auto &j: i) cnt += (j == 0);
	cout << power(2, cnt) << "\n";
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1);
  // cin >> t;
  for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}