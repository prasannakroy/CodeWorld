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

void solve() {
	int n, m, k, x, y, z;
	cin >> n >> m >> k;
	vector<pair<int, int>> gph[n + 1];
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		gph[x].push_back({y, z});
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	vector<int> cnt(n + 1, 0);
	q.push({0, 1});
	int c(0);
	while (!q.empty()) {
		auto p = q.top();
		q.pop();
		cnt[p.second]++;
		if (cnt[p.second] > k) continue;
		if (p.second == n) {
			c++;
			cout << p.first << " ";
			if (c == k) return;
		}
		for (auto &u: gph[p.second]) 
			if (cnt[u.first] < k) q.push({u.second + p.first, u.first});
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