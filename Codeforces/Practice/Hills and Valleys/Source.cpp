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
    int n, res, cnt(0);
    cin >> n;
    vc<int> a(n);
    for (auto &i: a) cin >> i;

    auto check = [&](int idx) {
        if (idx == n - 1 or idx == 0) return false;
        return ((a[idx] < a[idx + 1] and a[idx] < a[idx - 1]) or (a[idx] > a[idx + 1] and a[idx] > a[idx - 1]));
    };

    auto relax = [&](int idx) {
        int prev = a[idx];
        int val1, val2;
        val1 = val2 = cnt - check(idx - 1) - check(idx + 1) - check(idx);
        a[idx] = a[idx + 1];
        val1 += check(idx - 1) + check(idx + 1) + check(idx);
        a[idx] = a[idx - 1];
        val2 += check(idx - 1) + check(idx + 1) + check(idx);
        a[idx] = prev;
        return min({val1, val2, res});
    };

    for (int i = 1; i < n - 1; i++) 
        cnt += check(i);
    res = cnt;
    for (int i = 1; i < n - 1; i++) res = relax(i);
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