/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    int cnt(0), start(a[0].first);
    for (int i = 0; i < n; i++) {
        if (start > a[i].second) continue;
        start = max(a[i].first, start);
        int x = a[i].second - start;
        x = ((x + k - 1) / k);
        cnt += x;
        start = start + (x * k);
    }
    cout << cnt << "\n";
}

signed main() {

    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; cout << "Case #" << i << ": ", solve(), i++);
    return 0;
}
