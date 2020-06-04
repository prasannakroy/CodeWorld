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
#define i_64 long long

void solve() {
    int n, x, codd(0), ceven(0);
    cin >> n >> x;
    int a[n];
    for (int &i: a) {
        cin >> i;
        if (i & 1) codd++;
        else ceven++;
    }
    if (codd == 0) {
        cout << "No\n";
        return;
    }
    if (codd >= x and x & 1) {
        cout << "Yes\n";
        return;
    }
    if (!(codd & 1)) codd--;
    int y = x & 1 ? codd : min(codd, x - 1);
    if (ceven >= x - y) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
