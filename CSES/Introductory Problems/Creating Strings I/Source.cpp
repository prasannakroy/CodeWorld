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
#define int long long
#define span(a) a.begin(), a.end()
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)

void solve() {
    string s;
    cin >> s;
    map<char, int> m;
    for (auto &i : s) m[i]++;
    set<string> res;

    function<void(string)> generate = [&](string ss) {
        bool flag(1);
        for (auto &[a, b]: m) {
            if (!b) continue;
            flag = 0;
            b--;
            generate(ss + a);
            b++;
        }
        if (flag) res.insert(ss);
    };
    generate("");
    cout << res.size() << "\n";
    for (auto &i: res) cout << i << "\n";
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}