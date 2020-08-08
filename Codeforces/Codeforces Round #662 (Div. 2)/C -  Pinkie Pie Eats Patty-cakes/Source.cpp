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

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

void solve() {
    int n, mx(0), h(0);
    cin >> n;
    int a[n];
    std::map<int, int> m;
    for (int &i: a) 
        cin >> i, m[i]++;
    vector<pair<int, int>> vec;
    copy(m.begin(), m.end(), back_inserter(vec));
    sort(vec.begin(), vec.end(), cmp);
    mx = vec[0].second;
    h = vec[0].first;
    vector<int> v;
    int cnt(0);
    while (cnt < n) {
        for (auto &i: vec) 
            if (i.second) v.push_back(i.first), i.second--, cnt++;
    }
    for (auto &i: m) i.second = -1;
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (m[v[i]] == -1) {
            m[v[i]] = i;
        }
        else {
            int d = i - m[v[i]] - 1;
            m[v[i]] = i;
            if (v[i] == h) 
                t += d;
        }
    }
    if (!t) cout << t << "\n";
    else {
        cout << t / (mx - 1) << "\n";
    }
}

signed main() {
    __AcHiLlEs
  
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
