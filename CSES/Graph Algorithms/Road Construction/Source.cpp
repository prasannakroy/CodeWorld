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

vector<int> dsu, sze;

void init(int n) {
	dsu.resize(n + 1);
	iota(span(dsu), 0);
	sze.assign(n + 1, 1);
}

int root(int a) {
	return dsu[a] == a ? dsu[a] : dsu[a] = root(dsu[a]);
}

void join(int a, int b) {
	a = root(a);
	b = root(b);
	if (a == b) return;
	if (sze[a] < sze[b]) swap(a, b);
	dsu[b] = a;
	sze[a] += sze[b];
}

void solve() {
	int n, m, x, y;
	cin >> n >> m;
	init(n);
	int sz(1), cnt(n);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		x = root(x);
		y = root(y);
		if (x == y) cout << cnt << " " << sz << "\n";
		else {
			join(x, y);
			cnt--;
			sz = max(sz, sze[root(x)]);
			cout << cnt << " " << sz << "\n";
		}
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