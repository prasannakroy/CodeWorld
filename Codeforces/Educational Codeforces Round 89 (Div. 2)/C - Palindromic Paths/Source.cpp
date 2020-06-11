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
    int n, m;
    cin >> n >> m;
    int a[n][m], d[n][m];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> a[i][j];
    map<int, int> m1, m0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = min(i + j, m + n - 2 - i - j);
            if ((m + n - 1) & 1 and x == (m + n - 1) / 2) continue;
            if (a[i][j] == 0) m0[x]++;
            else m1[x]++;
        }
    }
    int res(0);
    for (int i = 0; i <= m + n - 2; i++) 
        res += min(m0[i], m1[i]);
    cout << res << "\n";
}

signed main() {
    __AcHiLlEs

    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
