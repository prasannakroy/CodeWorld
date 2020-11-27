/*****************************
*  Author :: Prasanna Kumar  *
*****************************/
 
/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
using namespace std::chrono;
 
#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) a.begin(), a.end()
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)
 
vector<int> dsu, sz;
 
int root(int a) {
	return dsu[a] == a ? dsu[a] : dsu[a] = root(dsu[a]);
}
 
void join(int a, int b) {
	a = root(a);
	b = root(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	dsu[b] = a;
	sz[a] += sz[b];
}
 
void solve() {
	int n, m;
	cin >> n >> m;
	int cnt(0);
	vector<vector<int>> a(n, vector<int>(m, 0));
	char x;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			cin >> x;
			if (x != '#') a[i][j] = ++cnt;
		}
	dsu.assign(cnt + 1, 0);
	iota(span(dsu), 0);
	sz.assign(cnt + 1, 1);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			if (!a[i][j]) continue;
			if (j < m - 1 and a[i][j + 1]) join(a[i][j], a[i][j + 1]);
			if (i < n - 1 and a[i + 1][j]) join(a[i][j], a[i + 1][j]);
		}
	int res(0);
	for (int i = 1; i <= cnt; i++) res += (dsu[i] == i);
	cout << res << "\n";
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