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

const int mod = 998244353;
const int mx = 200000;
vc<int> fact(mx + 1), ifact(mx + 1);

int power(int a, int b) {
    int res(1);
    while (b) {
        if (b & 1) (res *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return res;
}

void generate() {
    fact[0] = 1;
    for (int i = 1; i <= mx; i++) fact[i] = (fact[i - 1] * i) % mod;
    ifact[0] = ifact[1] = 1;
    for (int i = 2; i <= mx; i++) ifact[i] = power(fact[i], mod - 2);
}

int nCr(int n, int r) {
    int res = (((fact[n] * ifact[r]) % mod) * ifact[n - r]) % mod;
    return res;
}

int compute(int sz, int c1, int c0) {
    int res(0);
    for (int i = 1; i <= min(sz, c1); i += 2) {
        if (sz - i > c0) continue;
        (res += (nCr(c1, i) * nCr(c0, sz - i)) % mod) %= mod;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vc<int> c0(30, 0), c1(30, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int i = 0; i < 30; i++) {
            if (x & (1 << i)) c1[i]++; 
            else c0[i]++;
        }
    }
    vc<int> res(n + 1, 0);
    res[0] = 0;
    for (int i = 0; i < 30; i++) {
        for (int j = 1; j <= n; j++) {
            int cnt = j;
            int cnt1 = c1[i];
            int cnt0 = c0[i];
            int sol = compute(j, cnt1, cnt0);
            int pr = (1 << i);
            (sol *= pr) %= mod;
            (res[j] += sol) %= mod;
        }
    }
    for (int i = 1; i <= n; i++) (res[i] += res[i - 1]) %= mod;
    int q, x;
    cin >> q;
    while (q--) {
        cin >> x;
        cout << res[x] << "\n";
    }
}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs
    generate();
    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}