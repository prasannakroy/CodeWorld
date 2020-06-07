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

std::vector<pair<i_64, i_64>> a(100001);
i_64 MX = (i_64)1e18;
i_64 n, w, l;

void solve() {
    int n, m, r(0), c(0);
    cin >> n >> m;
    int a[n][m], rsum[n], csum[m];
    memset(rsum, 0, sizeof rsum);
    memset(csum, 0, sizeof csum);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            rsum[i] += a[i][j];
            csum[j] += a[i][j];
        }
        if (rsum[i] == 0) r++;
    }
    for (int i = 0; i < m; i++) 
        if (csum[i] == 0) c++;
    int x = min(r, c);
    if (x & 1) 
        cout << "Ashish\n";
    else 
        cout << "Vivek\n";
}

signed main() {
    __AcHiLlEs

    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}

