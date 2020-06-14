/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

// #define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define i_64 long long

void solve() {
    i_64 n, res(0), mx(LLONG_MIN);
    cin >> n;
    i_64 a[n];
    std::map<i_64, i_64> m;
    for (i_64 &i: a) cin >> i, m[i]++, mx = max(i, mx);
    sort(a, a + n);
    for (i_64 &i: a) {
        if (m[i] == 1) res++;
        i_64 x = i;
        m[i] += 2;
        while (x <= mx) {
            x += i;
            m[x]++;
        }
    }
    cout << res << "\n";
}

signed main() {
    // #ifndef ONLINE_JUDGE 
    //     __AnAkLuSmOs    
    // #endif

    __AcHiLlEs

    i_64 t(1);
    // cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
    