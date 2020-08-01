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
    if (n <= 30) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        int a = 6, b = 10, c = 14;
        if (n - 30 == a) {
            cout << "5 6 10 15\n";
        }
        else if (n - 30 == b) {
            cout << "6 14 15 5\n";
        }
        else if (n - 30 == c) {
            cout << "6 10 15 13\n";
        }
        else cout << "6 10 14 " << n - 30 << "\n";
    }
}

signed main() {
    __AcHiLlEs
  
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}