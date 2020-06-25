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

bool cond(pair<int, int> a, pair<int, int> b) {
    return a.first == b.first ? a.second < b.second : a.first < b.first;
}

int find(vector<pair<int, int>> &v, int n, int val) {
    int l = 0, u = n, res(n);
    while (l < u) {
        int m = (l + u) >> 1;
        if (v[m].first > val) {
            res = min(m, res);
            u = m;
        }
        else l = m + 1;
    }
    return res;
}

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int sum[n], mn(0);
    memset(sum, 0, sizeof sum);
    for (int i = 0; i < n; i++) {
        s[i] == '+' ? sum[i] = 1 : sum[i] = -1;
        if(i > 0) sum[i] += sum[i - 1];
        mn = min(sum[i], mn);
    }  
    mn *= -1;
    std::vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) 
        v.push_back({sum[i] *= -1, i + 1});
    v.push_back({INT_MAX, n + 1});
    sort(v.begin(), v.end());
    i_64 res = n;
    for (int i = 0; i < mn; i++) {
        int j = find(v, n, i);
        res += v[j].second;
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
