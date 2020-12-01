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
	int n, m, x, y;
	cin >> n >> m;
	dsu.assign(n + 1, -1);
	iota(span(dsu), 0);
	sz.assign(n + 1, 1);
	for (int i = 0; i < m; i++) cin >> x >> y, join(x, y);
	vector<int> v;
	for (int i = 1; i <= n; i++) if (dsu[i] == i) v.push_back(i);
	cout << v.size() - 1 << "\n";
	for (int i = 1; i < v.size(); i++) cout << v[0] << " " << v[i] << "\n";
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