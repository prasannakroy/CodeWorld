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

const int mx = 200000;
vector<int> val[mx + 1];
vector<pair<int, int>> tr[mx + 1];

int gcd(int a, int b) {
    while (b) tie(a, b) = make_tuple(b, a % b);
    return a;
}

template<typename t> 
class DisjointSet {
public:
    vector<t> dsu, SIZE;
    DisjointSet(t n) {
        dsu.resize(n + 1);
        SIZE.assign(n + 1, 1);
        iota(dsu.begin(), dsu.end(), 0);
    }

    t root(t a) {
        return dsu[a] == a? a: dsu[a] = root(dsu[a]);
    }

    void join(t a, t b, t &res) {
        a = root(a);
        b = root(b);
        if (a == b) return;
        res -= (SIZE[a] * (SIZE[a] + 1) >> 1);
        res -= (SIZE[b] * (SIZE[b] + 1) >> 1);
        if (SIZE[a] < SIZE[b]) dsu[a] = b, SIZE[b] += SIZE[a], res += (SIZE[b] * (SIZE[b] + 1) >> 1);
        else dsu[b] = a, SIZE[a] += SIZE[b], res += (SIZE[a] * (SIZE[a] + 1) >> 1);
    }
};


void solve() {
    int n, x, y;
    cin >> n;
    int a[n + 1], res[mx + 1];
    memset(res, 0, sizeof res);
    DisjointSet<int> tree(n);
    for (int i = 1; i <= n; i++) cin >> a[i], val[a[i]].push_back(i);
    for (int i = 1; i < n; i++) cin >> x >> y, tr[(gcd(a[x], a[y]))].push_back({x, y});
    for (int i = mx; i > 0; i--) {
        res[i] = 0;
        for (int j = i; j <= mx; j += i) {
            res[i] -= res[j];
            res[i] += val[j].size();
            for (auto &k: val[j]) tree.dsu[k] = k, tree.SIZE[k] = 1;
        }
        for (int j = i; j <= mx; j += i) 
            for (auto &k: tr[j]) 
                tree.join(k.first, k.second, res[i]);
    }
    for (int i = 1; i <= mx; i++) if (res[i] > 0) cout << i << " " << res[i] << "\n";
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