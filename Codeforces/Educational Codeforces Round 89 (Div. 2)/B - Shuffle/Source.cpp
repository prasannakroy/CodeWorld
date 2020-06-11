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
    int n, m, x;
    cin >> n >> x >> m;
    int s(x), e(x);
    while (m--) {
        int a, b;
        cin >> a >> b;
        if ((s <= a and e >= b) or (s >= a and s <= b) or (e >= a and e <= b)) {
            s = min(s, a);
            e = max(e, b);
        }
    }
    cout << (e - s + 1) << "\n";
}

signed main() {
    __AcHiLlEs

    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
