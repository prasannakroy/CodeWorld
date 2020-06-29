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
    i_64 n, k, x, y, z;
    cin >> n >> k;
    std::vector<i_64> t, a, b;
    for (i_64 i = 0; i < n; i++) {
        cin >> x >> y >> z;
        if (y & z) t.push_back(x);
        else if (y) a.push_back(x);
        else if (z) b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (i_64 i = 0; i < min(a.size(), b.size()); i++) t.push_back(a[i] + b[i]);
    if (t.size() < k) {
        cout << -1 << "\n";
        return;
    }
    sort(t.begin(), t.end());
    i_64 res(0);
    for (i_64 i = 0; i < k; i++) res += t[i];
    cout << res << "\n";
}

signed main() {
    __AcHiLlEs
  
    i_64 t(1);
    // cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
