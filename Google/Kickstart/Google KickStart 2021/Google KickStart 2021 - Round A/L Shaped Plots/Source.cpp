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

int compute(int a, int b) {
    if (a == 1 or b == 1) return 0;
    int val = a / 2;
    int res(0);
    if (val >= 2) res += min(val, b) - 1;
    val = b / 2;
    if (val >= 2) res += min(val, a) - 1;
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vc<vc<int>> a(n, vc<int>(m));
    for (auto &i: a) for (auto &j: i) cin >> j;
    auto l = a, r = a, u = a, d = a;
    for (int i = 0; i < n; i++) 
        for (int j = 1; j < m; j++) if (a[i][j]) l[i][j] = l[i][j - 1] + 1;
    for (int i = 0; i < n; i++) 
        for (int j = m - 2; j >= 0; j--) if (a[i][j]) r[i][j] = r[i][j + 1] + 1;
    for (int i = 1; i < n; i++) 
        for (int j = 0; j < m; j++) if (a[i][j]) d[i][j] = d[i - 1][j] + 1;
    for (int i = n - 2; i >= 0; i--) 
        for (int j = 0; j < m; j++) if (l[i][j]) u[i][j] = u[i + 1][j] + 1;
    int res(0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (a[i][j]) {
            res += compute(d[i][j], l[i][j]);
            res += compute(d[i][j], r[i][j]);
            res += compute(l[i][j], u[i][j]);
            res += compute(r[i][j], u[i][j]);
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