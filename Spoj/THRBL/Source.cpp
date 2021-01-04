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
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) a.begin(), a.end()

template<typename t>
using vc = vector<t>;

void solve() {
	int n, q;
	cin >> n >> q;
	int ln = log2(n) + 1;
	vc<int> a(n), lg(n + 1);
	lg[1] = 0;
	for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
	vc<vc<int>> sp(n, vc<int>(ln + 1));
	for (int i = 0; i < n; i++) cin >> a[i], sp[i][0] = a[i];
	for (int j = 1; j <= ln; j++) 
		for (int i = 0; i + (1 << j) <= n; i++) 
			sp[i][j] = max(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
	int cnt(0);
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		int st = l;
		if (l > r) swap(l, r);
		l++, r--;
		if (l > r) {
			cnt++;
			continue;
		}
		int idx = lg[r - l + 1];
		int mx = max(sp[l][idx], sp[r - (1 << idx) + 1][idx]); 
		if (mx <= a[st]) cnt++;
	}
	cout << cnt << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}