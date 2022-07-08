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
	vc<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	n++;

	vc<int> pref(n, 0);

	pref[0] = a[0];
	for (int i = 1; i < n; i++) 
		pref[i] = pref[i - 1] + a[i];

	vc<vc<int>> prefMx(n + 1, vc<int>(30));
	vc<vc<int>> prefMn(n + 1, vc<int>(30));
	vc<int> lg(n + 1, 0);
	
	lg[1] = 0;
	for (int i = 2; i <= n; i++) 
		lg[i] = lg[i / 2] + 1;

	for (int i = 0; i < n; i++) {
		prefMx[i][0] = pref[i];
		prefMn[i][0] = pref[i];
	}

	for (int j = 1; j < 30; j++)
    for (int i = 0; i + (1 << j) <= n; i++) {
    	prefMn[i][j] = min(prefMn[i][j-1], prefMn[i + (1 << (j - 1))][j - 1]);
    	prefMx[i][j] = max(prefMx[i][j-1], prefMx[i + (1 << (j - 1))][j - 1]);
    }

  function<int(int, int)> getRangeMin = [&](int l, int r) {
  	if (l > r) 
  		return 0ll;
  	int j = lg[r - l + 1];
  	int mn = min(prefMn[l][j], prefMn[r - (1 << j) + 1][j]);
  	return mn;
  };

  function<int(int, int)> getRangeMax = [&](int l, int r) {
  	if (l > r) 
  		return 0ll;
  	int j = lg[r - l + 1];
  	int mx = max(prefMx[l][j], prefMx[r - (1 << j) + 1][j]);
  	return mx;
  };

  stack<int> st;
  vc<int> nxtMx(n, n);

  for (int i = 0; i < n; i++) {
  	while (!st.empty() and a[i] > a[st.top()]) {
  		nxtMx[st.top()] = i;
  		st.pop();
  	}
  	st.push(i);
  }
  while (!st.empty()) 
  	st.pop();

  vc<int> prevMx(n, -1);

  for (int i = n - 1; i >= 0; i--) {
  	while (!st.empty() and a[i] > a[st.top()]) {
  		prevMx[st.top()] = i;
  		st.pop();
  	}
  	st.push(i);
  }

  for (int i = 0; i < n; i++) if (a[i] > 0) {
  	int l = prevMx[i];
  	int r = nxtMx[i];
  	int sum = 0;
  	sum = getRangeMax(i, r - 1) - getRangeMin(l + 1, i - 1);
  	if (sum > a[i]) 
  		return void(cout << "NO\n");
  }
  cout << "YES\n";

}

signed main() {
  // auto prefMnart = high_resolution_clock::now();
  __AcHiLlEs

  int t(1), prefMn(0);
  cin >> t;
  for (int i = prefMn; i < t + prefMn; /*cout << "Case #" << i << ": ",*/ solve(), i++);
  // auto prefMnop = high_resolution_clock::now();
  // double duration = duration_caprefMn<microseconds>(prefMnop - prefMnart).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}