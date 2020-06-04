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
int dsu[MX];

void init(int n) {
    for (int i = 1; i <= n; i++) 
        dsu[i] = i;
}

int root(int a) {
    if (dsu[a] != a) 
        dsu[a] = root(dsu[a]);
    return dsu[a];
}

void solve() {
    int n, q, x, y, z;
    cin >> n >> q;
    int res[n + 1];
    memset(res, 0, sizeof res);
    init(MX);
    std::vector<pair<pair<int, int>, int>> v;
    for (int i = 0; i < q; i++) {
        cin >> x >> y >> z;
        v.push_back({{x, y}, z});
    }
    for (int i = q - 1; i >= 0; i--) {
        int l = root(v[i].first.first);
        int r = v[i].first.second;
        int c = v[i].second;
        for (int i = l; i <= r; i = root(i + 1)) {
            res[i] = c;
            dsu[i] = max(dsu[i], root(r + 1));
        }
    }
    for (int i = 1; i <= n; i++) 
        cout << res[i] << "\n";
}

signed main() {
    // auto start=chrono::steady_clock::now();
    // #ifndef ONLINE_JUDGE 
    //     __AnAkLuSmOs    
    // #endif

    __AcHiLlEs

    i_64 t(1);
    // cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto end = chrono::steady_clock::now();
    // double elapsed = double (chrono::duration_cast < chrono::nanoseconds> (end-start).count());
    // cout << endl << "Terminated\n"<< elapsed/1e9;
    return 0;
}
