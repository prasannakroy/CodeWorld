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

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    if (a + b - c > n) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    if (n != 1 and a == 1 and b == 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    int x = n - a - b + c;
    vector<int> res;
    a -= c;
    b -= c;
    int val(n - a);
    for (int i = 0; i < a; i++) 
        res.push_back(val++);
    if (a < b) {
        for (int i = 0; i < ((c + 1) / 2); i++) 
            res.push_back(val);
        for (int i = 0; i < x; i++) 
            res.push_back(1);
        for (int i = 0; i < (c / 2); i++) 
            res.push_back(val);
        for (int i = 0; i < b; i++) 
            res.push_back(--val);
    }
    else {
        for (int i = 0; i < (c / 2); i++) 
            res.push_back(val);
        for (int i = 0; i < x; i++) 
            res.push_back(1);
        for (int i = 0; i < ((c + 1) / 2); i++) 
            res.push_back(val);
        for (int i = 0; i < b; i++) 
            res.push_back(--val);
    }
    for (int &i: res) cout << i << " ";
    cout << "\n";
}

signed main() {
    __AcHiLlEs
  
    int t(1);
    cin >> t;
    for (int i = 1; i <= t; cout << "Case #" << i << ": ", solve(), i++);
    return 0;
}
