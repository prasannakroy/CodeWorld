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
#define int int64_t
#define span(a) a.begin(), a.end()

template<typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

const int mod = (int)1e9 + 7;

void solve() {
	int n, m, x, y, z;
	cin >> n >> m;
	vector<int> cnt(n + 1, 0), minlen(n + 1, INT_MAX), maxlen(n + 1, 0), dist(n + 1, LLONG_MAX);
	cnt[1] = 1;
	minlen[1] = maxlen[1] = dist[1] = 0;
	vector<array<int, 2>> gph[n + 1];
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		gph[x].push_back({y, z});
	}

	minheap<array<int, 2>> q;
	q.push({0, 1});
	while (!q.empty()) {
		auto t = q.top();
		q.pop();
		if (t[0] != dist[t[1]]) continue;
		for (auto &v: gph[t[1]]) {
			if (dist[v[0]] == t[0] + v[1]) {
				(cnt[v[0]] += cnt[t[1]]) %= mod;
				minlen[v[0]] = min(minlen[v[0]], minlen[t[1]] + 1);
				maxlen[v[0]] = max(maxlen[v[0]], maxlen[t[1]] + 1);
			}
			else if (dist[v[0]] > t[0] + v[1]) {
				dist[v[0]] = t[0] + v[1];
				cnt[v[0]] = cnt[t[1]];
				minlen[v[0]] = minlen[t[1]] + 1;
				maxlen[v[0]] = maxlen[t[1]] + 1;
				q.push({dist[v[0]], v[0]});
			}
		}
	}
	cout << dist[n] << " " << cnt[n] << " " << minlen[n] << " " << maxlen[n] << "\n";
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