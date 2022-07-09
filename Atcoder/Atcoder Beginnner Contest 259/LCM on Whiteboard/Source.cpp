/*****************************
*  Author :: Πρασαννα Κ. Ροι *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

template<typename t>
using minpq = priority_queue<t, vc<t>, greater<t>>;

template<typename t>
using maxpq = priority_queue<t>;

void solve() {
	int n;
	cin >> n;
	vc<vc<array<int, 2>>> a(n);
	map<int, int> mp;
	map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		a[i].resize(m);
		for (auto &j: a[i]) {
			cin >> j[0] >> j[1];
			if (j[1] > mp[j[0]]) {
				mp[j[0]] = j[1];
				cnt[j[0]] = 1;
			} 
			else if (j[1] == mp[j[0]]) {
				cnt[j[0]]++;
			}
		}
	}
	int res(0), flag(0);

	for (int i = 0; i < n; i++) {
		int check = 0;
		for (auto &j: a[i]) {
			if (mp[j[0]] == j[1] and cnt[j[0]] == 1) {
				check = 1;
			}
		}
		if (check == 0) 
			flag = 1;
		res += check;
	}
	res += flag;

	cout << res << '\n';

}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1), st(0);
  // cin >> t;
  for (int i = st; i < t + st; /*cout << "Case #" << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}