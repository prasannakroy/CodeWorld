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
    string a;
    cin >> a;
    int n = a.length();
    vector<int> cnt(n, 0);
    int res(0);
    for (int i = 3; i < n; i++) {
        if (a[i - 3] == 'K' and a[i - 2] == 'I' and a[i - 1] == 'C' and a[i] == 'K') cnt[i] = cnt[i - 1] + 1;
        else {
            cnt[i] = cnt[i - 1];
            if (i > 3 and a[i - 4] == 'S' and a[i - 3] == 'T' and a[i - 2] == 'A' and a[i - 1] == 'R' and a[i] == 'T') res += cnt[i];
        }
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