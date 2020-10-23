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
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool f1 = 0, f2 = 0;
    for (auto &i: s) {
        f1 |= (i == '<');
        f2 |= (i == '>');
    }
    int cnt(0);
    if (f1 and f2) {
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (s[n - 1] == '-' or s[i] == '-') 
                    cnt++;
            }
            else if (s[i - 1] == '-' or s[i] == '-') 
                cnt++;
        }
        cout << cnt << "\n";
    }
    else cout << n << "\n";
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