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
    int n, flag(1), cnt(0);
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0 and a[i] < a[i - 1]) flag = 0;
    }
    for (int &i: b) cin >> i, cnt += i;
    if (flag) {
        cout << "Yes\n";
        return;
    }
    if (cnt > 0 and cnt < n) 
        cout << "Yes\n";
    else 
        cout << "No\n";
}

signed main() {
    __AcHiLlEs

    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}

