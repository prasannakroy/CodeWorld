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
#define span(a) a.begin(), a.end()
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)

void solve() {
    string s;
    cin >> s;
    vector<int> c(26, 0);
    for (auto &i: s) c[i - 'A']++;
    int o(0), x(-1);
    string res("");
    for (int i = 0; i < 26; i++) {
        if (c[i] & 1) 
            o++, x = i;
        for (int j = 0; j < (c[i] / 2); j++) res += ('A' + i);
    }
    if (o > 1) {
        cout << "NO SOLUTION\n";
        return;
    }
    cout << res;
    if (~x) cout << (char)('A' + x);
    reverse(span(res));
    cout << res << "\n";
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}