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
	int nc(0), pc(0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < 0) 
			nc++;
		else if (a[i] > 0)
			pc++;
	}

	vc<array<int, 2>> res;
	int mx, mn, mxIdx, mnIdx;

	if (pc) {
		auto posAr = a;
		mx = mn = a[0];
		mxIdx = mnIdx = 0;
		for (int i = 1; i < n; i++) {
			if (posAr[i] > mx) {
				mx = posAr[i];
				mxIdx = i;
			} 
			if (posAr[i] < mn) {
				mn = posAr[i];
				mnIdx = i;
			}
		}
		while (posAr[mxIdx] < abs(posAr[mnIdx])) {
			res.push_back({mxIdx, mxIdx});
			posAr[mxIdx] += posAr[mxIdx];
		}
		for (int i = 0; i < n; i++) {
			if (posAr[i] < 0) {
				res.push_back({i, mxIdx});
				posAr[i] += posAr[mxIdx];
			}
		}

		for (int i = 1; i < n; i++) {
			if (posAr[i] < posAr[i - 1]) {
				res.push_back({i, i - 1});
				posAr[i] += posAr[i - 1];
			}
		}
	}
	if (nc) {
		vc<array<int, 2>> resAux;
		auto negAr = a;
		for (auto &i: negAr) 
			i *= -1;

		mx = mn = negAr[0];
		mxIdx = mnIdx = 0;

		for (int i = 1; i < n; i++) {
			if (negAr[i] > mx) {
				mx = negAr[i];
				mxIdx = i;
			} 
			if (negAr[i] < mn) {
				mn = negAr[i];
				mnIdx = i;
			}
		}

		while (negAr[mxIdx] < abs(negAr[mnIdx])) {
			resAux.push_back({mxIdx, mxIdx});
			negAr[mxIdx] += negAr[mxIdx];
		}

		for (int i = 0; i < n; i++) {
			if (negAr[i] < 0) {
				resAux.push_back({i, mxIdx});
				negAr[i] += negAr[mxIdx];
			}
		}

		for (int i = n - 2; i >= 0; i--) {
			if (negAr[i] < negAr[i + 1]) {
				resAux.push_back({i, i + 1});
				negAr[i] += negAr[i + 1];
			}
		}
		if (pc) {
			if (resAux.size() < res.size()) 
				res = resAux;
		} else {
			res = resAux;
		}
	}

	cout << res.size() << '\n';
	for (auto &[x, y]: res) {
		cout << x + 1 << ' ' << y + 1 << '\n';
	}
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