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
	int n, m, cnt(0);
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m, 0));
	map<int, pair<int, int>> mp;
	int s, e;
	for (int i = 0; i < n; i++) {
		string st;
		cin >> st;
		for (int j = 0; j < m; j++) {
			if (st[j] != '#') {
			    v[i][j] = ++cnt, mp[cnt] = {i, j};
			}
			if (st[j] == 'A') s = cnt;
			if (st[j] == 'B') e = cnt;
		}
	}
	vector<vector<int>> gph(cnt + 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!v[i][j]) continue;
			if (i > 0 and v[i - 1][j]) gph[v[i][j]].push_back(v[i - 1][j]);
			if (j > 0 and v[i][j - 1]) gph[v[i][j]].push_back(v[i][j - 1]);
			if (i + 1 < n and v[i + 1][j]) gph[v[i][j]].push_back(v[i + 1][j]);
			if (j + 1 < m and v[i][j + 1]) gph[v[i][j]].push_back(v[i][j + 1]);
		}
	}
	vector<int> dist(cnt + 1, INT_MAX), parent(cnt + 1, -1);
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto &v: gph[u]) {
			if (dist[u] + 1 < dist[v]) {
				parent[v] = u;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		} 
	}
	if (dist[e] == INT_MAX) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	vector<int> path;
	path.push_back(e);
	int x = e;
	while (parent[x] != -1) {
		path.push_back(parent[x]);
		x = parent[x];
	}
	reverse(span(path));
	string res("");
	for (int i = 1; i < path.size(); i++) {
		int x1 = mp[path[i - 1]].first;
		int y1 = mp[path[i - 1]].second;
		int x2 = mp[path[i]].first;
		int y2 = mp[path[i]].second;
		if (x1 > x2) res += "U";
		else if (x1 < x2) res += "D";
		else if (y1 > y2) res += "L";
		else if (y1 < y2) res += "R";
	}
	cout << res.length() << "\n";
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