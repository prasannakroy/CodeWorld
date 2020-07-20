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

void solve() {
    i_64 l, r, m, a, b, c;
    cin >> l >> r >> m;
    for (i_64 i = l; i <= r; i++) {
        i_64 x = m % i;
        if (r - l >= x and x != m) {
            a = i;
            b = r;
            c = r - x;
            break;
        }
        i_64 y = i - x;
        if (r - l >= y) {
            a = i;
            b = l;
            c = l + y;
            break;
        }
    }
    cout << a << " " << b << " " << c << "\n";
}

signed main() {
    __AcHiLlEs
  
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
