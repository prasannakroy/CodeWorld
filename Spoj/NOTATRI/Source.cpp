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

signed main() {
  __AcHiLlEs

	int n;
	while (cin >> n and n) {
		vc<int> a(n);
		for (auto &i: a) cin >> i;
		sort(span(a));
		vc<int> lst[n];
		for (int i = 0; i < n; i++) 
			for (int j = i + 1; j < n; j++) 
				lst[i].push_back(a[i] + a[j]);
		for (auto &i: lst) if (i.size()) sort(span(i));

		int cnt(0), res(0);
		vc<int> c(n, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) 
				for (; c[j] < lst[j].size() and lst[j][c[j]] < a[i]; c[j]++) 
					cnt++;
			res += (cnt - c[i]);
		}
		cout << res << "\n";
	}
	return 0;
}
