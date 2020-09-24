/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class centroidDecomposition {
    public:
    int n;
    std::vector<set<int>> tr;
    vector<int> level, sze;
    centroidDecomposition(vector<set<int>> &tr, int n) : tr(tr), n(n) {
        level.assign(n + 1, 1);
        sze.assign(n + 1, 1);
        decompose(1, 0);
    }
    int dfs(int u, int p) {
        sze[u] = 1;
        for (auto &v: tr[u]) if (v != p) sze[u] += dfs(v, u);   
        return sze[u];
    }
    int centroid(int sz, int u, int p) {
        for(auto &v: tr[u]) if(v != p) if(sze[v] > (sz >> 1)) return centroid(sz, v, u);
        return u;
    }
    void decompose(int u, int p) {
        dfs(u, p);
        int c = centroid(sze[u], u, p);
        level[c] = p;
        for(auto &v: tr[c]) {
            tr[v].erase(c);
            decompose(v, p + 1);
        }
    }
};

void solve() {
    int n, x, y;
    cin >> n;
    vector<set<int>> tr(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        tr[x].insert(y);
        tr[y].insert(x);
    }
    centroidDecomposition *tree = new centroidDecomposition(tr, n);
    for (int i = 1; i <= n; i++) cout << (char)((tree->level)[i] + 'A') << " ";
    cout << "\n";
}

signed main() {
    __AcHiLlEs
  
    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
