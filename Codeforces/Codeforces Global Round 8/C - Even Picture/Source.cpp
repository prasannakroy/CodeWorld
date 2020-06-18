#include<bits/stdc++.h>
using namespace std;

#define i_64 long long

void solve() {
    int n, cnt(0);
    cin >> n;
    int res[n + 2][n + 2];
    memset(res, 0, sizeof res);
    for (int i = 0; i < n + 2; i++) {
        res[i][i] = 1;
        cnt++;
        if (i > 0 and !res[i - 1][i] and !res[i][i - 1]) res[i - 1][i] = 1, res[i][i - 1] = 1, cnt += 2;
        if (i < n + 1 and !res[i + 1][i] and !res[i][i + 1]) res[i + 1][i] = 1, res[i][i + 1] = 1, cnt += 2;
    }
    cout << cnt << "\n";
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            if (res[i][j]) cout << i << " " << j << "\n";
        }
    }
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    i_64 t(1);
    
    // cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}