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
    int n, resx, resy;
    cin >> n;
    std::vector<int> x(4 * n - 1), y(4 * n - 1);
    for (int i = 0; i < 4 * n - 1; i++) cin >> x[i] >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int i = 0;
    while (i < ((4 * n) - 1)) {
        int cnt = 1;
        while (i + 1 < ((4 * n) - 1) and x[i] == x[i + 1]) i++, cnt++;
        if (cnt & 1) {
            resx = x[i];
            break;
        }
        i++;
    }
    i = 0;
    while (i < ((4 * n) - 1)) {
        int cnt = 1;
        while (i + 1 < ((4 * n) - 1) and y[i] == y[i + 1]) i++, cnt++;
        if (cnt & 1) {
            resy = y[i];
            break;
        }
        i++;
    }
    cout << resx << " " << resy << "\n";
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
