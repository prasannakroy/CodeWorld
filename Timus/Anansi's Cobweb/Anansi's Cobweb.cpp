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
#define i_64 long long

const int MX = 100001;
int dsu[MX], SIZE[MX];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        dsu[i] = i;
        SIZE[i] = 1;
    }
}

int root(int a) {
    return dsu[a] == a? a: dsu[a] = root(dsu[a]);
}

void join(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    if (SIZE[a] < SIZE[b]) {
        dsu[a] = b;
        SIZE[b] += SIZE[a];
    }
    else {
        dsu[b] = a;
        SIZE[a] += SIZE[b];
    }
}

void solve() {
    int n, m, q;
    cin >> n >> m;
    init(n);
    std::vector<pair<int, int>> v(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> v[i].first >> v[i].second;
    }
    cin >> q;
    int query[q];
    std::map<int, int> mp;
    for (int &i: query) cin >> i, mp[i] = 1;
    for (int i = 1; i <= m; i++) {
        if (!mp[i]) {
            join(v[i].first, v[i].second);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (dsu[i] == i) cnt++;
    }
    std::vector<int> res(q);
    for (int i = q - 1; i >= 0; i--) {
        res[i] = cnt;
        int x = root(v[query[i]].first);
        int y = root(v[query[i]].second);
        if (x != y) {
            cnt--;
            join(x, y);
        }
    }
    for (int &i: res) cout << i << " ";
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    i_64 t(1);
    // cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}