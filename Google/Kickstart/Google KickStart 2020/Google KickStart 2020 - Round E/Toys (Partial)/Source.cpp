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
    int n, res(0), cnt(0);
    cin >> n;
    std::vector<pair<int, int>> v(n);
    for (auto &i: v) 
        cin >> i.first >> i.second;
    bool flag(1);
    for (int i = (1 << n) - 1; i >= 1; i--) {
        int x = i, sol(0), t(0), c(0);
        for (int j = 0; j < n; j++) {
            if (x & (1 << j)) {
                sol += v[j].first;
                t += v[j].first;
                c++;
            }
        }
        flag = 1;
        for (int j = 0; j < n; j++) {
            if (x & (1 << j)) {
                if (t - v[j].first < v[j].second) {
                    flag = 0;
                    break;
                }
                sol += v[j].first;
            }
        }
        if (flag) {
            cnt = n - c;
            break;
        }
        if (sol > res) {
            res = sol;
            cnt = n - c;
        }
    }
    if (flag) cout << cnt << " INDEFINITELY\n";
    else cout << cnt << " " << res << "\n";
}

signed main() {
    __AcHiLlEs
  
    int t(1);
    cin >> t;
    for (int i = 1; i <= t; cout << "Case #" << i << ": ", solve(), i++);
    return 0;
}
