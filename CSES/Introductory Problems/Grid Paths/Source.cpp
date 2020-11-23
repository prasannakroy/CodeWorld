/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) a.begin(), a.end()
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)

string s;
int cnt, c;
bool vis[7][7];

bool isValid(int x, int y) {
    return (x >= 0 and x <= 6 and y >= 0 and y <= 6);
}

inline void backTrack(int i, int j, int idx) {
    c++;
    if (i == 6 and j == 0 and idx != 48) return;
    if (idx == 48) {
        if (i == 6 and j == 0)
            cnt++;
        return;
    }
    vis[i][j] = 1;
    if (s[idx] == 'L') {
        if (!((!isValid(i - 1, j) or vis[i - 1][j]) and (!isValid(i + 1, j) or vis[i + 1][j]) and (isValid(i, j - 1) and !vis[i][j - 1]) and (isValid(i, j + 1) and !vis[i][j + 1]))) if (isValid(i, j - 1) and !vis[i][j - 1]) backTrack(i, j - 1, idx + 1);
    }
    else if (s[idx] == 'R') {
        if (!((!isValid(i - 1, j) or vis[i - 1][j]) and (!isValid(i + 1, j) or vis[i + 1][j]) and (isValid(i, j - 1) and !vis[i][j - 1]) and (isValid(i, j + 1) and !vis[i][j + 1]))) if (isValid(i, j + 1) and !vis[i][j + 1]) backTrack(i, j + 1, idx + 1);
    }
    else if (s[idx] == 'U') {
        if (!((isValid(i - 1, j) and !vis[i - 1][j]) and (isValid(i + 1, j) and !vis[i + 1][j]) and (!isValid(i, j - 1) or vis[i][j - 1]) and (!isValid(i, j + 1) or vis[i][j + 1]))) if (isValid(i - 1, j) and !vis[i - 1][j]) backTrack(i - 1, j, idx + 1);
    }
    else if (s[idx] == 'D') {
        if (!((isValid(i - 1, j) and !vis[i - 1][j]) and (isValid(i + 1, j) and !vis[i + 1][j]) and (!isValid(i, j - 1) or vis[i][j - 1]) and (!isValid(i, j + 1) or vis[i][j + 1]))) if (isValid(i + 1, j) and !vis[i + 1][j]) backTrack(i + 1, j, idx + 1);
    }
    else {
        if (!((!isValid(i - 1, j) or vis[i - 1][j]) and (!isValid(i + 1, j) or vis[i + 1][j]) and (isValid(i, j - 1) and !vis[i][j - 1]) and (isValid(i, j + 1) and !vis[i][j + 1]))) {
            if (isValid(i, j - 1) and !vis[i][j - 1]) backTrack(i, j - 1, idx + 1);
            if (isValid(i, j + 1) and !vis[i][j + 1]) backTrack(i, j + 1, idx + 1);
        }
        if (!((isValid(i - 1, j) and !vis[i - 1][j]) and (isValid(i + 1, j) and !vis[i + 1][j]) and (!isValid(i, j - 1) or vis[i][j - 1]) and (!isValid(i, j + 1) or vis[i][j + 1]))) {
            if (isValid(i - 1, j) and !vis[i - 1][j]) backTrack(i - 1, j, idx + 1);
            if (isValid(i + 1, j) and !vis[i + 1][j]) backTrack(i + 1, j, idx + 1);
        }
    }
    vis[i][j] = 0;
}

void solve() {
    cin >> s;
    backTrack(0, 0, 0);
    cout << cnt << "\n";
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