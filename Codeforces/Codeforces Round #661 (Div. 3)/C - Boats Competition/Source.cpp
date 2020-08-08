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
    for (int &i: a) cin >> i;
    std::vector<pair<int, int>> sum;
    for (int i = 0; i < n; i++) 
        for (int j = i + 1; j < n; j++) sum.push_back({a[i], a[j]});
    int res(0);
    for (int i = 0; i < sum.size(); i++) {
        int sm = sum[i].first + sum[i].second;
        int mp[n + 1];
        memset(mp, 0, sizeof mp);
        for (int j = 0; j < n; j++) {
            mp[a[j]]++;
        }
        mp[sum[i].first]--;
        mp[sum[i].second]--;
        int cnt(1);
        for (int j = 0; j < n; j++) {
            if (sm <= a[j] or sm - a[j] > n) continue;
            if (!mp[a[j]] or !mp[sm - a[j]]) continue;
            if (a[j] == sm - a[j] and mp[a[j]] < 2) continue;
            cnt++;
            mp[a[j]]--;
            mp[sm - a[j]]--;
        }
        res = max(res, cnt);
    }
    cout << res << "\n";
}

signed main() {
    __AcHiLlEs
  
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
