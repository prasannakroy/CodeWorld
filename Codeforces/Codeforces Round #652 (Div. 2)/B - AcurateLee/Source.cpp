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
    if (s.length() == 1) {
        cout << s << "\n";
        return;
    }
    string resl(""), resr("");
    int i = 0;
    while (s[i] != '1' and i < n) resl += s[i++];
    int j = n - 1;
    while (s[j] != '0' and j >= 0) resr += s[j--];
    if (resl.length() + resr.length() == n) cout << resl << resr << "\n";
    else cout << resl << "0" << resr << "\n";
}

signed main() {
    __AcHiLlEs
    
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
