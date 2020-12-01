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

void solve() {
	int n, m, x, y;
	cin >> n >> m;
	vector<vector<int>> gph(n + 1);
	for (int i = 0; i < m; i++) cin >> x >> y, gph[x].push_back(y), gph[y].push_back(x);
	vector<int> vis(n + 1, -1);
	queue<int> q;
	bool flag = 1;
	for (int i = 1; i <= n; i++) {
		if (~vis[i]) continue;
		q.push(i);
		vis[i] = 0;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (auto &v: gph[u]) {
				if (~vis[v]) {
					if (vis[v] != (vis[u] ^ 1)) {
						flag = 0;
						break;
					}
					continue;
				} 
				vis[v] = vis[u] ^ 1;
				q.push(v);
			}
		}
	}
	if (!flag) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	for (int i = 1; i <= n; i++) cout << vis[i] + 1 << " ";
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