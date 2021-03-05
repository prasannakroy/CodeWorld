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
    int n, m, sum(0);
    cin >> n >> m;
    vc<int> a(n);
    vc<array<int, 2>> pref;
    for (int i = 0; i < n; i++) cin >> a[i], sum += a[i], pref.push_back({sum, i});
    sort(span(pref), [&](array<int, 2> x, array<int, 2> y) {
        return x[0] == y[0] ? x[1] < y[1] : x[0] < y[0];
    });

    for (int i = n - 2; i >= 0; i--) pref[i][1] = min(pref[i][1], pref[i + 1][1]);
    
    auto lowerBound = [&](int val) {
        int l = -1, r = n;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            if (pref[mid][0] < val) l = mid;
            else r = mid;
        }
        return r;
    };
    while (m--) {
        int x;
        cin >> x;
        int val = pref[n - 1][0];
        if (sum <= 0) {
            int idx = lowerBound(x);
            if (idx == n) cout << -1 << " ";
            else cout << pref[idx][1] << " ";
        }
        else {
            if (x <= val) {
                int idx = lowerBound(x);
                cout << pref[idx][1] << " ";
                continue;
            }
            int ss = x;
            x -= val;
            x = (x + sum - 1) / sum;
            int r = x * n;
            x = x * sum;
            ss -= x;
            int idx = lowerBound(ss);
            r += pref[idx][1];
            cout << r << " ";
        }
    }
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