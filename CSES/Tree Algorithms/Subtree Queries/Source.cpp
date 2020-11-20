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
vector<int> bgn, ed, bit, val;
int n, timer;

void update(int idx, int val) {
	for (; idx < 2*n; idx |= (idx + 1)) bit[idx] += val;
}

int query(int r, int l = -1) {
	if (~l) return query(r) - query(l - 1);
	int sm = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1) sm += bit[r];
	return sm;
}

void dfs(int u, int p = 0) {
	update(timer, val[u]);
	bgn[u] = timer++;
	for (auto &v: tr[u]) if (v != p) dfs(v, u);
	update(timer, val[u]);
	ed[u] = timer++;
}

void solve() {
	int q, a, b;
	cin >> n >> q;
	tr.assign(n + 1, vector<int>());
	bgn.assign(n + 1, 0);
	ed.assign(n + 1, 0);
	bit.assign(2 * n, 0);
	val.assign(n + 1, 0);
	timer = 0;
	for (int i = 1; i <= n; i++) cin >> val[i]; 
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		tr[a].push_back(b);
		tr[b].push_back(a);
	}
	dfs(1);
	while (q--) {
		int t;
		cin >> t;
		if (t - 1) {
			cin >> a;
			cout << query(ed[a], bgn[a]) / 2 << "\n";
		}
		else {
			cin >> a >> b;
			int d = b - val[a];
			val[a] = b;
			update(bgn[a], d);
			update(ed[a], d);
		}
	}
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