/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define i_64 unsigned long long

vector<i_64> mp[1000001];

void solve() {
    i_64 n, m, x, y;
    cin >> n >> m;
    vector<pair<i_64, i_64>> v;
    for (i_64 i = 0; i < m; i++) {
        cin >> x >> y;
        v.push_back({x, y});
    }
    vector<pair<i_64, i_64>> t(n);
    vector<i_64> check(n + 1);
    for (i_64 i = 0; i < n; i++) {
        cin >> t[i].first;
        check[i + 1] = t[i].first;
        t[i].second = i + 1;
    }
    for (i_64 i = 0; i < m; i++) {
        x = v[i].first;
        y = v[i].second;
        if (check[x] >= check[y]) {
            mp[y].push_back(x);
        }
        if (check[y] >= check[x]) {
            mp[x].push_back(y);
        }
    }
    sort(t.begin(), t.end());
    std::map<i_64, i_64> sum;
    map<pair<i_64, i_64>, i_64> c;
    vector<i_64> res;
    bool flag = 0;
    for (i_64 i = 0; i < n; i++) {
        x = (t[i].first * (t[i].first - 1)) / 2;
        if (x != sum[t[i].second]) {
            flag = 1;
            break;
        }
        res.push_back(t[i].second);
        for (i_64 &j: mp[t[i].second]) {
            if (c[{j, t[i].first}] != 1) {
                sum[j] += t[i].first;
                c[{j, t[i].first}] = 1;
            }
        }
    }
    if (flag) {
        cout << -1 << "\n";
        return;
    }
    for (i_64 &i : res) cout << i << " ";
    cout << "\n";
}

signed main() {
    __AcHiLlEs

    i_64 t(1);
    // cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}

