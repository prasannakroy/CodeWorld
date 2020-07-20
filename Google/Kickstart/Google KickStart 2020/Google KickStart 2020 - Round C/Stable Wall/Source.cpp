/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define i_64 long long

void solve() {
    int r, c, cnt(0);
    cin >> r >> c;
    string s[r];
    for (string &i: s) cin >> i;
    std::map<char, int> m, x;
    std::map<char, std::vector<char>> mp;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (x[s[i][j]] == 0) {
                cnt++;
                x[s[i][j]] = 1;
                m[s[i][j]] = 0;
            }
            if (i == r - 1 and m.find(s[i][j]) == m.end()) {
                m[s[i][j]] += 0;
            }
            else if (i != r - 1 and s[i + 1][j] != s[i][j]){
                m[s[i][j]] = m[s[i][j]] + (s[i + 1][j] - 'A' + 1);
                mp[s[i + 1][j]].push_back(s[i][j]);
            }
            else {
                m[s[i][j]] += 0;
            }
        }
    }
    string res = "";
    while (cnt > 0) {
        bool flag = 0;
        for (auto &i: m) {
            if (i.second == 0) {
                flag = 1;
                res += i.first;
                i.second -= 1;
                for (auto &it: mp[i.first]) {
                    m[it] = m[it] - (i.first - 'A' + 1);
                }
                cnt--;
            }
        }
        if (!flag and cnt > 0) {
            res = "-1";
            break;
        }
    }
    cout << res << "\n";
}

int main() {
    // auto start=chrono::steady_clock::now();
    // #ifndef ONLINE_JUDGE 
    //     __AnAkLuSmOs
    // #endif

    __AcHiLlEs
    
    i_64 t(1);
    cin >> t;
    for (int i = 1; i <= t; cout << "Case #" << i << ": ", solve(), i++);
    // auto end = chrono::steady_clock::now();
    // double elapsed = double (chrono::duration_cast < chrono::nanoseconds> (end-start).count());
    // cout << endl << "Terminated\n"<< elapsed/1e9;
    return 0;
}

