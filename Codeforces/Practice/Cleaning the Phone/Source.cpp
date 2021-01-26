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
    int n, m, sumb(0), suma(0), res(INT_MAX);
    cin >> n >> m;
    vc<array<int, 2>> v(n);
    vc<int> a, b;
    for (auto &i: v) cin >> i[0];
    for (auto &i: v) cin >> i[1];
    for (auto &i: v) {
        if (i[1] == 2) a.push_back(i[0]), suma += i[0];
        else b.push_back(i[0]);
    }
    sort(span(a), greater<int>());
    sort(span(b), greater<int>());
    int i, j;
    for (i = 0, j = a.size() - 1; i < b.size(); i++) {
        while (j >= 0 and sumb + suma - a[j] >= m) suma -= a[j], j--;
        if (suma + sumb >= m) res = min(res, i + (j + 1) * 2);
        suma += b[i];
    }
    while (j >= 0 and sumb + suma - a[j] >= m) suma -= a[j], j--;
    if (suma + sumb >= m) res = min(res, i + (j + 1) * 2);
    if (res == INT_MAX) cout << -1 << "\n";
    else cout << res << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}