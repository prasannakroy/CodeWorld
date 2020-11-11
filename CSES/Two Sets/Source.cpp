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
 
void solve() {
    int n;
    cin >> n;
    if ((n * (n + 1)) % 4 != 0) {
        cout << "NO\n";
        return;
    }
    vector<int> a, b;
    int k = !(n & 1);
    if (!k) b.push_back(n);
    for (int i = 1; i <= n / 2; i++) {
        if (i & 1) a.push_back(i), a.push_back(n - i + k);
        else b.push_back(i), b.push_back(n - i + k);
    }
    cout << "YES\n";
    cout << a.size() << "\n";
    for (auto &i: a) cout << i << " ";
    cout << "\n" << b.size() << "\n";
    for (auto &i: b) cout << i << " ";
    cout << "\n";
}
 
signed main() {
    // #ifndef ONLINE_JUDGE 
    //     __AnAkLuSmOs    
    // #endif
 
    __AcHiLlEs
 
    int t(1);
    // cin >> t; 
    for (int i = 1; i <= t; /*cout << "Case #" << i << ": ",*/ solve(), i++);
    return 0;
}