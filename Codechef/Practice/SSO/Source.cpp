/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long

void solve() {
    int n, sum(0);
    cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i, sum += i;
    int cnt = ceil(log2(sum));
    int res(0);
    vector<int> m(65, 0);
    for (int i = 0; i < n; i++) {
        int c(0);
        while ((1ll << c) <= a[i]) {
            if ((1ll << c) & a[i]) 
                res |= (1ll << c), m[c]++;
            c++;
        }
    }
    for (int i = 0; i <= 64; i++) {
        if (m[i]) 
            res |= (1ll << i);
        if (i + 1 < 65) m[i + 1] += (m[i] >> 1);
    }
    cout << res << "\n";
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case #" << i << ": ",*/ solve(), i++);
    return 0;
}