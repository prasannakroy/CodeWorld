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
	map<int, int> mp;

	int sum(0), mx(0);
	for (auto &i: a) {
		cin >> i;
		sum += i;
		mp[i]++;
		mx = max(mx, mp[i]);
	}

	if (n == 1) 
		return void(cout << "NO\n");

	if ((sum / n) >= 2) 
		return void(cout << "YES\n");

	int dif = sum - mp[1];
	int cnt = n - mp[1];

	if (dif - cnt < mp[1])
		cout << "NO\n";
	else 
		cout << "YES\n";

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