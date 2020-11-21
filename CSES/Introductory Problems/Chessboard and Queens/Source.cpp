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
    vector<string> v(8);
    vector<vector<int>> vis(8, vector<int>(8, 0));
    for (auto &i: v) cin >> i;
    for (int i = 0; i < 8; i++) 
        for (int j = 0; j < 8; j++) 
            if (v[i][j] == '*') vis[i][j] = 2;
    int cnt(0); 
    
    function<bool(int, int)> isValid = [&](int r, int c) {
        for (int i = 0; i < c; i++) if (vis[r][i] == 1) return false; 
        for (int i = r, j = c; i >= 0 and j >= 0; i--, j--) if (vis[i][j] == 1) return false; 
        for (int i = r, j = c; j >= 0 and i < 8; i++, j--) if (vis[i][j] == 1) return false; 
        return true; 
    };
    
    function<void(int)> compute = [&](int c) {
        if (c >= 8) cnt++;
        for (int i = 0; i < 8; i++) { 
            if (vis[i][c] == 2) continue;
            if (isValid(i, c)) { 
                vis[i][c] = 1; 
                compute(c + 1); 
                vis[i][c] = 0; 
            } 
        }  
    };
    compute(0);
    cout << cnt << "\n";
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