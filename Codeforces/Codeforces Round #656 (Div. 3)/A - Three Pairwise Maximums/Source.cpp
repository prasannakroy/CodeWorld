/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include <bits/stdc++.h> 
using namespace std; 

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define i_64 long long

void solve() {
    i_64 x, y, z;
    std::map<i_64, i_64> m;
    cin >> x >> y >> z;
    m[x]++, m[y]++, m[z]++;
    i_64 mx = max(x, max(y, z));
    if (m[mx] < 2) 
        cout << "NO\n";
    else {
        cout << "YES\n";
        i_64 a, b, c;
        if (x == mx and y == mx) b = mx, c = z, a = z;
        else if (x == mx and z == mx) a = mx, b = y, c = y;
        else if (y == mx and z == mx) c = mx, a = x, b = x;
        cout << a << " " << b << " " << c << "\n";
    }
}

signed main() {
    __AcHiLlEs
  
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case #" << i << ": ",*/ solve(), i++);
    return 0;
}
