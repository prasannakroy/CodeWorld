/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define i_64 unsigned long long

int res[10000];
char g[10000];
vector<int> gph[10000];

void dfs(int u) {
    res[u] = 1;
    for (int &v: gph[u]) {
        if (g[v] == '#' or res[v] == 1) continue;
        dfs(v);
    }
}

void solve() {
    memset(res, 0, sizeof res);
    int n, m, cnt(0);
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) gph[i].clear();
    std::vector<string> v(n);
    for (string &i: v) cin >> i;
    bool flag = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { 
            if (v[i][j] == 'G') {
                flag = 0;
                break;
            }
        }
    }
    if (flag) {
        cout << "Yes\n";
        return;
    }
    flag = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'B') {
                if ((i + 1 == n - 1 and j == m - 1) or (j + 1 == m - 1 and i == n - 1)) {
                    flag = 0;
                    break;
                }
                if (i > 0 and v[i - 1][j] == 'G') {
                    flag = 0;
                    break;
                }
                if (i < n - 1 and v[i + 1][j] == 'G') {
                    flag = 0;
                    break;
                }
                if (j > 0 and v[i][j - 1] == 'G') {
                    flag = 0;
                    break;
                }
                if (j < m - 1 and v[i][j + 1] == 'G') {
                    flag = 0;
                    break;
                }
                if (i > 0 and v[i - 1][j] == '.') 
                    v[i - 1][j] = '#';
                if (i < n - 1 and v[i + 1][j] == '.') 
                    v[i + 1][j] = '#';
                if (j > 0 and v[i][j - 1] == '.') 
                    v[i][j - 1] = '#';
                if (j < m - 1 and v[i][j + 1] == '.') 
                    v[i][j + 1] = '#';
            }
        }
    }
    if (!flag) {
        cout << "No\n";
        return;
    }
    cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            g[cnt] = v[i][j];
            if (i > 0) gph[cnt].push_back(cnt - m);
            if (i < n - 1) gph[cnt].push_back(cnt + m);
            if (j > 0) gph[cnt].push_back(cnt - 1);
            if (j < m - 1) gph[cnt].push_back(cnt + 1);
            cnt++;
        }
    }
    dfs((m * n) - 1);
    for (int i = 0; i <cnt; i++) {
        if (g[i] == 'G' and res[i] != 1) {
            flag = 0;
            break;
        }
    }
    if (flag) 
        cout << "Yes\n";
    else 
        cout << "No\n";
}

signed main() {
    __AcHiLlEs

    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}

