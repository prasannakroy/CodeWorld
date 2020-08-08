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
    string s;
    cin >> s;
    int cnt(0);
    int res[n];
    int i = 0;
    int r(0);
    char v[n + 1];
    for (int i = 1; i <= n; i++) v[i] = 'x';
    while (i < n) {
        int cnt(1);
        if (v[cnt] == 'x') {
            res[i] = cnt;
            v[cnt] = s[i];
        }
        else {
            while (v[cnt] == s[i]) cnt++;
            res[i] = cnt;
            v[cnt] = s[i];
        }
        while (i + 1 < n and s[i] == s[i + 1]) {
            i++;
            cnt++;
            if (v[cnt] == 'x') {
                res[i] = cnt;
                v[cnt] = s[i];
            }
            else {
                while (v[cnt] == s[i]) cnt++;
                res[i] = cnt;
                v[cnt] = s[i];
            }
        }
        r = max(cnt, r);
        i++;
    }
    cout << r << "\n";
    for (int &j: res) cout << j << " ";
    cout << "\n";
}

signed main() {
    __AcHiLlEs
  
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
