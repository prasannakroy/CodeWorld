/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

// #define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define i_64 long long

void solve() {
    int n;
    cin >> n;
    int cnt[n + 1];
    memset(cnt, 0, sizeof cnt);
    int a, b, c;
    std::vector<pair<int, int>> v[n + 1];
    std::map<pair<int, int>, vector<int>> m;
    for (int i = 0; i < n - 2; i++) {
        cin >> a >> b >> c;
        v[a].push_back({min(b, c), max(b, c)});
        v[b].push_back({min(a, c), max(a, c)});
        v[c].push_back({min(a, b), max(a, b)});
        m[{min(b, c), max(b, c)}].push_back(a);
        m[{min(a, c), max(a, c)}].push_back(b);
        m[{min(a, b), max(a, b)}].push_back(c);
    }
    int res[n], flag(0);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) { 
        if (v[i].size() == 1) {
            if (flag == 1) {
                mp[i] = 1;
                res[n - 1] = i;
                a = v[i][0].first;
                b = v[i][0].second;
                if (v[a].size() == 2) {
                    mp[a] = 1;
                    res[n - 2] = a;
                }
                else {
                    mp[b] = 1;
                    res[n - 2] = b;
                }
            }
            else {
                mp[i] = 1;
                res[0] = i;
                a = v[i][0].first;
                b = v[i][0].second;
                if (v[a].size() == 2) {
                    mp[a] = 1;
                    res[1] = a;
                }
                else {
                    mp[b] = 1;
                    res[1] = b;
                }
                flag = 1;
            }
        }
    }
    for (int i = 2; i < n - 2; i++) {
        a = min(res[i - 1], res[i - 2]);
        b = max(res[i - 1], res[i - 2]);
        int x = m[{a, b}][0];
        int y = m[{a, b}][1];
        if (!mp[x]) {
            mp[x] = 1;
            res[i] = x;
        }
        else {
            mp[y] = 1;
            res[i] = y;
        }
    }
    for (int &i: res) cout << i << " ";
    cout << "\n";
}

signed main() {
    // #ifndef ONLINE_JUDGE 
    //     __AnAkLuSmOs    
    // #endif

    __AcHiLlEs

    i_64 t(1);
    // cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
