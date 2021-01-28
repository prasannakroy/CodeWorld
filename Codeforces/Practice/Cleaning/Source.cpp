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

bool check(vc<int> &a) {
    bool flag = 1;
    int val = 0;
    for (auto &i: a) {
        if (i < val) return 0;
        val = i - val;
    }
    return val == 0;
}

void solve() {
    int n;
    cin >> n;
    vc<int> a(n), pref(n), suf(n);
    for (auto &i: a) cin >> i;
    if (n == 1) return void(cout << "NO\n");
    if (check(a)) return void(cout << "YES\n");
    int val = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < val or (i > 0 and pref[i - 1] == -1)) pref[i] = -1;
        else pref[i] = a[i] - val, val = pref[i];
    }
    val = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < val or (i < n - 1 and suf[i + 1] == -1)) suf[i] = -1;
        else suf[i] = a[i] - val, val = suf[i];
    }
    for (int i = 1; i < n; i++) {
        int val1 = 0, val2 = 0;
        if (i - 1 > 0) val1 = pref[i - 2];
        if (i < n - 1) val2 = suf[i + 1];
        if (val1 == -1 or val2 == -1) continue;
        vector<int> c = {val1, a[i], a[i - 1], val2};
        if (check(c)) return void(cout << "YES\n");
    }
    cout << "NO\n";
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