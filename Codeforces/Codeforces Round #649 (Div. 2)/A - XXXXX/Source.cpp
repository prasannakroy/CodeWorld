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
    int n, x;
    cin >> n >> x;
    int a[n], sum = 0, flag(1);
    for (int &i: a) {
        cin >> i;
        i %= x;
        if (i != 0) {
            flag = 0;
        }
        sum += i;
    }
    if (flag) {
        cout << -1 << "\n";
        return;
    }
    int res(n);
    if (sum % x == 0) {
        int i = 0, cnt(0), cnt2(0);
        while (a[i++] == 0) 
            cnt++;
        i = n - 1;
        while (a[i--] == 0) 
            cnt2++;
        res = n - min(cnt, cnt2) - 1;
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
