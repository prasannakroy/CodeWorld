/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define i_64 long long

std::map<i_64, bool> m;
 
i_64 power(i_64 base, i_64 e, i_64 mod) {
    i_64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (i_64)result * base % mod;
        base = (i_64)base * base % mod;
        e >>= 1;
    }
    return result;
}
 
bool check_composite(i_64 n, i_64 a, i_64 d, i_64 s) {
    i_64 x = power(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (i_64 r = 1; r < s; r++) {
        x = (i_64)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};
 
bool primeCheck(i_64 n) {
    if (n < 2)
        return false;
 
    i_64 r = 0;
    i_64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }
 
    for (i_64 a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}
 
void solve() {
    i_64 n, cnt(0);
    cin >> n;
    if (n == 2) {
        cout << "Ashishgup\n";
        return;
    }
    if (::m[n] == 1) {
        cout << "FastestFinger\n";
        return;
    }
    while (!(n & 1)) n >>= 1, cnt++;
    if (cnt != 1) {
        cout << "Ashishgup\n";
        return;
    }
    if (primeCheck(n)) {
        cout << "FastestFinger\n";
        return;
    }
    else {
        cout << "Ashishgup\n";
        return;
    }
}

signed main() {
    __AcHiLlEs

    i_64 x(1);
    ::m[1] = 1;
    while (x < 1000000001) {
        x <<= 1;
        ::m[x] = 1;
    }
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
