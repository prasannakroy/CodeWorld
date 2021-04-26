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
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int n, m;
  while (cin >> n and n) {
  	vc<int> a(n);
  	for (auto &i: a) cin >> i;
  	cin >> m;
  	vc<int> b(m);
  	for (auto &i: b) cin >> i;
  	vc<array<int, 2>> sum;
  	int s1(0), s2(0), flag(0), res(0);
  	int i, j;
  	for (i = 0, j = 0; i < n and j < m; ) {
  		if (a[i] < b[j]) {
  			s1 += a[i];
  			i++;
  		}
  		else if (a[i] > b[j]) {
  			s2 += b[j];
  			j++;
  		}
  		else {
  			res += a[i];
  			sum.push_back({s1, s2});
  			s1 = 0, s2 = 0;
  			i++, j++;
  		}
  	}
  	while (i < n) s1 += a[i++];
  	while (j < m) s2 += b[j++];
  	sum.push_back({s1, s2});
  	for (auto &i: sum) res += max(i[0], i[1]);
  	cout << res << "\n";
  }
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}