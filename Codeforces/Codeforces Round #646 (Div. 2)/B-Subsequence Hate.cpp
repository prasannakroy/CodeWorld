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
#define i_64 long long

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int c0[n + 1], c1[n + 1];
    memset(c1, 0, sizeof c1);
    memset(c0, 0, sizeof c0);
    for(int i = 0; i < n; i++) {
        c1[i + 1] = c1[i];
        c0[i + 1] = c0[i];
        s[i] == '0'? c0[i + 1] += 1: c1[i + 1] += 1;
    }
    int mx = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            mx = max(mx, c0[i + 1] + c1[j + 1] - c1[i + 1]);
            mx = max(mx, c1[i + 1] + c0[j + 1] - c0[i + 1]);
        }
    }
    cout << n - mx << "\n";
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
