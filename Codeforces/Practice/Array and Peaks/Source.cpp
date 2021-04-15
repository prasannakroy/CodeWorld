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
	int n, k;
	cin >> n >> k;
	if (k > (n - 1) / 2) return void(cout << -1 << "\n");
	vc<int> a(n, 0);
	int val(3), idx = 0;
	a[idx++] = 1;
	for (int i = 0; i < k; i++, val += 2, idx += 2) {
		a[idx] = val;
		a[idx + 1] = val - 1;
	}
	val--;
	for (; idx < n; idx++) a[idx] = val++;
	for (auto &i: a) cout << i << " ";
	cout << "\n";
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1);
  cin >> t;
  for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}