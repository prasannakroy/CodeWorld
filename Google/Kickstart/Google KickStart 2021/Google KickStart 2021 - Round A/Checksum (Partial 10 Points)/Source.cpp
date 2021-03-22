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

bool check(vc<vc<int>> a, vc<int> r, vc<int> c, vc<int> rx, vc<int> cx, vc<int> rc, vc<int> cc, int n) {
    set<array<int, 3>> s;
    int cnt(0);
    for (int i = 0; i < n; i++) if (rc[i]) s.insert({rc[i], 0, i});
    for (int i = 0; i < n; i++) if (cc[i]) s.insert({cc[i], 1, i});
    // for (auto &i: a) {
    //     for (auto &j: i) cout << j << " ";
    //     cout << "\n";
    // }
    // cout << "\n";
    // for (auto &i: rc) cout << i << " ";
    // cout << "\n";
    // for (auto &i: cc) cout << i << " ";
    // cout << "\n\n";
    while (!s.empty()) {
        if (cnt > 100) break;
        cnt++;
        // cout << cnt << "\n";
        auto u = *s.begin();
        s.erase(s.begin());
        if (u[0] >= 2) return 0;
        if (u[1] == 0) {
            for (int i = 0; i < n; i++) if (a[u[2]][i] == -1) {
                a[u[2]][i] = (rx[u[2]] != r[u[2]]);
                rx[u[2]] ^= a[u[2]][i];
                cx[i] ^= a[u[2]][i];
                // cout << cc[i] << "\n";
                s.erase(s.find({cc[i], 1, i}));
                cc[i]--;
                if (cc[i]) s.insert({cc[i], 1, i});
            }
        }
        else {
            for (int i = 0; i < n; i++) if (a[i][u[2]] == -1) {
                a[i][u[2]] = (cx[u[2]] != c[u[2]]);
                cx[u[2]] ^= a[i][u[2]];
                rx[i] ^= a[i][u[2]];
                // cout << rc[i] << "\n";
                s.erase(s.find({rc[i], 0, i}));
                rc[i]--;
                if (rc[i]) s.insert({rc[i], 0, i});
            }
        }
    }
    // cout << "\n";
    return true;
}

void solve() {
    // cout << "\n";
    int n;
    cin >> n;
    vc<vc<int>> a(n, vc<int>(n));
    vc<int> rc(n, 0), cc(n, 0), rx(n, 0), cx(n, 0);
    auto b = a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == -1) rc[i]++, cc[j]++;
            else rx[i] ^= a[i][j], cx[j] ^= a[i][j];
        }
    }
    for (auto &i: b) for (auto &j: i) cin >> j;
    vc<int> r(n), c(n);
    for (auto &i: r) cin >> i;
    for (auto &i: c) cin >> i;
    int res(INT_MAX);
    vc<int> vis(n * n, 0);
        // for (auto &i: a) {
        //     for (auto &j: i) cout << j << " ";
        //     cout << "\n";
        // }
        // cout << "\n";
    for (int p = 0; p < (1 << (n * n)); p++) {
        int cnt(0), cost(0);
        // for (auto &i: rc) cout << i << ":";
        // cout << "\n";
        // for (auto &i: cc) cout << i << ":";
        // cout << "\n\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++, cnt++) if (a[i][j] == -1) {
                if (p & (1 << cnt)) {
                    // cout << cc[0] << "-\n";
                    vis[cnt] = 1;
                    if (rc[i] == 1) 
                        a[i][j] = (r[i] != rx[i]);
                    else if (cc[i] == 1) 
                        a[i][j] = (c[i] != cx[i]);
                    else a[i][j] = 0;
                    rx[i] ^= a[i][j];
                    cx[i] ^= a[i][j];
                    cost += b[i][j];
                    // cout << j << " " << cc[j] << " " << cc[0] << "--\n";
                    rc[i]--;
                    cc[j]--;
                    // cout << j << " " << cc[j] << "--\n";
                }
            }
        }
        // cout << "\n";
        if (check(a, r, c, rx, cx, rc, cc, n)) res = min(res, cost);
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++, cnt++) if (vis[cnt]) {
                vis[cnt] = 0;
                rx[i] ^= a[i][j];
                cx[j] ^= a[i][j];
                a[i][j] = -1;
                rc[i]++;
                cc[j]++;
            }
        }
        // for (auto &i: rc) cout << i << ":";
        // cout << "\n";
        // for (auto &i: cc) cout << i << ":";
        // cout << "\n\n";
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