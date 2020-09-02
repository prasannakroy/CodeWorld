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
    int n;
    cin >> n;
    int a[n];
    for (int &i: a) cin >> i;
    int cnt(1), i(0);
    while (i < n - 1) {
        int c(1);
        int x = a[i + 1] - a[i];
        while ((i + 1 < n) and a[i + 1] - a[i] == x) i++, c++;
        cnt = max(cnt, c);
    }
    cout << cnt << "\n";
}

signed main() {
    __AcHiLlEs
  
    int t(1);
    cin >> t;
    for (int i = 1; i <= t; cout << "Case #" << i << ": ", solve(), i++);
    return 0;
}
