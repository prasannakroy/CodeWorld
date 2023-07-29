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
	
	vc<int> a(n), idx(n + 1), lMx(n), rMx(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		idx[a[i]] = i;
	}

	stack<int> st;

	for (int i = 0; i < n; i++) {
		while (!st.empty() and a[i] > a[st.top()]) {
			rMx[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}

	while (!st.empty()) {
		rMx[st.top()] = n;
		st.pop();
	}

	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() and a[i] > a[st.top()]) {
			lMx[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}

	while (!st.empty()) {
		lMx[st.top()] = -1;
		st.pop();
	}

	int res(0);

	for (int i = 0; i < n; i++) {
		int l = lMx[i] + 1;
		int r = rMx[i] - 1;
		int st1 = l, ed1 = i - 1, st2 = i + 1, ed2 = r;
		if (i - l > r - i) {
			swap(st1, st2);
			swap(ed1, ed2);
		}

		for (int j = st1; j <= ed1; j++) {
			int dif = a[i] - a[j];
			if (idx[dif] >= st2 and idx[dif] <= ed2) 
				res++;
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