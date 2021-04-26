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

vc<int> a;

const int mx = 1e18;

void precompute() {
	int val(2050);
	while (val <= mx and val > 0) a.push_back(val), val *= 10;
}

void solve() {
	int n, res(0);
	cin >> n;
	for (int i = a.size() - 1; i >= 0; i--) if (a[i] <= n){
		res += n / a[i];
		n = n % a[i];
	}
	if (n) return void(cout << "-1\n");
	cout << res << "\n";
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  precompute();
  int t(1);
  cin >> t;
  for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}