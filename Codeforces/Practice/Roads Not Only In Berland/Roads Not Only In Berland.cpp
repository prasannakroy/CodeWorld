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
int dsu[MX], sze[MX];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        dsu[i] = i;
        sze[i] = 1;
    }
}

int root(int a) {
    return dsu[a] == a? a: dsu[a] = root(dsu[a]);
}

void join(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    if (sze[a] < sze[b]) {
        dsu[a] = b;
        sze[b] += sze[a];
    }
    else {
        dsu[b] = a;
        sze[a] += sze[b];
    }
}

void solve() {
    int n, x, y;
    cin >> n;
    init(n);
    std::vector<pair<int, int>> v;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        if (root(x) == root(y)) 
            v.push_back({x, y});
        else 
            join(x, y);
    }
    std::vector<int> r;
    for (int i = 1; i <= n; i++) 
        if (dsu[i] == i) 
            r.push_back(i);
        
    cout << v.size() << "\n";
    for (int i = 0, j = 0; i < v.size(); i++) 
        cout << v[i].first << " " << v[i].second << " " << r[j++] << " " << r[j] << "\n";
}

signed main() {
    // #ifndef ONLINE_JUDGE 
    //     __AnAkLuSmOs    
    // #endif

    __AcHiLlEs

    i_64 t(1);
    // cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);   
    return 0;
}
