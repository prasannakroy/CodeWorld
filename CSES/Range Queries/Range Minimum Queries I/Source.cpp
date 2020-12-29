/*****************************
*  Author :: Prasanna Kumar  *
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
 
vector<int> tr, a;
 
void build(int l, int r, int p = 1) {
	if (l > r) return;
	if (l == r) return void(tr[p] = a[l]);
	int m = (l + r) >> 1;
	build(l, m, p << 1);
	build(m + 1, r, (p << 1) | 1);
	tr[p] = min(tr[p << 1], tr[(p << 1) | 1]);
}
 
int query(int l, int r, int s, int e, int p = 1) {
	if (l > e or s > r or l > r) return INT_MAX;
	if (s <= l and e >= r) return tr[p];
 
	int m = (l + r) >> 1;
	return min(query(l, m, s, e, p << 1), query(m + 1, r, s, e, (p << 1) | 1));
}
 
void solve() {
	int n, q;
	cin >> n >> q;
	a.assign(n, 0);
	tr.assign(24 * n, 0);
	for (auto &i: a) cin >> i;
	build(0, n - 1);
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << query(0, n - 1, l - 1, r - 1) << "\n";
	}
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