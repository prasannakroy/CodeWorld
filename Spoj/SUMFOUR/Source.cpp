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

void solve() {
	int n, mx(0);
	cin >> n;
	int a[4][n];
	for (int i = 0; i < n; i++) {
		cin >> a[0][i] >> a[1][i] >> a[2][i] >> a[3][i];
		mx = max({mx, abs(a[0][i]), abs(a[1][i]), abs(a[2][i]), abs(a[3][i])});
	}

	int lst1[n * n], lst2[n * n];

	for (int i = 0, idx = 0; i < n; i++) 
		for (int j = 0; j < n; j++, idx++) lst1[idx] = a[0][i] + a[1][j];

	for (int i = 0, idx = 0; i < n; i++) 
		for (int j = 0; j < n; j++, idx++) lst2[idx] = a[2][i] + a[3][j];

	sort(lst1, lst1 + (n * n));
	sort(lst2, lst2 + (n * n));

	int res(0);
	n *= n;
	int l = 0, r = n - 1;
	while (l < n and r >= 0) {
		if (lst1[l] + lst2[r] < 0) l++;
		else if (lst1[l] + lst2[r] > 0) r--;
		else {
			int v1 = lst1[l];
			int v2 = lst2[r];
			int c1(0), c2(0);
			while (l < n and lst1[l] == v1) l++, c1++;
			while (r >= 0 and lst2[r] == v2) r--, c2++;
			res += (c1 * c2);
		}
	}
	cout << res << "\n";
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