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

map<pair<int, int>, int> m;

auto merge(pair<int, int> a, pair<int, int> b) {
    pair<int, int> res;
    res.first = max(a.first, b.first);
    res.second = min(a.second, b.second);
    return res;
}

template<typename t> 
class LCA{
public:
    t l, n, timer;
    vector<vector<t>> tr, parent, dst;
    vector<t> bgn, ed, level;

    LCA(vector<vector<t>> &tr, t n) : tr(tr), n(n) {
        timer = 0;
        l = ceil(log2(n));
        bgn.resize(n + 1);
        ed.resize(n + 1);
        level.resize(n + 1);
        parent.resize(n + 1, vector<t>(l + 1));
        dst.assign(n + 1, vector<t>(l + 1, 0));
        precomputeDFS(1, 1, 0);
    }

    void precomputeDFS(t u, t p, t lvl) {
        bgn[u] = ++timer;
        parent[u][0] = p;
        int d = m[{max(u, p), min(u, p)}];
        dst[u][0] = d;
        level[u] = lvl;
        for (int i = 1; i <= l; i++) {
            parent[u][i] = parent[parent[u][i - 1]][i - 1];
            dst[u][i] = dst[u][i - 1] + dst[parent[u][i - 1]][i - 1];
        }
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
        if (!k) return 0;
        int d = 0;
        int v = u;
        for (t i = 0; i <= l; i++) if (k & (1 << i)) {
            d += dst[v][i];
            v = parent[v][i];
        }
        return d;
    }

    t dist(t u, t v) {
        return (level[u] + level[v] - (level[lca(u,v)] << 1));
    }
};

void solve() {
    int n, x, y, d;
    cin >> n;
    vector<vector<int>> v(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> x >> y >> d;
        x++, y++;
        v[x].push_back(y);
        v[y].push_back(x);
        m[{max(x, y), min(x, y)}] = d;
    }
    LCA<int> tree(v, n);
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        x++, y++;
        int a = tree.lca(x, y);
        int l1 = tree.level[x] - tree.level[a];
        int l2 = tree.level[y] - tree.level[a];
        cout << tree.kParent(x, l1) + tree.kParent(y, l2) << "\n";
    }
}

signed main() {
    // #ifndef ONLINE_JUDGE 
    //     __AnAkLuSmOs    
    // #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}