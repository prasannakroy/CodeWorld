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
    i_64 n, c0(0), mx(0);
    cin >> n;
    i_64 a[n];
    i_64 res[n + 1];
    memset(res, -1, sizeof res);
    map<i_64, i_64> m, mp;
    // m[0] = -1;
    for (i_64 i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]] = i;
        mp[a[i]]++;
    }
    for (auto &i: m) {
        res[i.second + 1] = i.first;
        mp[i.first] += 1;
    }
    bool flag(1);
    i_64 cnt(0);
    for (i_64 i = 0; i < n; i++) {
        if (res[i] != -1) continue;
        if (a[i] > i + 1) {
            flag = 0;
            break;
        }
        while (mp[cnt]) 
            cnt++;
        res[i] = cnt++;
        mp[a[i]]--;
    }
    if (flag)
        for (i_64 i = 0; i < n; i++) 
            cout << res[i] << " ";
    else cout << -1;
}

signed main() {
    __AcHiLlEs

    i_64 t(1);
    // cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
