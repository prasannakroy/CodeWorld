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
	int n, cnt(0);
	cin >> n;
	map<string, int> m;
	vc<string> a(n);
	for (auto &i: a) cin >> i, m[i]++;
	for (auto &s: a) if (m[s] > 1) {
		cnt++;
		m[s]--;
		for (int i = 0; i < 4; i++) {
			bool flag(0);
			char x = s[i];
			for (char c = '0'; c <= '9'; c++) {
				s[i] = c;
				if (!m[s]) {
					m[s]++;
					flag = 1;
					break;
				}
			}
			if (flag) break;
			s[i] = x;
		}
	}
	cout << cnt << "\n";
	for (auto &i: a) cout << i << "\n";
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