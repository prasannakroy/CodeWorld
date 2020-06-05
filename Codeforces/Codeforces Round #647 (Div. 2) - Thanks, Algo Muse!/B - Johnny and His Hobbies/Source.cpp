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
    int n;
    cin >> n;
    int a[n];
    std::map<int, int> m;
    for (int &i: a) {
        cin >> i;
        m[i]++;
    }
    bool flag = 0;
    int res = -1;
    for (int i = 1; i <= 1024; i++) {
        std::map<int, int> mp;
        for (int j = 0; j < n; j++) {
            mp[a[j] ^ i]++;
        }
        flag = 0;
        for (int j = 0; j < n; j++) {
            if (mp[a[j]] != m[a[j]]) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            res = i;
            break;
        }
    }
    cout << res << "\n";
}

signed main() {
    __AcHiLlEs

    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
