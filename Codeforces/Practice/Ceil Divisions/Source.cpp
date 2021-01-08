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
#define span(a) a.begin(), a.end()

template<typename t>
using vc = vector<t>;

void solve() {
    int n, m, cnt(0);
    cin >> n;
    m = n;
    int val = sqrt(n);
    if (val * val < n) val++;
    vc<int> a(n + 1);
    iota(span(a), 0);
    vc<pair<int, int>> res;
    while (true) {
        cnt++;
        if (cnt > 100) break;
        if (n <= 3) break;
        for (int j = n - 1; j > val; j--) {
            res.push_back({j, n}), a[j] = (a[j] + n - 1) / n;
        }
        res.push_back({n, val});
        a[n] = (a[n] + a[val] - 1) / a[val];
        res.push_back({n, val});
        a[n] = (a[n] + a[val] - 1) / a[val];
        n = val;
        val = sqrt(n);
        if (val * val < n) val++;
    }
    if (n == 3) {
        res.push_back({3, 2});
        res.push_back({3, 2});
        a[3] = 1;
    }
    int cn1(0), cn2(0);
    for (int i = 1; i <= m; i++) {
        if (a[i] == 1) cn1++;
        else if (a[i] == 2) cn2++;
    }
    cout << res.size() << "\n";
    for (auto &i: res) cout << i.first << " " << i.second << "\n";
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