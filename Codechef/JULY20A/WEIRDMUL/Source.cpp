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
#define i_64 long long

const i_64 mod = 998244353;

i_64 power(i_64 a, i_64 p) {
    i_64 res(1);
    while (p) {
        if (p & 1) (res *= a) %= mod;
        (a *= a) %= mod;
        p >>= 1;
    }
    return res;
}

void solve() {
    i_64 n, x;
    cin >> n >> x;
    i_64 a[n];
    for (i_64 &i: a) cin >> i;
    i_64 sum[n];
    for (i_64 i = 0; i < n; i++) {
        sum[i] = power(x, i);
        (sum[i] *= a[i]) %= mod;
        if (i > 0) (sum[i] += sum[i - 1]) %= mod;
    }
    i_64 res(1);
    for (i_64 i = 0; i < n; i++) {
        i_64 r1 = power(sum[i], (n - i) << 1);
        (res *= r1) %= mod;
    }
    cout << res << "\n";
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs
  
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
