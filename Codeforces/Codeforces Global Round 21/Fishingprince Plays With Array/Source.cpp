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

stack<array<int, 2>> getCompressed(vc<int> &a, int m) {
	stack<array<int, 2>> st;
	for (auto &i: a) {
		if (i % m) {
			if (st.empty()) {
				st.push({i, 1});
				continue;
			}
			auto tp = st.top();
			st.pop();
			if (tp[0] == i) {
				tp[1]++;
				st.push(tp);
			}
			else {
				st.push(tp);
				st.push({i, 1});
			}
		}
		else {
			int val = i;
			int cnt = 1;
			while (val % m == 0) {
				val /= m;
				cnt *= m;
			}
			if (st.empty()) {
				st.push({val, cnt});
			}
			else {
				auto tp = st.top();
				st.pop();
				if (tp[0] == val) {
					tp[1] += cnt;
					st.push(tp);
				}
				else {
					st.push(tp);
					st.push({val, cnt});
				}
			}
		}
	}
	return st;

}

void solve() {
	int n, d;
	cin >> n >> d;
	vc<int> a(n);
	for (auto &i: a) 
		cin >> i;
	int m;
	cin >> m;
	vc<int> b(m);
	for (auto &i: b) 
		cin >> i;
	auto p = getCompressed(a, d);
	auto q = getCompressed(b, d);
	if (p.size() != q.size()) 
		return void(cout << "No\n");
	while (!p.empty()) {
		if (p.top()[0] != q.top()[0] or p.top()[1] != q.top()[1]) 
			return void(cout << "No\n");
		p.pop();
		q.pop();
	}
	cout << "Yes\n";
	
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