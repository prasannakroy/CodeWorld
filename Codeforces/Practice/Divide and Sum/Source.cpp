/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long


const int mod = 998244353;
vector<int> fact(300001);

int power(int a, int b) {
    int res(1);
    while (b) {
        if (b & 1) (res *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return res;
}

int Imod(int a) {
    return power(a, mod - 2);
}

int nCr(int n, int r) {
    int res = fact[n];
    (res *= Imod(fact[r])) %= mod;
    (res *= Imod(fact[n - r])) %= mod;
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i: a) cin >> i;
    for (auto &i: b) cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    int res(0);
    for (int i = 0; i < n; i++) res += abs(a[i] - b[i]);
    res %= mod;
    (res *= nCr(n << 1, n)) %= mod;
    cout << res << "\n";
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif
    
    fact[0] = 1;
    for (int i = 1; i < 300001; i++) fact[i] = (fact[i - 1] * i) % mod;

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case #" << i << ": ",*/ solve(), i++);
    return 0;
}