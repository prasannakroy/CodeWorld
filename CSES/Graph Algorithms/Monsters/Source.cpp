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
	int n, m, sx, sy;
	cin >> n >> m;
	vector<string> v(n);
	for (auto &i: v) cin >> i;
	queue<array<int, 4>> q;
	vector<vector<vector<int>>> dist(2, vector<vector<int>>(n, vector<int>(m, INT_MAX)));
	vector<vector<char>> parent(n, vector<char>(m));
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 'M') q.push({i, j, 0, 0});
			if (v[i][j] == 'A') sx = i, sy = j;
		}
	vector<array<int, 2>> df = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	vector<char> pr = {'D', 'U', 'R', 'L'};
	map<char, array<int, 2>> mp;
	mp['D'] = {-1, 0}, mp['U'] = {1, 0}, mp['L'] = {0, 1}, mp['R'] = {0, -1};
	function<void(int)> bfs = [&](int idx) {
		while (!q.empty()) {
			auto p = q.front();
			q.pop();
			if (p[0] < 0 or p[0] == n or p[1] < 0 or p[1] == m or v[p[0]][p[1]] == '#' or dist[idx][p[0]][p[1]] != INT_MAX) continue;
			parent[p[0]][p[1]] = 'A' + p[3];
			dist[idx][p[0]][p[1]] = p[2];
			for (int i = 0; i < 4; i++) q.push({p[0] + df[i][0], p[1] + df[i][1], p[2] + 1, pr[i] - 'A'});
		}
	};
	bfs(0);
	q.push({sx, sy, 0, 0});
	bfs(1);
	bool flag = 0;
	int tx(-1), ty(-1); 
	for (int i = 0; i < m; i++) {
		if (v[0][i] != '#' and dist[1][0][i] < dist[0][0][i]) {
			flag = 1, tx = 0, ty = i;
			break;
		}
		else if (v[n - 1][i] != '#' and dist[1][n - 1][i] < dist[0][n - 1][i]) {
			flag = 1, tx = n - 1, ty = i;
			break;
		}
	}
	if (!flag) for (int i = 0; i < n; i++) {
		if (v[i][0] != '#' and dist[1][i][0] < dist[0][i][0]) {
			flag = 1, tx = i, ty = 0;
			break;
		}
		else if (v[i][m - 1] != '#' and dist[1][i][m - 1] < dist[0][i][m - 1]) {
			flag = 1, tx = i, ty = m - 1;
			break;
		}
	}
	if (!flag) 
		cout << "NO\n";
	else {
		cout << "YES\n";
		string res("");
		while (tx != sx or ty != sy) {
		    res += parent[tx][ty];
		    tie(tx, ty) = make_tuple(tx + mp[parent[tx][ty]][0], ty + mp[parent[tx][ty]][1]);
		}
		reverse(span(res));
		cout << res.length() << "\n";
		cout << res << "\n";
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