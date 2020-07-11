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
    i_64 n;
    cin >> n;
    i_64 a[n];
    for (i_64 &i: a) cin >> i;
    i_64 prefe[n], prefo[n];
    prefe[0] = 0;
    prefe[1] = a[1];
    prefo[0] = a[0];
    prefo[1] = a[0];
    for (int i = 2; i < n; i++) {
        if (i & 1) prefe[i] = a[i] + prefe[i - 2], prefo[i] = prefo[i - 1];
        else prefo[i] = a[i] + prefo[i - 2], prefe[i] = prefe[i - 1];
    }
    i_64 res(0);
    for (int i = 0; i < n; i++) {
        i_64 sum;
        if (i == 0) 
            sum = prefo[n - 1];
        else if (i & 1) {
            sum = prefe[n - 1] - prefe[i - 1];
            sum += prefo[i];
        }
        else {
            sum = prefo[n - 1] - prefo[i - 1];
            sum += prefe[i];
        }
        res = max(sum, res);
    } 
    cout << res << "\n";
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs
  
    i_64 t(1);
    // cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
