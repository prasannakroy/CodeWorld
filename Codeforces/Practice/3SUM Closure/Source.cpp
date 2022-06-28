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
	vc<int> a(n);
	map<int, int> mp;
	int cntp(0), cntn(0);
	for (auto &i: a) {
		cin >> i;
		if (i > 0) 
			cntp++;
		if (i < 0) 
			cntn++;
		mp[i] = 1;
	}
	if (cntp > 2 or cntn > 2) 
		return void(cout << "NO\n");
	vc<int> lst;
	for (auto &i: a) 
		if (i) 
			lst.push_back(i);
	if (mp[0]) 
		lst.push_back(0);
	int m = lst.size();
	for (int i = 0; i < m; i++) 
		for (int j = i + 1; j < m; j++) 
			for (int k = j + 1; k < m; k++) if (!mp[lst[i] + lst[j] + lst[k]]) 
				return void(cout << "NO\n");
	cout << "YES\n";
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1), st(0);
  cin >> t;
  for (int i = st; i < t + st; /*cout << "Case #" << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}