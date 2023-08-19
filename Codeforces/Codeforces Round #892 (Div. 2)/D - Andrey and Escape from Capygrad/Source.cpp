// Author : Prasanna Kumar
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

	vc<array<int, 3>> lst;
	vc<array<int, 2>> a;
	int cnt(0);
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		lst.push_back({a, 0, i});
		lst.push_back({d, 1, i});
	}

	sort(span(lst));

	set<int> st;

	int l = 0, r = 0;

	for (auto &i: lst) {
		if (i[1] == 0) {
			if (st.empty()) 
				l = i[0];
			st.insert(i[2]);
		} else {
			r = i[0];
			st.erase(i[2]);
			if (st.empty()) 
				a.push_back({l, r});
		}
	}


	int q;
	cin >> q;

	function<int(int)> getRes = [&](int val) {
		int l = 0, r = a.size() - 1;
		while (l <= r) {
			int m = (r + l) / 2;
			if (a[m][0] > val) {
				r = m - 1;
			} else if (a[m][1] < val) {
				l = m + 1;
			} else 
				return a[m][1];
		}
		return -1ll;

	};

	while (q--) {
		int x;
		cin >> x;

		int res = getRes(x);
		cout << max(x, res) << ' ';
	}

	cout << '\n';



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