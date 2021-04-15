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
	int n;
	cin >> n;
	int a[n];
	for (auto &i: a) cin >> i;
	vc<vc<int>> lst(2, vc<int>(n * n * n));
	int idx = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			for (int k = 0; k < n; k++) 
				lst[0][idx++] = (a[i] * a[j]) + a[k];
	idx = 0;
	for (int i = 0; i < n; i++) if (a[i] != 0)
		for (int j = 0; j < n; j++) 
			for (int k = 0; k < n; k++)  
				lst[1][idx++] = a[i] * (a[j] + a[k]);

	lst[1].resize(idx);
	n = lst[0].size();
	int m = lst[1].size();
	sort(span(lst[0]));
	sort(span(lst[1]));

	int res(0);
	for (int l = 0, r = 0; l < n and r < m; ) {
		if (lst[0][l] < lst[1][r]) l++;
		else if (lst[0][l] > lst[1][r]) r++;
		else {
			int val(lst[0][l]), c1(0), c2(0);
			while (l < n and lst[0][l] == val) l++, c1++;
			while (r < m and lst[1][r] == val) r++, c2++;
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

