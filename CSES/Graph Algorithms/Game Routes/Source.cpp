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

const int mod = (int)1e9 + 7;

void solve() {
	int n, m, x, y;
	cin >> n >> m;
	vector<int> cnt(n + 1, 0), deg(n + 1, 0), gph[n + 1];
	for (int i = 0; i < m; i++) cin >> x >> y, gph[x].push_back(y), deg[y]++;
	queue<int> q;
	for (int i = 1; i <= n; i++) if (!deg[i]) q.push(i);
	cnt[1] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto &v: gph[u]) {
			deg[v]--;
			(cnt[v] += cnt[u]) %= mod;
			if (!deg[v]) q.push(v);
		}
	}
	cout << cnt[n] << "\n";
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