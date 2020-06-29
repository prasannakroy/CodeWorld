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
    int n, cnt2(0), cnt3(0);
    cin >> n;
    while (!(n & 1)) cnt2++, n >>= 1;
    while (n % 3 == 0) cnt3++, n /= 3;
    if (n != 1 or cnt3 < cnt2) {
        cout << -1 << "\n";
        return;
    }
    cout << cnt3 + (cnt3 - cnt2) << "\n";
}

signed main() {
    __AcHiLlEs
  
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
