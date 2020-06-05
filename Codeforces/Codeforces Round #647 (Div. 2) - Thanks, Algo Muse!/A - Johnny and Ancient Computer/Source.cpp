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
    i_64 a, b, cnt(0);
    cin >> a >> b;
    tie(a, b) = make_tuple(max(a, b), min(a, b));
    if (a % b) {
        cout << -1 << "\n";
        return;
    }
    i_64 d = a / b;
    bool flag = 0;
    while (d != 1) {
        if (d % 8 == 0) d >>= 3;
        else if (d % 4 == 0) d >>= 2
        else if (d % 2 == 0) d >>= 1
        else {
            flag = 1;
            break;
        }
        cnt++;
    }
    if (flag) {
        cout << -1 << "\n";
        return;
    }
    cout << cnt << "\n";
}

signed main() {
    __AcHiLlEs

    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
