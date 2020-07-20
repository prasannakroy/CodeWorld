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
    for (int &i: a) cin >> i;
    int res(0), i = 1;
    while (i < n) {
        if (a[i] < a[i - 1]) {
            int cnt = 0;
            while (a[i] <= a[i - 1] and i < n) {
                if (a[i] < a[i - 1]) cnt++;
                i++;
                if (cnt > 3) res++, cnt = 0;
            }
        }
        else if (a[i] > a[i - 1]) {
            int cnt(0);
            while (a[i] >= a[i - 1] and i < n) {
                if (a[i] > a[i - 1]) cnt++;
                i++;
                if (cnt > 3) res++, cnt = 0;
            }
        }
        else i++;
    }
    cout << res << "\n";
}

signed main() {
    __AcHiLlEs
  
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; cout << "Case #" << i << ": ", solve(), i++);
    return 0;
}
