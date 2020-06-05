/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define i_64 unsigned long long

i_64 power(i_64 a, i_64 p) {
    i_64 res = 1;
    while (p) {
        if (p & 1) res *= a;
        a *= a;
        p >>= 1;
    }
    return res;
}

void solve() {
    i_64 n, cnt(0);
    cin >> n;
    i_64 x = 1, res(0);
    for (i_64 i = 1; i <= 64; i++) {
        i_64 d = power(2ll, i - 1);
        if (d <= n) {
            res += i;
            i_64 x = n - d;
            d *= 2;
            res += (i * (x / d));
        }
        else {
            break;
        }
    }
    cout << res << "\n";
}

signed main() {
    __AcHiLlEs

    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
