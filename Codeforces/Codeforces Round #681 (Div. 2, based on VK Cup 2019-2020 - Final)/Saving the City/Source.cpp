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
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int n = s.length();
    int i = 0, flag(1);
    int res(0), prev(INT_MAX);
    while (i < n) {
        if (s[i] == '0' and flag) {
            i++;
            continue;
        }
        else if (s[i] == '1') {
            flag = 0;
            while (i < n and s[i] == '1') i++;
            if (prev > a) res += a;
            else res += prev;
        }
        else {
            int cnt(0);
            while (i < n and s[i] == '0') i++, cnt++;
            prev = b * cnt;
        }
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