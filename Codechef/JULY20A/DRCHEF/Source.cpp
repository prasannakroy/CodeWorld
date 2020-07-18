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
    i_64 n, x, res(0);
    cin >> n >> x;
    std::vector<i_64> a(n);
    for (i_64 &i: a) cin >> i;
    sort(a.begin(), a.end());
    bool check[n];
    memset(check, 0, sizeof check);
    i_64 ptr = 0, ind = 0, cnt(2);
    while (ind < n) {
        ind = lower_bound(a.begin() + ptr, a.end(), (x + 1) >> 1) - a.begin();
        if (ind >= n) break;
        if (a[ind] <= x) {
            check[ind] = 1;
            ptr = ind + 1;
        }
        res++;
        x = min(a[ind], x);
        x <<= 1;
    }
    for (i_64 i = 0; i < n; i++) if (!check[i])res++;
    cout << res << "\n";
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
