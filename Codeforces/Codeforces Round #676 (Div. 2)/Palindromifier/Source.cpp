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
    string s;
    cin >> s;
    int n = s.length();
    bool flag(1);
    for (int i = 0; i < n; i++) 
        if (s[i] != s[n - i - 1]) flag = 0;
    if (flag) {
        cout << 0 << "\n";
        return;
    }
    cout << 4 << "\n";
    cout << "L " << n - 1 << "\n";
    n += n - 2;
    cout << "R " << n - 1 << "\n";
    n += 1;
    cout << "L " << n - 1 << "\n";
    n += n - 2;
    cout << "L " << 2 << "\n";
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case #" << i << ": ",*/ solve(), i++);
    return 0;
}