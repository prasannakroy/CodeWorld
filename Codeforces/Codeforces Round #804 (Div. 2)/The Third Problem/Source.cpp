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

const int mod = 1e9 + 7;

vc<int> factorial(100001, 1);

int power(int a, int b) {
	int res(1);
	while (b) {
		if (b & 1) 
			(res *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return res;
}

int invMod(int a) {
	return power(a, mod - 2);
}

void precompute() {
	for (int i = 1; i < 100001; i++) 
		factorial[i] = (factorial[i - 1] * i) % mod;
}

int nCr(int n, int r) {
	int res = factorial[n];
	(res *= invMod(factorial[r])) %= mod;
	(res *= invMod(factorial[n - r])) %= mod;
	return res;
}

void solve() {
	int n;
	cin >> n;
	vc<int> a(n);
	vc<int> idx(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		idx[a[i]] = i;
	}
	int curMex = 1;
	int l = idx[0];
	int r = idx[0];
	vc<int> vis(n + 1, 0);
	vis[0] = 1;
	int res(1);
	int sz = 0;
	while (curMex != n) {
		int tIdx = idx[curMex];
		sz--;
		if (tIdx > r) {
			for (int i = r + 1; i <= tIdx; i++) {
				vis[a[i]] = 1;
				sz++;
			}
			r = tIdx;
		}
		else {
			for (int i = tIdx; i < l; i++) {
				vis[a[i]] = 1;
				sz++;
			}
			l = tIdx;
		}
		for (int i = curMex; i <= n; i++) if (!vis[i]) {
			int dif = i - curMex - 1;
			(res *= ((nCr(sz, dif) * factorial[dif]) % mod)) %= mod;
			sz -= dif;
			curMex = i;
			break;
		}
	}
	res *= factorial[sz];
	cout << res << '\n';
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  precompute();

  int t(1), st(0);
  cin >> t;
  for (int i = st; i < t + st; /*cout << "Case #" << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}