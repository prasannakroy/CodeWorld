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
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vc<int> a(n1), b(n2), c(n3), sum(4, 0), mn(3, INT_MAX);
    for (auto &i: a) cin >> i, sum[0] += i, mn[0] = min(i, mn[0]);
    for (auto &i: b) cin >> i, sum[1] += i, mn[1] = min(i, mn[1]);
    for (auto &i: c) cin >> i, sum[2] += i, mn[2] = min(i, mn[2]);
    sort(span(mn));
    sort(span(sum));
    cout << accumulate(span(sum), sum[0]) - 2 * min(sum[1], mn[0] + mn[1]) << "\n";
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