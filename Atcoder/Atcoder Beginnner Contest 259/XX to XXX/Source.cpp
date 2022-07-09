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
	string s, t;
	cin >> s >> t;
	vc<array<int, 2>> a, b;
	int cnt(1);
	for (int i = 1; i < s.length(); i++) {
		if (s[i] != s[i - 1]) {
			a.push_back({s[i - 1] - 'a', cnt});
			cnt = 1;
		}
		else 
			cnt++;
	}
	a.push_back({s[s.length() - 1] - 'a', cnt});
	cnt = 1;
	for (int i = 1; i < t.length(); i++) {
		if (t[i] != t[i - 1]) {
			b.push_back({t[i - 1] - 'a', cnt});
			cnt = 1;
		}
		else 
			cnt++;
	}
	b.push_back({t[t.length() - 1] - 'a', cnt});

	// for (auto &i: a) 
	// 	cout << i[0] << ' ' << i[1] << '\n';
	// for (auto &i: b) 
	// 	cout << i[0] << ' ' << i[1] << '\n';

	if (a.size() != b.size()) 
		return void(cout << "No\n");

	for (int i = 0; i < a.size(); i++) {
		if (a[i][0] != b[i][0] or a[i][1] > b[i][1] or (a[i][1] == 1 and b[i][1] != 1)) 
			return void(cout << "No\n");
	}
	cout << "Yes\n";

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