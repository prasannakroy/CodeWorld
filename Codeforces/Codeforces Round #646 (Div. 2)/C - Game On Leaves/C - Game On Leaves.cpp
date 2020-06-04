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
    int n, k, x, y;
    cin >> n >> k;
    int d[n + 1];
    memset(d, 0, sizeof d);
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        d[x]++;
        d[y]++;
    }
    if (d[k] == 1 or n == 1 or !(n & 1)) cout << "Ayush\n";
    else cout << "Ashish\n";
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
