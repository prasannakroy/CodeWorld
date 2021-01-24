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
    int r, g, b;
    cin >> r >> g >> b;
    vc<int> R(r), G(g), B(b);
    for (auto &i: R) cin >> i;
    for (auto &i: G) cin >> i;
    for (auto &i: B) cin >> i;
    sort(span(R));
    sort(span(G));
    sort(span(B));

    auto sqr = [&](int a) {
        return a * a;
    };
    auto sum = [&] (int a, int b, int c) {
        return sqr(a - b) + sqr(b - c) + sqr(c - a);
    };

    int i(0), j(0), k(0), res(LLONG_MAX);
    while (i < r - 1 or j < g - 1 or k < b - 1) {
        res = min(res, sum(R[i], G[j], B[k]));
        int v1, v2, v3;
        v1 = v2 = v3 = LLONG_MAX;
        if (i < r - 1) v1 = sum(R[i + 1], G[j], B[k]);
        if (j < g - 1) v2 = sum(R[i], G[j + 1], B[k]);
        if (k < b - 1) v3 = sum(R[i], G[j], B[k + 1]);
        if (v1 <= v2 and v1 <= v3) i++;
        else if (v2 <= v3) j++;
        else k++;
    }
    res = min(res, sum(R[i], G[j], B[k]));
    cout << res << "\n";
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