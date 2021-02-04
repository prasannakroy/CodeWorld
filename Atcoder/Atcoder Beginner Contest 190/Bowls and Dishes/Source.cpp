/*****************************
*  Author :: Πρασαννα Κ. Ροι  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

void solve() {
    int n, m, k, val(0), rs(0);
    cin >> n >> m;
    vc<int> check(n);
    vc<array<int, 2>> a(m);
    for (auto &i: a) cin >> i[0] >> i[1];
    cin >> k;
    val = (1 << k);
    vc<array<int, 2>> b(k);
    for (auto &i: b) cin >> i[0] >> i[1];
    for (int i = 0; i < val; i++) {
        vector<int> res;
        int x = i;
        while (x) {
            if (x & 1) res.push_back(1);
            else res.push_back(0);
            x >>= 1;
        }
        while (res.size() < k) res.push_back(0);
        check.assign(n + 1, 0);
        for (int j = 0; j < k; j++) 
            check[b[j][res[j]]] = 1;
        int cnt(0);
        for (int j = 0; j < m; j++) 
            if (check[a[j][0]] == 1 and check[a[j][1]] == 1) cnt++;
        rs = max(rs, cnt);
    }
    cout << rs << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}