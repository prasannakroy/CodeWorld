/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define i_64 unsigned long long

void solve() {
    int n;
    cin >> n;
    int a[n], b[n];
    std::map<int, int> m;
    for (int i = 0; i < n; i++) cin >> a[i], m[a[i]] = i;
    int res[n], mx(0);
    memset(res, 0, sizeof res);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        int x = (((m[b[i]] - i) % n) + n) % n;
        res[x]++;
        mx = max(res[x], mx);
    }
    cout << mx << "\n";
}

signed main() {
    __AcHiLlEs

    i_64 t(1);
    // cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}

