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
#define MAX 1000000

template<typename t> 
class LCA{
public:
	t l, n, timer;
	vector<vector<t>> tr, parent;
	vector<t> bgn, ed, level;

	LCA(vector<vector<t>> &tr, t n) : tr(tr), n(n) {
		timer = 0;
		l = ceil(log2(n));
		bgn.resize(n + 1);
		ed.resize(n + 1);
		level.resize(n + 1);
		parent.resize(n + 1, vector<t>(l + 1));
		precomputeDFS(1, 1, 0);
	}

	void precomputeDFS(t u, t p, t lvl) {
		bgn[u] = ++timer;
		parent[u][0] = p;
		level[u] = lvl;
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

template<typename t> 
class CentroidDecomposition {
public:
	t n;
	vector<vector<t>> tr;
	vector<t> sz, parent, dead, record;
	CentroidDecomposition (vector<vector<t>> &tr, t n) : tr(tr), n(n) {
		sz.assign(n + 1, 1);
		dead.assign(n + 1, 0);
		parent.assign(n + 1, 0);
		record.assign(n + 1, MAX);
		decompose(1, 0);
	}

	t subtree (t u, t p) {
		sz[u] = 1;
		for (auto &v: tr[u]) if (v != p and !dead[v]) sz[u] += subtree(v, u);
		return sz[u];
	}

	t centroid (t m, t u, t p) {
		for (auto &v: tr[u]) if (v != p and !dead[v]) 
			if (sz[v] > (m >> 1)) return centroid(m, v, u);
		return u;
	}

	void decompose (t u, t p) {
		subtree(u, p);
		t c = centroid(sz[u], u, p);
		parent[c] = p;
		dead[c] = 1;
		for (auto &v: tr[c]) if (!dead[v]) 
			decompose(v, c);
	}
};

void solve() {
	int n, q, x, y;
	cin >> n >> q;
	vector<vector<int>> v(n + 1);
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	LCA<int> tr1(v, n);
	CentroidDecomposition<int> tr2(v, n);

	function<void(int)> update = [&](int u) {
		tr2.record[u] = 0;
		for (int v = u; v; v = tr2.parent[v]) {
			int d = tr1.dist(u, v);
			tr2.record[v] = min(d, tr2.record[v]);
		}
	};

	auto query = [&](int u) {
		int d(tr2.record[u]);
		for (int v = u; v; v = tr2.parent[v]) {
			int x = tr1.dist(u, v) + tr2.record[v];
			d = min(d, x);
		}
		return d;
	};
	
    update(1);
    
	for (int i = 0; i < q; i++) {
		int t, u;
		cin >> t >> u;
		if (t == 1) update(u);
		else cout << query(u) << "\n";
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