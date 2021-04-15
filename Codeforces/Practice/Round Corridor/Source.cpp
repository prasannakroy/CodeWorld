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

int gcd(int a, int b) {
	while (b) tie(a, b) = make_tuple(b, a % b);
	return a;
}

void solve() {
	int a[2], q;
	cin >> a[0] >> a[1] >> q;
	int d = gcd(a[0], a[1]);
	a[0] /= d;
	a[1] /= d;
	while (q--) {
		int t1, v1, t2, v2;
		cin >> t1 >> v1 >> t2 >> v2;
		t1--, t2--, v1--, v2--;
		if (v1 / a[t1] == v2 / a[t2]) cout << "YES\n";
		else cout << "NO\n";
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