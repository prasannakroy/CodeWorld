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
    std::map<int, int> m;
    for (int &i: a) cin >> i, m[i]++;
    int q;
    cin >> q;
    int cnt4(0), cnt2(0);
    for (auto &[a, b]: m) {
        cnt4 += (b / 4);
        cnt2 += (b % 4) / 2;
    }
    while (q--) {
        string s;
        int x;
        cin >> s >> x;
        cnt4 -= (m[x] / 4);
        cnt2 -= (m[x] % 4) / 2;
        if (s[0] == '+') m[x]++;
        else m[x]--;
        cnt4 += (m[x] / 4);
        cnt2 += (m[x] % 4) / 2;
        if (cnt4 == 0 or (cnt4 < 2 and cnt2 < 2)) cout << "NO\n";
        else cout << "YES\n";
    }
}

signed main() {
    __AcHiLlEs
  
    i_64 t(1);
    // cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
