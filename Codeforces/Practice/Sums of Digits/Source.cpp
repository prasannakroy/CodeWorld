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

auto find_num(vc<int> a, int sum) {
    int n = a.size();
    auto pref = a;
    for (int i = 1; i < n; i++) pref[i] += pref[i - 1];
    vector<int> res;
    for (int i = n - 1, k = 0; ; i--, k++) {
        int d = 0;
        if (i >= 0) d = a[i];
        for (int j = d + 1; j <= 9; j++) {
            int r = j;
            if (i > 0) r += pref[i - 1];
            if (sum - r >= 0 and sum - r <= 9 * k) {
                if (i > 0) for (int l = 0; l < i; l++) res.push_back(a[l]);
                res.push_back(j);
                int cnt = (sum - r) / 9;
                if (cnt < k) {
                    while (cnt + 1 < k) res.push_back(0), k--;
                    res.push_back((sum - r) % 9);
                }
                while (cnt) res.push_back(9), cnt--;
                return res;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vc<int> b(n);
    for (auto &i: b) cin >> i;

    vc<vc<int>> a;
    a.push_back({0});
    for (int i = 0; i < n; i++) 
        a.push_back(find_num(a.back(), b[i]));
    for (int i = 1; i <= n; i++) {
        for (auto &j: a[i]) cout << j;
        cout << "\n";
    }
}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}