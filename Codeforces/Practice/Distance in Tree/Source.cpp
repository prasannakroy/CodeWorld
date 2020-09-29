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

vector<int> prime;

template<typename t> 
class CentroidDecomposition {
public:
    t n, res;
    vector<vector<t>> tr;
    vector<t> sz, dead, dst;

    CentroidDecomposition(vector<vector<t>> &tr, t n) : tr(tr), n(n) {
        res = 0;
        sz.resize(n + 1);
        dead.assign(n + 1, 0);
        dst.assign(n + 1, 0);
        decompose(1, 0);
    }

    void subtree(t u, t p, t d, t val) {
        sz[u] = 1;
        for (auto &v: tr[u]) if (v != p and !dead[v]) {
            dst[d] += val;
            subtree(v, u, d + 1, val);
            sz[u] += sz[v];
        }
    }
    
    t centroid(t m, t u, t p) {
        for (auto &v: tr[u]) if (v != p and !dead[v]) if (sz[v] > (m >> 1)) return centroid(m, v, u);
        return u;
    }

    void decompose(t u, t p) {
        dst[0] = 1ll;
        subtree(u, p, 1, 0);
        t c = centroid(sz[u], u, p);
        dead[c] = 1;
        t r = compute(c, p, 1);
        res += r;
        for (auto &v: tr[c]) if (v != p and !dead[v]) decompose(v, c);
    }

    t compute(t c, t p, t d) {
        subtree(c, p, 1, 1);
        t r(0);
        for (auto &v: tr[c]) if (!dead[v]) {
            dst[1] -= 1;
            subtree(v, c, 2, -1);
            r += pathCount(d);
            r += cntDFS(v, c, d + 1);
            dst[1] += 1;
            subtree(v, c, 2, 1);
        }
        subtree(c, p, 1, -1);
        return r;
    }

    t cntDFS(t u, t p, t d) {
        t r(0);
        for (auto &v: tr[u]) if (!dead[v] and v != p){
            r += pathCount(d);
            r += cntDFS(v, u, d + 1);
        }
        return r;
    }

    t pathCount(t d) {
        t r = 0;
        for (auto &i: prime) {
            if (i - d > n) break;
            if (d > i) continue;
            if (!dst[i - d]) break;
            if (i == d) r += 2;
            else r += dst[i - d];
        }
        return r;
    }
};

void solve() {
    int n, k, x, y;
    cin >> n >> k;
    prime.push_back(k);
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    CentroidDecomposition<int> tree(adj, n);
    cout << (tree.res >> 1) << "\n";
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