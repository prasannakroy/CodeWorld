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
    string s, res("");
    cin >> s;
    int cnt1(0), cnt0(0);
    for (char &i: s) i == '0' ? cnt0++ : cnt1++;
    if (cnt1 == 0 or cnt0 == 0) {
        cout << "NET\n";
        return;
    } 
    int cnt = min(cnt1, cnt0);
    if (cnt & 1) res = "DA";
    else res = "NET";
    cout << res << "\n";
}

signed main() {
    __AcHiLlEs
  
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
