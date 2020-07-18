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
#define i_64 long long

void solve() {
    i_64 n, mn(INT_MAX);
    cin >> n;
    std::map<i_64, i_64> total, a, b;
    for (i_64 i = 0; i < n; i++) {
        i_64 x;
        cin >> x;
        total[x]++; 
        a[x]++;
    }
    for (i_64 i = 0; i < n; i++) {
        i_64 x;
        cin >> x;
        total[x]++;
        b[x]++;
    }
    for (auto &i: total) {
        if (i.second & 1) {
            cout << "-1\n";
            return;
        }
        mn = min(i.first, mn);
        i.second >>= 1;
    }
    std::vector<pair<i_64, i_64>> resa, resb;
    i_64 as(0), bs(0);
    for (auto &i : a) 
        if (i.second > total[i.first]) resa.push_back({i.first, i.second - total[i.first]}), as++;    
    for (auto &i : b) 
        if (i.second > total[i.first]) resb.push_back({i.first, i.second - total[i.first]}), bs++;
    sort(resa.begin(), resa.end());
    sort(resb.begin(), resb.end());
    i_64 res(0);
    i_64 i = 0, j = bs - 1;
    int fix = mn << 1;
    while (i < as and resa[i].first < fix) {
        if (resa[i].second == 0) break;
        while (resa[i].second != 0 and j >= 0) {
            i_64 cnt = min(resa[i].second, resb[j].second);
            i_64 cost = min(resa[i].first, resb[j].first);
            resb[j].second -= cnt;
            resa[i].second -= cnt;
            res += (cnt * cost);
            if (resa[i].second != 0) j--;
        }
        i++;
    }
    i = 0, j = as - 1;
    while (i < bs and resb[i].first < fix) {
        if (resb[i].second == 0) break;
        while (resb[i].second != 0 and j >= 0) {
            i_64 cnt = min(resb[i].second, resa[j].second);
            i_64 cost = min(resb[i].first, resa[j].first);
            resa[j].second -= cnt;
            resb[i].second -= cnt;
            res += (cnt * cost);
            if (resb[i].second != 0) j--;
        }
        i++;
    }
    i_64 left(0);
    while (i < bs and resb[i].second != 0) left += resb[i++].second;
    res += (left * fix);
    cout << res << "\n";
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs
  
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
