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
    priority_queue<pair<int, pair<int, int>>> q;
    int res[n], cnt(1);
    q.push({n, {0, n - 1}});
    while (!q.empty()) {
        pair<int, pair<int, int>> p = q.top();
        q.pop();
        int x = p.first;
        int y = -1 * p.second.first;
        int z = p.second.second;
        int m = (z + y) >> 1;
        res[m] = cnt++;
        if (y <= m - 1) {
            int l = m - y;
            q.push({l, {-y, m - 1}});
        }
        if (m + 1 <= z) {
            int l = z - m;
            q.push({l, {-1 * (m + 1), z}});
        }
    }
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
