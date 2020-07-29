/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define i_64 long long

i_64 generalise(string s, i_64 mod) {
    i_64 n(0);
    for (char &i: s) {
        n = (n * 10) + (i - '0');
        n %= mod;
    }
    return n;
}

i_64 power(i_64 a, i_64 b, i_64 mod) {
    i_64 res(1);
    while (b) {
        if (b & 1) (res *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    string a, b;
    i_64 mod = (i_64)1e9 + 7;
    cin >> a >> b;
    i_64 base = generalise(a, mod);
    i_64 p = generalise(b, mod - 1);
    i_64 res = power(base, p, mod);
    cout << res << "\n";
}

signed main() {
    // #ifndef ONLINE_JUDGE 
    //     __AnAkLuSmOs    
    // #endif

    __AcHiLlEs

    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}