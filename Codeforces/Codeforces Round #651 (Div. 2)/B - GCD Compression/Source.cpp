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
    int n, x;
    cin >> n;
    n <<= 1;
    std::vector<pair<int, int>> o, e;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x & 1) o.push_back({x, i + 1});
        else e.push_back({x, i + 1});
    }
    int cnt(0);
    if (o.size() & 1) o.pop_back(), cnt++;
    if (cnt == 1) e.pop_back();
    else {
        if (!e.empty()) {
            e.pop_back();
            e.pop_back();
        }
        else {
            o.pop_back();
            o.pop_back();
        }
    }
    for (int i = 0; i < e.size(); i += 2) cout << e[i].second << " " << e[i + 1].second << "\n";
    for (int i = 0; i < o.size(); i += 2) cout << o[i].second << " " << o[i + 1].second << "\n";
}

signed main() {
    __AcHiLlEs

    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
