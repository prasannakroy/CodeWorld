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
	string s;
	cin >> s;
	int n = s.length();
	int prefLen = 0;
	for (int i = 0, j = n - 1; i <= j; i++, j--) {
		if (s[i] != s[j]) {
			prefLen = i;
			break;
		}
		if (i == j) 
			return void(cout << s << '\n');
	}

	string t = "";

	for (int i = prefLen; i < n - prefLen; i++) 
		t += s[i];

	string a = "?";

	function<int()> compute = [&]() {
		int m = a.length();
		vc<int> lps(m, 0);

		for (int i = 1; i < m; i++) {
			int len = lps[i - 1];
			while (len and a[len] != a[i]) 
				len = lps[len - 1];
			if (a[i] == a[len]) 
				len++;
			lps[i] = len;
		}
		return lps[m - 1];
	};

	a = t + a;
	reverse(span(t));
	a += t;
	int p = compute();
	a = t + "?";
	reverse(span(t));
	a += t;
	int q = compute();

	string pref = "";
	string suf = "";
	a = "";
	for (int i = 0; i < prefLen; i++) 
		a += s[i];
	pref = a;

	if (p < q) {
		for (int i = n - prefLen - q; i < n - prefLen; i++) 
			suf += s[i];
	} 
	else {
		for (int i = prefLen; i < prefLen + p; i++) 
			pref += s[i];
	}
	for (int i = n - prefLen; i < n; i++) 
		suf += s[i];

	cout << pref + suf << '\n';

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