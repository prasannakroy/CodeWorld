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
    i_64 n, k, res(0), mx(0);
    cin >> n >> k;
    i_64 a[n];
    std::map<i_64, i_64> m;
    for (i_64 &i: a) cin >> i, i %= k, i = (k - i) % k, m[i]++;
    sort(a, a + n);
    for (auto &i: m) {
        if (i.first == 0) continue;
        i_64 x = ((i.second - 1) * k) + i.first + 1;
        res = max(res, x);
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
