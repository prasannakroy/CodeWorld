/*****************************
*  Author :: Πρασαννα Κ. Ροι  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve() {
    int n, m;
    cin >> n >> m;
    vc<vc<int>> a(n, vc<int>(m, 0));
    auto cmp = [](array<int, 3> p, array<int, 3> q) {
        if (p[0] == q[0]) {
            if (p[1] == q[1]) return p[2] > q[2];
            return p[1] > q[1];
        }
        return p[0] > q[0];
    };
    set<array<int, 3>, decltype(cmp)> s(cmp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            s.insert({a[i][j], i, j});
        }
    }
    int res(0);
    while (!s.empty()) {
        auto u = *s.begin();
        s.erase(s.begin());
        for (int i = 0; i < 4; i++) {
            int x = u[1] + dx[i], y = u[2] + dy[i];
            if (x < n and x >= 0 and y < m and y >= 0 and a[x][y] < a[u[1]][u[2]] - 1) {
                res += (a[u[1]][u[2]] - 1 - a[x][y]);
                s.erase(s.find({a[x][y], x, y}));
                a[x][y] = a[u[1]][u[2]] - 1;
                s.insert({a[x][y], x, y});
            }
        }
    }
    cout << res << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    // #ifndef ONLINE_JUDGE 
    //     __AnAkLuSmOs    
    // #endif

    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; cout << "Case #" << i << ": ", solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}