/*****************************
*  Author :: Πρασαννα Κ. Ροι  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<pair<int, int>, int> mp;
    int x = 0, y = 0, res(INT_MAX), l(-1), r(-1);
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'L') x--;
        else if (s[i - 1] == 'R') x++;
        else if (s[i - 1] == 'U') y++;
        else y--;
        if (!mp[{x, y}] and !x and !y) {
            if (i < res) {
                res = i;
                l = 1, r = i;
            }
        }
        else if (mp[{x, y}]) {
            if (i - mp[{x, y}] < res) {
                res = i - mp[{x, y}];
                l = mp[{x, y}] + 1;
                r = i;
            }
        }
        mp[{x, y}] = i;
    }
    if (l == -1) cout << -1 << "\n";
    else cout << l << " " << r << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}