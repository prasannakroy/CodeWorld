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
    int n, k;
    cin >> n >> k;
    vc<int> a(n);
    for (auto &i: a) cin >> i;

    auto compute = [&](int val) {
        vc<int> v(n);
        int sum(0);
        for (int i = 0; i < n; i++) {
            if (a[i] >= val) sum++;
            else sum--;
            v[i] = sum;
        }
        int res = v[k - 1];
        sum = 0;
        for (int i = k; i < n; i++) {
            sum = min(sum, v[i - k]);
            res = max(res, v[i] - sum);
        }
        return res > 0;
    };

    int l = 1, r = n + 1;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (compute(m)) l = m;
        else r = m;
    }
    cout << l << "\n"; 
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