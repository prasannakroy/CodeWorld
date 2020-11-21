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

int n, l, timer;
vector<int> bit, bgn, ed;
vector<vector<int>> tr, parent;

void precomputeDFS(int u = 1, int p = 1) {
	bgn[u] = timer++;
	parent[u][0] = p;
	for (int i = 1; i <= l; i++) parent[u][i] = parent[parent[u][i - 1]][i - 1];
	for (auto &v: tr[u]) if (v != p) precomputeDFS(v, u);
	ed[u] = timer++;
}

bool isAncestor (int u, int v) {
	return bgn[u] <= bgn[v] and ed[u] >= ed[v];
}

int lca(int u, int v) {
	if (isAncestor(u, v)) return u;
	if (isAncestor(v, u)) return v;
	for (int i = l; i >= 0; i--) if (!isAncestor(parent[u][i], v)) u = parent[u][i];
	return parent[u][0];
}

void update(int idx, int val = 1) {
	for (; idx <= 2*n; idx |= (idx + 1)) bit[idx] += val;
}

int query(int r, int l = -1) {
	if (~l) return query(r) - query(l - 1);
	int sm(0);
	for (; r >= 0; r = (r & (r + 1)) - 1) sm += bit[r];
	return sm;
}

void solve() {
	int m, x, y;
	cin >> n >> m;
	l = ceil(log2(n));
	tr.assign(n + 1, vector<int>());
	parent.assign(n + 1, vector<int>(l + 1, 0));
	bgn.assign(n + 1, 0);
	ed.assign(n + 1, 0);
	bit.assign(2 * n + 1, 0);
	for (int i = 1; i < n; i++) cin >> x >> y, tr[x].push_back(y), tr[y].push_back(x); 
	precomputeDFS();
	while (m--) {
		cin >> x >> y;
		int v = lca(x, y);
		update(bgn[v]);
		update(bgn[v] + 1, 1);
		update(bgn[x] + 1, -1);
		update(bgn[y] + 1, -1);
	}
	for (int i = 1; i <= n; i++) {
		x = query(bgn[i]);
		y = query(ed[i]);
		cout << x - y << " ";
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