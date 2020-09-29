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

vector<int> tr[200001];
int dist[200001][18];
int n, timer;
vector<pair<int, int>> segtr[200001];
bool dead[200001], color[200001];
int parent[200001], sz[200001], tin[200001], tout[200001], level[200001];

pair<int, int> merge(pair<int, int> &x, pair<int, int> &y) {
    if (x.first > y.first) return x;
    else if (x.first < y.first) return y;
    else {
        if (x.second > y.second) return x;
        else return y;
    }
}

void subtree(int u, int p) {
    sz[u] = 1;
    for (auto &v: tr[u]) if (!dead[v] and v != p) subtree(v, u), sz[u] += sz[v];
}

int centroid(int m, int u, int p) {
    for (auto &v: tr[u]) if (!dead[v] and v != p) if (sz[v] > (m >> 1)) return centroid(m, v, u);
    return u;
}

void findDist(int u, int p, int lvl, int dst) {
    dist[u][lvl] = dst;
    for (auto &v: tr[u]) if (!dead[v] and v != p) findDist(v, u, lvl, dst + 1);
}

void decompose(int u, int p) {
    subtree(u, p);
    int c = centroid(sz[u], u, p);
    parent[c] = p;
    level[c] = level[p] + 1;
    tin[c] = ++timer;
    findDist(c, p, level[c], 0);
    dead[c] = 1;
    for (auto &v: tr[c]) if (!dead[v] and v != p)
        decompose(v, c);
    tout[c] = ++timer;
}

void updateSeg (int u, int v, int idx, int d, int sz) {
    pair<int, int> rr = make_pair(d, v);
    for(segtr[u][idx += sz] = rr; idx > 1; idx >>= 1) 
        segtr[u][idx >> 1] = merge(segtr[u][idx], segtr[u][idx ^ 1]);
}

auto querySeg(int u, int l, int r, int sz) {
    r++;
    pair<int, int> result = make_pair(-1, -1);
    for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
        if (l & 1) result = merge(result, segtr[u][l++]);
        if (r & 1) result = merge(result, segtr[u][--r]);
    }
    return result;
}

auto query (int u) {
    pair<int, int> res;
    res = segtr[u][1];
    int c = u;
    for (int v = parent[u]; v; v = parent[v]) {
        int d = dist[u][level[v]];
        pair<int, int> a = querySeg(v, 0, tin[c] - tin[v] - 1, tout[v] - tin[v] + 1);
        pair<int, int> b = querySeg(v, tout[c] - tin[v] + 1, tout[v] - tin[v], tout[v] - tin[v] + 1);
        a = merge(a, b);
        if (a.first != -1) a.first += d;
        res = merge(a, res);
        c = v;
    }
    return res.second;
}

void update (int u) {
    if (color[u]) {
        color[u] = 0;
        for (int v = u; v; v = parent[v]) 
            updateSeg(v, u, tin[u] - tin[v], -1, tout[v] - tin[v] + 1);
    }
    else {
        color[u] = 1;
        for (int v = u; v; v = parent[v])
            updateSeg(v, u, tin[u] - tin[v], dist[u][level[v]], tout[v] - tin[v] + 1);
    }
}

void solve() {
    int m, x;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) tr[i].clear();
    for (int i = 1; i < n; i++) {
        cin >> x;
        tr[x].push_back(i + 1);
        tr[i + 1].push_back(x);
    }
    timer = 0;
    memset(parent, 0, (n + 1) * sizeof(int));
    memset(sz, 0, (n + 1) * sizeof(int));
    memset(tin, 0, (n + 1) * sizeof(int));
    memset(tout, 0, (n + 1) * sizeof(int));
    memset(level, -1, (n + 1) * sizeof(int));
    memset(color, 0, (n + 1) * sizeof(bool));
    memset(dead, 0, (n + 1) * sizeof(bool));
    decompose(1, 0);

    for (int i = 1; i <= n; i++) {
        int sz = tout[i] - tin[i] + 1;
        segtr[i].assign((sz << 1) + 1, {-1, -1});
    }
    
    for (int i = 1; i <= n; i++) update(i);

    while (m--) {
        cin >> x;
        if (color[x]) {
            cout << query(x) << "\n";
            update(x);
        }
        else {
            update(x);
            cout << query(x) << "\n";
        }
    }
}

signed main() {

    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif  

    __AcHiLlEs

    // auto start=std::chrono::steady_clock::now();

    int t(1);
    cin >> t;
    // cout << t << "\n";
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);

    // auto end = std::chrono::steady_clock::now();
    //     double elapsed=double (std::chrono::duration_cast < std::chrono::nanoseconds> (end-start).count());
    // std::cout << endl << "Terminated\n"<< elapsed/1e9;
    return 0;
}