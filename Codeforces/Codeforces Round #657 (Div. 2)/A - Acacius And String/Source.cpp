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

bool check(string s, string t, int n) {
    int cnt(0);
    for (int i = 0; i <= n - 7; i++) {
        bool flag(1);
        for (int j = 0; j < 7; j++) {
            if (s[i + j] != t[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) cnt++;
    }
    if (cnt > 1) return false;
    return true;
}

void solve() {
    int n, cnt(0);
    cin >> n;
    string s, t("abacaba"), s2;
    cin >> s;
    for (int i = 0; i <= n - 7; i++) {
        bool flag(1);
        for (int j = 0; j < 7; j++) {
            if (s[i + j] != t[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) cnt++;
    }
    if (cnt == 1) {
        cout << "YES\n";
        char r = 'd';
        for (char &i: s) {
            if (i == '?') i = r;
            cout << i;
        }
        cout << "\n";
        return;
    }
    if (cnt > 1) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i <= n - 7; i++) {
        bool flag(1);
        s2 = s;
        for (int j = 0; j < 7; j++) {
            if (s2[i + j] == '?') 
                s2[i + j] = t[j];
            if (s2[i + j] != t[j]) {
                flag = 0;
                break;
            }
        }
        for (char &i: s2) if (i == '?') i = 'd';
        if (!flag) s2 = s;
        if (flag == 1) {
            if (check(s2, t, n)) {
                s = s2;
                cnt++;
                break;
            }
            else s2 = s;
        }
    }
    if (!cnt) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << s << "\n";
}

signed main() {
    __AcHiLlEs
  
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
