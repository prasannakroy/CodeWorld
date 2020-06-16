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
    string s1;
    cin >> s1;
    sort(s1.begin(), s1.end());
    int m[26];
    memset(m, 0, sizeof m);
    string s("");
    for (char &i: s1) {
        if (!m[i - 'a']) {
            s += i;
        }
        m[i - 'a']++;
    } 
    int n, x;
    cin >> n;
    priority_queue<pair<int, int>, std::vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push({x, i});
    }
    string res;
    for (int i = 0; i < n; i++) res += '0';
    map<int, int> mp;
    while (!q.empty()) {
        pair<int, int> p = q.top();
        q.pop();
        int cnt(0);
        vector<int> z;
        z.push_back(p.second);
        vector<pair<int, int>> v;
        while (!q.empty()) {
            v.push_back(q.top());
            q.pop();
        }
        for (auto &i: v) {
            if (i.first == 0) {
                z.push_back(i.second);
                continue;
            }
        }
        for (auto &i: v) {
            if (i.first == 0) continue;
            for (int &j : z) 
                i.first -= abs(i.second - j);
            q.push(i);
        }
        char add;
        for (int i = 25; i >= 0; i--) {
            if (m[i] >= z.size()) {
                m[i] = 0;
                add = 'a' + i;
                break;
            }
            else m[i] = 0;
        }
        for (int &i: z) res[i] = add;
    }
    cout << res << "\n";
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
    