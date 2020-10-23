/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long


void solve() {
    int n, res(0);
    cin >> n;
    int a[n][n];
    bool vis[n][n];
    memset(vis, 0, sizeof vis);
    for (auto &i: a) for (auto &j: i) cin >> j;
    for (int k = 0; k < n; k++) {
        int i = 0, j = k;
        int r(0);
        while (i < n and j < n) 
            r += a[i++][j++];
        res = max(res, r);
    }
    for (int k = 1; k < n; k++) {
        int i = k, j = 0;
        int r(0);
        while (i < n and j < n) r += a[i++][j++];
        res = max(res, r);
    }
    cout << res << "\n";
}

signed main() {

    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; cout << "Case #" << i << ": ", solve(), i++);
    return 0;
}