/*****************************
*  Author :: Πρασαννα Κ. Ροι  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i: a) cin >> i;
	vector<int> mn(n, -1), mx(n, -1);
	set<int> vis1, vis2;
	for (int i = 1; i <= n; i++) vis1.insert(i), vis2.insert(i);
	mn[0] = mx[0] = a[0];
	vis1.erase(a[0]);
	vis2.erase(a[0]);
	for (int i = 1; i < n; i++) if (a[i] != a[i - 1]) mn[i] = mx[i] = a[i], vis1.erase(a[i]), vis2.erase(a[i]);
	for (int i = 1, idx = 1; i < n; i++) if (mn[i] == -1) {
		while (vis1.find(idx) == vis1.end()) 
			idx++;
		mn[i] = idx;
		vis1.erase(idx);
	}
	for (int i = 1; i < n; i++) if (mx[i] == -1) {
		auto idx = vis2.lower_bound(mx[i - 1]);
		idx--;
		mx[i] = *idx;
		vis2.erase(idx);
	}
	for (auto &i: mn) cout << i << " ";
	cout << "\n";
	for (auto &i: mx) cout << i << " ";
	cout << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}