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
    i_64 n;
    cin >> n;
    i_64 a[n], b[n], mnc(INT_MAX), mno(INT_MAX);
    for (i_64 &i: a) cin >> i, mnc = min(mnc, i);
    for (i_64 &i: b) cin >> i, mno = min(mno, i);
    i_64 res(0);
    for (i_64 i = 0; i < n; i++) 
        res += max(a[i] - mnc, b[i] - mno);
    cout << res << "\n";
}

signed main() {
    __AcHiLlEs
  
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
