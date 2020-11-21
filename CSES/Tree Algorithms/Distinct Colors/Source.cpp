/*****************************
*  Author :: Prasanna Kumar  *
*****************************/
 
/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;
 
#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) a.begin(), a.end()
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)
 
vector<vector<int>> tr;
vector<int> a;
vector<int> res;
 
void merge(set<int> &s1, set<int> &s2) {
	if (s1.size() < s2.size()) swap(s1, s2);
	for (auto &i: s2) if (s1.find(i) == s1.end()) s1.insert(i);
}
 
set<int> dfs(int u, int p) {
	set<int> r;
	r.insert(a[u - 1]);
	for (auto &v: tr[u]) if (v != p) {
		set<int> s = dfs(v, u);
		merge(r, s);
	}
	res[u - 1] = r.size();
	return move(r);
}
 
void solve() {
	int n, x, y;
	cin >> n;
	a.assign(n, 0);
	res.assign(n, 0);
	tr.assign(n + 1, vector<int>());
	for (int &i: a) cin >> i;
	for (int i = 1; i < n; i++) cin >> x >> y, tr[x].push_back(y), tr[y].push_back(x);
	dfs(1, 0);
	for (auto &i: res) cout << i << " ";
	cout << "\n";
}
 
signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif
 
    __AcHiLlEs
 
    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}