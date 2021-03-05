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
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

void solve() {
    int n;
    cin >> n;
    vc<int> a(n);
    for (auto &i: a) cin >> i;
    for (int i = n - 2; i >= 0; i--) a[i] += a[i + 1];
    vc<bool> res(n, 0);
    for (int i = 1; i < n; i += 2) res[i] = 1;
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int idx = lower_bound(a.rbegin(), a.rend(), x) - a.rbegin();
        idx = n - idx - 1;
        cout << (char)('A' + res[idx]) << "\n";
    }
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