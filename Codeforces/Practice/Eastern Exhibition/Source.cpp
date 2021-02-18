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
    int n, d1(LLONG_MAX), d2(LLONG_MAX);
    cin >> n;
    vc<int> a(n), b(n), x, y;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    sort(span(a));
    sort(span(b));
    for (int i = 0; i < n; i++) {
        int d = 0;
        for (int j = 0; j < n; j++) 
            d += abs(a[j] - a[i]);
        if (d < d1) d1 = d, x.clear(), x.push_back(a[i]);
        else if (d == d1) x.push_back(a[i]);
    }
    for (int i = 0; i < n; i++) {
        int d = 0;
        for (int j = 0; j < n; j++) 
            d += abs(b[j] - b[i]);
        if (d < d2) y.clear(),d2 = d, y.push_back(b[i]);
        else if (d == d2) y.push_back(b[i]);
    }
    int c1 = x.back() - x.front() + 1;
    int c2 = y.back() - y.front() + 1;
    cout << c1 * c2 << "\n";
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