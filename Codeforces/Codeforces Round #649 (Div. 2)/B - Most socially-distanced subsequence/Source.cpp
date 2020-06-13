/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define i_64 long long

void solve() {
    int n;
    cin >> n;
    int a[n];
    int num[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    std::vector<int> res;
    int i = 0;
    res.push_back(a[0]);
    while (i < n - 1) {
        if (a[i + 1] < a[i]) {
            while (a[i + 1] < a[i] and i < n - 1) i++;
            res.push_back(a[i]);
        }
        else {
            while (a[i + 1] > a[i] and i < n - 1) i++;
            res.push_back(a[i]);
        }
    }
    cout << res.size() << "\n";
    for (int &i: res) cout << i << " ";
    cout << "\n";
}

signed main() {
    __AcHiLlEs

    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
