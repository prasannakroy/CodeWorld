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
    int a[2 * n];
    for (int &i: a) cin >> i;
    std::map<int, bool> m;
    std::vector<int> res;
    for (int &i: a) if (!m[i]) res.push_back(i), m[i] = 1;
    for (int &i: res) cout << i << " ";
    cout << "\n";
}

signed main() {
    __AcHiLlEs
  
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case #" << i << ": ",*/ solve(), i++);
    return 0;
}
