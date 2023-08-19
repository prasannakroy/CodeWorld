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

vc<int> tr;

void update(int p, int l, int r, int idx) {
	if (l > r) 
		return;
	if (l == r) 
		return void(tr[p] = 1);

	int m = (l + r) / 2;
	if (idx <= m) 
		update(p * 2, l, m, idx);
	else 
		update((p * 2) + 1, m + 1, r, idx);
	tr[p] += 1;
}

int getSum(int p, int l, int r, int s, int e) {
	if (l > r or s > r or l > e) 
		return 0;

	if (s <= l and e >= r) 
		return tr[p];

	int m = (l + r) >> 1;
	return getSum(p * 2, l, m, s, e) + getSum((p * 2) + 1, m + 1, r, s, e);
}

void solve() {
	int n;
	cin >> n;
	
	vc<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}

	int mn = a[0];

	tr.assign((4 * n) + 1, 0);
	int res(0);

	for (int i = 1; i < n; i++) {
		int sum = getSum(1, 0, n - 1, 0, a[i] - 1);
		mn = min(mn, a[i]);
		if (a[i] != mn) {
			update(1, 0, n - 1, a[i]);
			if (!sum) 
				res++;
		} 
	}
	cout << res << '\n';
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