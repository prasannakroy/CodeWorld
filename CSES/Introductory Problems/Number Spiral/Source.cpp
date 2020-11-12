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
#define int long long
#define span(a) a.begin(), a.end()
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)
 
void solve() {
    int x, y;
    cin >> x >> y;
 
    function<int(int, int)> findVal = [&] (int x, int y) {
        if (x > y) {
            if (x & 1) return ((x - 1) * (x - 1)) + y;
            else return x * x - y + 1;
        }
        else {
            if (y & 1) return y * y - x + 1;
            else return ((y - 1) * (y - 1)) + x;
        }
    };
 
    cout << findVal(x, y) << "\n";
}
 
signed main() {
    // #ifndef ONLINE_JUDGE 
    //     __AnAkLuSmOs    
    // #endif
 
    __AcHiLlEs
 
    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}