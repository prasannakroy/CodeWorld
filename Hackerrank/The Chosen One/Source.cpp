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

i_64 gcd(i_64 a, i_64 b) {
    while (b) tie(a, b) = make_tuple(b, a % b);
    return a;
}

bool verify(i_64 a[], i_64 cnt, i_64 d, i_64 n) {
    if (cnt == n - 1) {
        cout << d << "\n";
        return true;
    }
    else if (cnt  == 1) {
        i_64 d2(0);
        for(int i = 0; i < sizeof(a); i++) {
            if (a[i] == d) continue;
            d2 = gcd(a[i], d2);
        } 
        cout << d2 << "\n";
        return true;
    }
    else {
        return false;
    }
}

void solve() {
    int n;
    cin >> n;
    i_64 a[n];
    i_64 d(0), cnt(0);
    for(i_64 &i: a) {
        cin >> i; 
        i_64 x = gcd(i, d);
        if (x == 1) continue;
        d = x;
        cnt++;
    }
    if (n == 1) {
        cout << a[0] + 1 << "\n";
        return;
    }
    bool res = verify(a, cnt, d, n);
    if (!res) {
        for(i_64 &i: a) i /= d;
        i_64 d2 = d;
        d = 0, cnt = 0;
        i_64 r;
        for(i_64 &i: a) {
            cin >> i; 
            i_64 x = gcd(i, d);
            if (x == 1) {
                r = i; 
                continue;
            }
            d = x;
            cnt++;
        }
        verify(a, cnt, d * d2, n);
    }
}

signed main() {

    // __AcHiLlEs

    i_64 t(1);
    // cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
