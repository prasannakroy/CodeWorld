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
	int n, m;
	cin >> n >> m;
	vc<int> a(m);
	vc<int> cnt(n, 0);

	multiset<int> st;
	int res(0);
	
	for (auto &i: a) {
		cin >> i;
		i--;
		cnt[i]++;
		res = max(res, cnt[i]);
	}

	for (auto &i: cnt) 
		st.insert(i);


	while (true) {
		int x = *st.begin();
		int y = *st.rbegin();
		if (y <= x + 2) 
			break;
		st.erase(st.begin());
		st.erase(--st.end());
		st.insert(x + 2);
		st.insert(y - 1);
	}

	cout << *st.rbegin() << '\n';


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