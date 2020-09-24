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

template<typename t> 
class LCA{
public:
	t l, n, timer;
	vector<vector<t>> tr, parent, lvt;
	vector<t> bgn, ed, level, vis;

	LCA(vector<vector<t>> &tr, t n) : tr(tr), n(n) {
		timer = 0;
		l = ceil(log2(n));
		bgn.resize(n + 1);
		ed.resize(n + 1);
		level.resize(n + 1);
		lvt.resize(n + 1);
		parent.resize(n + 1, vector<t>(l + 1));
	}

	void precomputeDFS(t u, t p, t lvl) {
		bgn[u] = ++timer;
		parent[u][0] = p;
		level[u] = lvl;
		lvt[lvl].push_back(timer);
		for (int i = 1; i <= l; i++) parent[u][i] = parent[parent[u][i - 1]][i - 1];
		for (auto &v: tr[u]) if (v != p) precomputeDFS(v, u, lvl + 1);
		ed[u] = ++timer;
	}

	bool isAncestor (t u, t v) {
		return bgn[u] <= bgn[v] and ed[u] >= ed[v];
	}

	t lca(t u, t v) {
		if (isAncestor(u, v)) return u;
		if (isAncestor(v, u)) return v;
		for (t i = l; i >= 0; i--) if (!isAncestor(parent[u][i], v)) u = parent[u][i];
		return parent[u][0];
	}
	
	t kParent(t u, t k) {
	    t r = u;
	    for (t i = 0; i <= l; i++) if (k & (1 << i)) r = parent[r][i];
	    return r;
	}

	t dist(t u, t v) {
		return (level[u] + level[v] - (level[lca(u,v)] << 1));
	}
};

void solve() {
	int n, q, x, y;
	cin >> n;
	vector<vector<int>> v(n + 1);
	vector<int> p(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		if (p[i]) {
			v[p[i]].push_back(i);
			v[i].push_back(p[i]);
		}
	}
	LCA<int> tree(v, n);
	for (int i = 1; i <= n; i++) if (!p[i]) tree.precomputeDFS(i, 0, 0);
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> x >> y;
		int lvl = tree.level[x];
		if (lvl < y) {
			cout << 0 << " ";
			continue;
		}
		int p = tree.kParent(x, y);
		int st = lower_bound(tree.lvt[lvl].begin(), tree.lvt[lvl].end(), tree.bgn[p]) - tree.lvt[lvl].begin();
		int en = lower_bound(tree.lvt[lvl].begin(), tree.lvt[lvl].end(), tree.ed[p]) - tree.lvt[lvl].begin();
		cout << en - st - 1 << " ";
	}
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