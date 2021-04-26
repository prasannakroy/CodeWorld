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

void generate(vc<int> &a, vc<int> &lst) {
	int n = a.size();
	for (int i = 0; i < (1 << n); i++) {
		int sum(0);
		for (int j = 0; j < n; j++) if (i & (1 << j)) sum += a[j];
		lst.push_back(sum);
	}
	sort(span(lst));
}

void solve() {
	int n, l, r;
	cin >> n >> l >> r;
	vc<int> a((n + 1) / 2), b(n / 2);
	for (auto &i: a) cin >> i;
	for (auto &i: b) cin >> i;
	vc<int> sum1, sum2;
	generate(a, sum1);
	generate(b, sum2);
	int res(0);
	if (sum1.size() > sum2.size()) swap(sum1, sum2);
	int s(sum2.size() - 1), e(sum2.size() - 1);
	for (auto &i: sum1) {
		int d1 = l - i;
		int d2 = r - i;
		while (e >= 0 and sum2[e] > d2) e--;
		while (s >= 0 and sum2[s] >= d1) s--;
		res += (e - s);
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