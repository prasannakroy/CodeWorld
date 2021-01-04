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

void solve() {
	int n, m, x, y;
	cin >> n >> m;
	char c1, c2;
	vc<int> vis(2 * m + 1, 0), res(2 * m + 1, 0), lst;
	vector<char> sol(m + 1, '-');
	vc<vc<vc<int>>> gph(2, vc<vc<int>>(2 * m + 1));

	auto convert = [&](int x, char y, char z) {
		if (z == '+' and y == '-') x += m;
		else if (z == '-' and y == '+') x += m;
		return x;
	};

	for (int i = 0; i < n; i++) {
		cin >> c1 >> x >> c2 >> y;
		gph[0][convert(x, c1, '-')].push_back(convert(y, c2, '+'));
		gph[0][convert(y, c2, '-')].push_back(convert(x, c1, '+'));
		gph[1][convert(x, c1, '+')].push_back(convert(y, c2, '-'));
		gph[1][convert(y, c2, '+')].push_back(convert(x, c1, '-'));
	}

	int cnt(0);

	function<void(int, int)> dfs = [&] (int u, int t) {
		vis[u] = 1;
		for (auto &v: gph[t][u]) if (!vis[v]) dfs(v, t);
		if (t) res[u] =  cnt;
		else lst.push_back(u);
	};

	for (int i = 1; i <= 2 * m; i++) if (!vis[i]) dfs(i, 0);
	reverse(span(lst));
	fill(span(vis), 0);
	bool flag = 1;
	for (auto &i: lst) if (!vis[i]) cnt++, dfs(i, 1);

	for (int i = 1; i <= m; i++) {
		if (res[i] == res[i + m]) {
			flag = 0;
			break;
		}
		if (res[i] > res[i + m]) sol[i] = '+';
		else sol[i] = '-';
	}

	if (flag) for (int i = 1; i <= m; i++) cout << sol[i] << " ";
	else cout << "IMPOSSIBLE";
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