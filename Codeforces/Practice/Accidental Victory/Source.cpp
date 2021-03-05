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
    int n;
    cin >> n;
    vc<int> a(n);
    for (auto &i: a) cin >> i;
    auto b = a;
    sort(span(b));
    int l = 0, r = 1e9;
    while (r - l > 1) {
        int m = (l + r) >> 1;

        int sum(0), i;
        for (i = 0; i < n; i++) {
            if (b[i] <= m) {
                sum += b[i];
                continue;
            }
            if (sum < b[i]) break;
            sum += b[i];
        }
        if (i == n) r = m;
        else l = m;
    }
    b.clear();
    for (int i = 0; i < n; i++) if (a[i] >= r) b.push_back(i + 1);
    cout << b.size() << "\n";
    for (auto &i: b) cout << i << " ";
    cout << "\n";
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