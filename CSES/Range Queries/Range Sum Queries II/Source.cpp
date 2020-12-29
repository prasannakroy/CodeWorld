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

vc<int> tr, a;

void build(int l, int r, int p = 1) {
	if (l > r) return;
	if (l == r) return void(tr[p] = a[l]);

	int m = (l + r) >> 1;
	build(l, m, p << 1);
	build(m + 1, r, (p << 1) | 1);
	tr[p] = tr[(p << 1)] + tr[(p << 1) | 1];
}

void update(int l, int r, int idx, int p = 1) {
	if (l > r) return;
	if (l == r and r == idx) return void(tr[p] = a[idx]);

	int m = (l + r) >> 1;
	if (idx <= m) update(l, m, idx, p << 1);
	else update(m + 1, r, idx, (p << 1) | 1);
	tr[p] = tr[p << 1] + tr[(p << 1) | 1];
}

int query(int l, int r, int s, int e, int p = 1) {
	if (l > r or l > e or r < s or s > e) return 0;
	if (s <= l and r <= e) return tr[p];
	int m = (l + r) >> 1;
	return query(l, m, s, e, p << 1) + query(m + 1, r, s, e, (p << 1) | 1);
}

void solve() {
	int n, q, t, x, y;
	cin >> n >> q;
	a.resize(n);
	tr.resize((n << 2) + 1);
	for (auto &i: a) cin >> i;

	build(0, n - 1);
	
	while (q--) {
		cin >> t >> x >> y;
		if (t - 1) cout << query(0, n - 1, x - 1, y - 1) << '\n';
		else a[x - 1] = y, update(0, n - 1, x - 1);
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