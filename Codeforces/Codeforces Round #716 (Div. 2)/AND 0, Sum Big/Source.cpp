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

vc<int> fact(100001);

int power(int a, int b) {
	int res(1);
	while (b) {
		if (b & 1) (res *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return res;
}

void precompute() {
	fact[0] = 1;
	for (int i = 1; i < 100001; i++) fact[i] = (fact[i - 1] * i) % mod;
}

int invMod(int a) {
	return power(a, mod - 2);
}

int nPr(int n, int r) {
	int res = fact[n];
	(res *= invMod(fact[r])) %= mod;
	return res;
}

void solve() {
	int n, k;
	cin >> n >> k;
	int res(1);
	for (int i = 0; i < k; i++) (res *= nPr(n, n - 1)) %= mod;
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