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
	bool flag(0);
	cin >> n >> m;
	set<int> gph[n + 1];
	for (int i = 0; i < m; i++) cin >> x >> y, gph[x].insert(y), gph[y].insert(x);
	for (int i = 1; i <= n; i++) 
		flag |= (gph[i].size() & 1);
	if (flag) return void(cout << "IMPOSSIBLE");
	
	stack<int> st;
	vc<int> res;
	st.push(1);
	while (!st.empty()) {
		int u = st.top();
		if (gph[u].empty()) {
			res.push_back(u);
			st.pop();
		}
		else {
			int v = *gph[u].begin();
			gph[u].erase(v);
			gph[v].erase(u);
			st.push(v);
		}
	}
	for (auto &i: gph) flag |= i.size();
	if (flag) return void(cout << "IMPOSSIBLE"); 
	for (int &i : res) cout << i << " ";
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