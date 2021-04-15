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

auto convert(int val, int base) {
	vc<int> a(21);
	for (int i = 0; i < 21; i++, val /= base) a[i] = val % base;
	return a;
}

void solve() {
	int n, x;
	cin >> n >> x;
	int sum(0);
	for (int i = 0, val = 1; i < n; i++, val *= 3) sum += val;
	if (sum < x) return void(cout << -1 << "\n");
	
	auto a = convert(x, 3);
	vc<int> b(21, 0);
	for (int i = 0; i < 21; i++) {
		if (a[i] == 1) a[i] = 0, b[i] = 1;
		else if (a[i] == 2) a[i] = 1, a[i + 1]++;
		else if (a[i] == 3) a[i] = 0, a[i + 1]++;
	}
	for (int i = 0; i < 21; i++) if (a[i] == 1) cout << i + 1 << " ";
	cout << "\n";
	for (int i = 0; i < 21; i++) if (b[i] == 1) cout << i + 1 << " ";
	cout << "\n";
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