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
    int n;
    cin >> n;
    int a[n];
    std::map<int, int> ind;
    for (int i = 0; i < n; i++) cin >> a[i], ind[a[i]] = i;
    int flag = 0, flag2 = 0;
    int i = 0;
    while (a[i] == i + 1 and i < n) i++;
    int l = i;
    i = n - 1;
    while (a[i] == i + 1 and i >= 0) i--;
    int r = i;
    if (l >= r) {
        cout << 0 << "\n";
        return;
    }
    for (int i = l; i <= r; i++) {
        if (a[i] == i + 1) flag = 1;
    }
    if (!flag) 
        cout << 1 << "\n";
    else cout << 2 << "\n";
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
