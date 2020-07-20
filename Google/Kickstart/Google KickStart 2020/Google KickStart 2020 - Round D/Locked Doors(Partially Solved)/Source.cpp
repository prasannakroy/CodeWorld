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
    int n, q;
    cin >> n >> q;
    int a[n - 1];
    for (int &i: a) cin >> i;
    while (q--) {
        int s, k;
        cin >> s >> k;
        if (k == 1) cout << s << " ";
        else if (s == 1) cout << k << " ";
        else if (s == n) cout << n - k + 1 << " ";
        else {
            int l = s - 2;
            int r = s - 1;
            int cnt = 1, res;
            while (cnt < k) {
                // cout << l << " " << r << "\n";
                if (l < 0) r++, res = r + 1;
                else if (r >= n - 1) l--, res = l + 2;
                else if (a[l] < a[r]) l--, res = l + 2;
                else if (a[l] > a[r]) r++, res = r + 1;
                // cout << res << ":\n";
                cnt++;
            }
            cout << res << " ";
        }
    }
    cout << "\n";
}

signed main() {
    __AcHiLlEs
  
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; cout << "Case #" << i << ": ", solve(), i++);
    return 0;
}
