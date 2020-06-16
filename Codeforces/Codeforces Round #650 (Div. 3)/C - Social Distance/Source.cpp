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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int a[n];
    memset(a, 0, sizeof a);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') a[i] = k + 1;
        else if (a[i] == 0 and i > 0) a[i] = max(0, a[i - 1] - 1);
    }
    for (int i = n - 1; i >= 0; i--) 
        if (a[i] == 0 and i < n - 1) a[i] = max(0, a[i + 1] - 1);
    int res(0);
    for (int i = 0; i < n; i++) {
        if (a[i] == 0 and i == 0) {
            a[i] = k + 1;
            res++;
            continue;
        }
        if (i > 0 and a[i] == 0) a[i] = max(0, a[i - 1] - 1);
        if (a[i] == 0) {
            a[i] = k + 1;
            res++;
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
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
    