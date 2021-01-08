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

int limit = (1e6) + 1;

vc<int> fact(limit);

void precompute(int n = limit) {
    iota(span(fact), 0);

    for (int i = 4; i < n; i += 2) fact[i] = 2;
    for (int i = 9; i < n; i += 6) fact[i] = 3;

    for (int i = 5; i * i < n; i += 6) {
        if (fact[i] == i) 
            for (int j = i * i; j < n; j += (2 * i)) fact[j] = i;
        if (fact[i + 2] == i + 2) 
            for (int j = (i + 2) * (i + 2); j < n; j += (2 * (i + 2))) fact[j] = i + 2;
    }
}

int factorize(int n) {
    int res(1);
    while(n != 1) {
        int val = fact[n], cnt(0);
        while (n != 1 and !(n % val)) n /= val, cnt ^= 1;
        if (cnt) res *= val;
    }
    return res;
}

void solve() {
    int n, res(0), mx(0);
    cin >> n;
    vc<int> a(n);
    map<int, int> m;
    for (auto &i: a) cin >> i, i = factorize(i), m[i]++, mx = max(mx, m[i]);
    for (auto &[x, y]: m) if (!(y & 1) or x == 1) res += y;
    res = max(res, mx);
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        if (!x) cout << mx << "\n";
        else cout << res << "\n"; 
    }
}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    precompute();

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}