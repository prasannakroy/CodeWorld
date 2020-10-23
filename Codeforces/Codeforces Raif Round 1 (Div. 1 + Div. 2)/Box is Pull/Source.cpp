/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long


void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int d = abs(x1 - x2) + abs(y1 - y2);
    if (x1 == x2 or y1 == y2) cout << d << "\n";
    else cout << d + 2 << "\n";
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case #" << i << ": ",*/ solve(), i++);
    return 0;
}