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
    vector<pair<int, int>> v(n);
    for (auto &i: v) cin >> i.first;
    for (auto &i: v) cin >> i.second;
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    int res(INT_MAX), sum(0);
    for (int i = 0; i <= n; i++) {
        if (i < n) {
            int t = max(sum, v[i].first);
            res = min(t, res);
            sum += v[i].second;
        }
        else 
            res = min(res, sum);
    }
    cout << res << "\n";
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case #" << i << ": ",*/ solve(), i++);
    return 0;
}