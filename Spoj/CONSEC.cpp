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

const int MX = 1000005;
int dsu[MX], sze[MX];

void init(int n) {
    for (int i = 0; i <= n; i++) { 
        dsu[i] = i;
        sze[i] = 1;
    }
}

int root(int a) {
    if (dsu[a] != a) 
        dsu[a] = root(dsu[a]);
    return dsu[a];
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
    cout << "\n";
    string s;
    cin >> s;
    string s2 = s;
    int n = s.length();
    init(n);
    int q, t, v;
    cin >> q;
    std::vector<pair<int, int>> query;
    for (int i = 0; i < q; i++) {
        cin >> t >> v;
        if (t == 2) 
            s2[v] = '#';
        query.push_back({t, v});
    }
    for (int i = 1; i < n; i++) 
        if (s2[i] == s2[i - 1] and s2[i] != '#')
            join(i, i - 1);
    std::vector<int> res;
    for (int i = q - 1; i >= 0; i--) {
        if (query[i].first == 1) 
            res.push_back(sze[root(query[i].second)]);
        else {
            int x = query[i].second;
            s2[x] = s[x];
            if (s2[x] == s2[x - 1] and x > 0) 
                join(x, x - 1);
            if (s2[x] == s2[x + 1] and x < n - 1) 
                join(x, x + 1);
        }
    }
    for (int j = res.size() - 1; j >= 0; j--) {
        cout << res[j] << "\n";
    }
}

signed main() {
    // auto start=chrono::steady_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; cout << "Case " << i << ": ", solve(), i++);
    // auto end = chrono::steady_clock::now();
    // double elapsed = double (chrono::duration_cast < chrono::nanoseconds> (end-start).count());
    // cout << endl << "Terminated\n"<< elapsed/1e9;
    return 0;
}
