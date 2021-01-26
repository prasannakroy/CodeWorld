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

vc<int> fact(1001);
const int mod = 1e9 + 7;

void generate() {
    fact[0] = 1;
    for (int i = 1; i < 1001; i++) fact[i] = (fact[i - 1] * i) % mod;
}

int power(int a, int b) {
    int res(1);
    while (b) {
        if (b & 1) (res *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return res;
}

int imod(int a) {
    return power(a, mod - 2);
}

int nCr(int a, int b) {
    int res;
    res = fact[a];
    int i = imod(fact[b]);
    (res *= i) %= mod;
    i = imod(fact[a - b]);
    (res *= i) %= mod;
    return res;
}

void solve() {
    int n, k, sum(0);
    cin >> n >> k;
    vc<int> a(n);
    map<int, int> m, mp;
    for (auto &i: a) cin >> i, m[i]++;
    sort(span(a), greater<int>());
    for (int i = 0; i < k; i++) sum += a[i], mp[a[i]]++;
    int cnt1 = mp[a[k - 1]];
    int cnt2 = m[a[k - 1]];
    cout << nCr(cnt2, cnt1) << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    cin >> t;
    generate();
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}