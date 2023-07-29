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

	vc<int> a(n);
	for (auto &i:a) 
		cin >> i;

	stack<int> st;

	function<bool(int, int)> lessThan = [&](int a, int b) {
		return a < b;
	};

	function<bool(int, int)> greaterThan = [&](int a, int b) {
		return a > b;
	};

	function<void(int, int, int, vc<int>&, function<bool(int, int)>)> preCompute = 
		[&](int s, int e, int inc, vc<int> &ar, function<bool(int, int)> cmp) {

			for (int i = s; i != e; i += inc) {
				while (!st.empty() and cmp(a[i], a[st.top()])) {
					ar[st.top()] = i;
					st.pop();
				}
				st.push(i);
			}

			while (!st.empty()) 
				st.pop();

	};

	vc<int> lMn(n, -1), rMn(n, n), lMx(n, -1), rMx(n, n);

	preCompute(0ll, n, 1ll, rMn, lessThan);
	preCompute(0ll, n, 1ll, rMx, greaterThan);
	preCompute(n - 1, -1ll, -1ll, lMn, lessThan);
	preCompute(n - 1, -1ll, -1ll, lMx, greaterThan);

	int res(0);

	for (int i = 0; i < n; i++) {
		int l = lMn[i] + 1;
		int r = rMn[i] - 1;
		int len1 = (i - l) + 1;
		int len2 = (r - i) + 1;

		if (len1 > len2) {
			int s = i + 1, e = r;
			vc<int> lst(len2 - 1, 0);

			for (int j = s; j <= e; j++) {
				int idx = lMx[j];
				if (idx < i) {
					if (idx < l) 
						lst[j - s] = len1;
					else 
						lst[j - s] = i - idx;
				} else {
					lst[j - s] = lst[idx - s];
				}
				res += lst[j - s];
			}
		} else {
			res += (len1 * len2);
			int s = l, e = i;
			vc<int> lst(len1);

			for (int j = e; j >= s; j--) {
				int idx = rMx[j];
				if (idx < i) {
					lst[j - s] = lst[idx - s];
				} else {
					if (idx > r) 
						lst[j - s] = len2;
					else 
						lst[j - s] = idx - i;
				}
				res -= lst[j - s];
			}
		}

	}
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