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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string res("");
    for (int i = 0; i < 2 * (k - 1); i++) i & 1 ? res += ')' : res += '(';
    for (int i = 2 * (k - 1); i < (2 * (k - 1)) + ((n - (2 * (k - 1))) / 2); i++) res += '(';
    for (int i = (2 * (k - 1)) + ((n - (2 * (k - 1))) / 2); i < n; i++) res += ')';
    std::vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        if (s[i] != res[i]) {
            int j = i + 1;
            while (s[j] == s[i] and j < n) j++;
            reverse(s.begin() + i, s.begin() + j + 1);
            v.push_back({i + 1, j + 1});
        }
    }
    cout << v.size() << "\n";
    for (auto &i : v) cout << i.first << " " << i.second << "\n";
}

signed main() {
    // #ifndef ONLINE_JUDGE 
    //     __AnAkLuSmOs    
    // #endif

    __AcHiLlEs

    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
    