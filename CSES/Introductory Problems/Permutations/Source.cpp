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
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }
    if (n <= 3) {
        cout << "NO SOLUTION\n";
        return;
    }
    for (int i = 1; i <= n / 2; i++) cout << (2 * i) << " ";
    for (int i = 0; i < (n + 1) / 2; i++) cout << (2 * i + 1) << " ";
    cout << "\n";
}
 
signed main() {
    // #ifndef ONLINE_JUDGE 
    //     __AnAkLuSmOs    
    // #endif
 
    __AcHiLlEs
 
    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}