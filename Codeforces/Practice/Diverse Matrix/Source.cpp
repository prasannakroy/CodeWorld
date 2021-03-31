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

void solve() {
	int r, c, cnt(2);
	cin >> r >> c;
	if (r == 1 and c == 1) return void(cout << 0 << "\n");
	if (r == 1) {
		for (int i = 0; i < c; i++) cout << cnt++ << " ";
		cout << "\n";
		return;
	}
	if (c == 1) {
		for (int i = 0; i < r; i++) cout << cnt++ << "\n";
		return;
	}
	int a[r][c];
	for (int i = 0; i < c; i++) a[0][i] = cnt++;
	for (int i = 1; i < r; i++) for (int j = 0; j < c; j++) a[i][j] = a[0][j] * (c + i + 1);
	for (auto &i: a) {
		for (auto &j: i) cout << j << " ";
		cout << "\n";
	}
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