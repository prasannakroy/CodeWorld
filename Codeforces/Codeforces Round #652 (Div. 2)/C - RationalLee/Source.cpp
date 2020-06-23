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
    i_64 n, k, t(0), res(0), m(0);
    cin >> n >> k;
    vector<i_64> a(n), b(k);
    for (i_64 &i: a) cin >> i;
    for (i_64 &i: b) cin >> i;
    sort(a.begin(), a.end(), greater<i_64>());
    sort(b.begin(), b.end());
    for (int i = 0; i < k; i++) {
        res += a[i]; 
        b[i]--;
        if (b[i] == 0) res += a[i];
    }
    int j = k - 1;
    for (int i = 0; i < k; i++) {
        if (!b[i])
            continue;
        res += a[j + b[i]];
        j += b[i];
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
