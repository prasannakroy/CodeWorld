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
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &i: v) cin >> i;
    if (v[0][1] == v[1][0] and v[n - 1][n - 2] == v[n - 2][n - 1] and v[n - 1][n - 2] == v[1][0]) {
        cout << 2 << "\n";
        cout << 1 << " " << 2 << "\n";
        cout << 2 << " " << 1 << "\n";
    }
    else if (v[0][1] == v[1][0] and v[n - 1][n - 2] != v[n - 2][n - 1]) {
        cout << 1 << "\n";
        if (v[n - 2][n - 1] == v[1][0]) cout << n - 1 << " " << n << "\n";
        else cout << n << " " << n - 1 << "\n";
    }
    else if (v[0][1] != v[1][0] and v[n - 1][n - 2] == v[n - 2][n - 1]) {
        cout << 1 << "\n";
        if (v[n - 2][n - 1] == v[1][0]) cout << 2 << " " << 1 << "\n";
        else cout << 1 << " " << 2 << "\n";
    }
    else if (v[0][1] != v[1][0] and v[n - 1][n - 2] != v[n - 2][n - 1]) {
        cout << 2 << "\n";
        if (v[0][1] == v[n - 1][n - 2]) {
            cout << 1 << " " << 2 << "\n";
            cout << n - 1 << " " << n << "\n";
        }
        else {
            cout << 1 << " " << 2 << "\n";
            cout << n << " " << n - 1 << "\n";
        }
    }
    else cout << 0 << "\n";
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