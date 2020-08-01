/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define i_64 long long

std::vector<int> tr[100001];
int p[100001], h[100001], happy[100001], sad[100001], lp[100001];
int l(0);

bool dfs(int u, int pr) {
    int pop(p[u]);
    bool res(1);
    for (int &v: tr[u]) {
        if (v == pr) continue;
        res = res & dfs(v, u);
        pop += lp[v];
    }
    if (pop < abs(h[u])) return 0;
    lp[u] = pop;
    int x = pop - abs(h[u]);
    if (x & 1) return 0;
    x >>= 1;
    if (h[u] > 0) happy[u] = x + h[u], sad[u] = x;
    else happy[u] = x, sad[u] = x + abs(h[u]);
    return res;
}

bool dfs2(int u, int pr) {
    bool res(1);
    int hp(0), sd(0), pop(0);
    for (int &v: tr[u]) {
        if (v == pr) continue;
        hp += happy[v];
        sd += sad[v];
        res = res & dfs2(v, u);
    }
    if (happy[u] + sad[u] - p[u] != hp + sd) return 0;
    int x = happy[u] - hp;
    if (x < 0) return 0;
    int y = p[u] - x;
    int ss = sad[u] - y;
    if (ss > sd) return 0;
    int dif = h[u];
    int z = x - y;
    dif -= z;
    if (hp - sd != dif) return 0;
    return res;
}

void solve() {
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) tr[i].clear();
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        tr[x].push_back(y);
        tr[y].push_back(x);
    }
    if (!dfs(1, 0)) {
        cout << "NO\n";
        return;
    }
    if (lp[1] != m) {
        cout << "NO\n";
        return;
    }
    if (!dfs2(1, 0)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

signed main() {
    __AcHiLlEs
  
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}