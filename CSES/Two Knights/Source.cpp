/*****************************
*  Author :: Prasanna Kumar  *
*****************************/
 
/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;
 
#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
 
int compute(int a) {
    int r = 4;
    int g = 8;
    int y = 4 * (a - 3);
    int p = 4 * (a - 4);
    int b = max(0ll, (a * a) - r - g - y - p);
    int n = a * a;
    int res = (r * (n - 3));
    res += (g * (n - 4));
    res += (y * (n - 5));
    res += (p * (n - 7));
    res += (b * (n - 9));
    return (res >> 1ll);
}
 
void solve() {
    int n;
    cin >> n;
    std::vector<int> v;
    v.push_back(0);
    v.push_back(6);
    v.push_back(28);
    for (int i = 1; i <= n; i++) {
        if (i < 4) cout << v[i - 1] << "\n";
        else cout << compute(i) << "\n";
    }
}
 
signed main() {
    __AcHiLlEs
  
    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}