/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include <bits/stdc++.h> 
using namespace std; 

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define i_64 long long

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int &i: a) cin >> i;
    int i = n - 1;
    while (i - 1 >= 0 and a[i] <= a[i - 1]) i--;
    while (i - 1 >= 0 and a[i] >= a[i - 1]) i--;
    cout << i << "\n";
}

signed main() {
    __AcHiLlEs
  
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case #" << i << ": ",*/ solve(), i++);
    return 0;
}
