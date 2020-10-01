/*****************************
*  Author :: Prasanna Kumar  *
*****************************/
 
/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;
 
#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
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
 
void solve() {
    int n, x, y;
    cin >> n;
    vector<vector<int>> v(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> x;
        v[x + 1].push_back(i + 1);
        v[i + 1].push_back(x + 1);
    }
    LCA<int> tree(v, n);
    int m;
    cin >> m;
    int a[m];
    for (auto &i: a) cin >> i, i++;
    int u = a[0];
    for (int i = 1; i < m; i++) u = tree.lca(u, a[i]);
    cout << u - 1 << "\n";
}
 
signed main() {
 
    __AcHiLlEs
 
    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}