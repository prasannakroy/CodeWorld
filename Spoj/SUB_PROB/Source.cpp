/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) a.begin(), a.end()
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)

int p1 = 67, p2 = 71;
int mod = (int)1e9 + 7;

int calcVal(char a) {
    int x = 0;
    if (a >= 'a' and a <= 'z') x = a - 'a' + 1;
    else if (a >= 'A' and a <= 'Z') x = a - 'A' + 27;
    else x = a - '0' + 53;
    return x;
}

auto computeHash(string &s) {
    pair<int, int> hs;
    hs.first = hs.second = 0;
    for (auto &i: s) {
        int x = calcVal(i);
        hs.first = (((hs.first * p1) % mod) + x) % mod;
        hs.second = (((hs.second * p2) % mod) + x) % mod;
    }
    return hs;
}

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> pw1(n), pw2(n);
    pw1[0] = 1;
    pw2[0] = 1;
    for (int i = 1; i < n; i++) pw1[i] = (pw1[i - 1] * p1) % mod, pw2[i] = (pw2[i - 1] * p2) % mod;
    int q;
    cin >> q;
    map<int, set<pair<int, int>>> mp;
    while (q--) {
        string t;
        cin >> t;
        auto res = computeHash(t);
        int m = t.length();
        if (m > n) {
            cout << "N\n";
            continue;
        }
        pair<int, int> hs;
        if(!mp[m].size()) for (int i = 0; i < n; i++) {
            int x = calcVal(s[i]);
            if (i < m) {
                hs.first = (((hs.first * p1) % mod) + x) % mod;
                hs.second = (((hs.second * p2) % mod) + x) % mod;
                if (i == m - 1) mp[m].insert(hs);
                continue;
            }
            int y = calcVal(s[i - m]);
            hs.first = hs.first - (y * pw1[m - 1]) % mod;
            hs.second = hs.second - (y * pw2[m - 1]) % mod;
            if (hs.first < 0) hs.first += mod;
            if (hs.second < 0) hs.second += mod;
            hs.first = (((hs.first * p1) % mod) + x) % mod;
            hs.second = (((hs.second * p2) % mod) + x) % mod;
            mp[m].insert(hs);
        }
        if (mp[m].find(res) != mp[m].end()) cout << "Y\n";
        else cout << "N\n";
    }
}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}