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
    int n;
    cin >> n;
    int q = n / 4;
    int r = n % 4;
    string res("");
    for (int i = 0; i < n - q - 1; i++) res += '9';
    if (r == 0) res += '9';
    else res += '8';
    for (int i = res.length(); i < n; i++) res += '8';
    cout << res << "\n";
}

signed main() {
    __AcHiLlEs
  
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}