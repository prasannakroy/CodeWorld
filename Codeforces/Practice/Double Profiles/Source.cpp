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
#define int unsigned long long
#define span(a) a.begin(), a.end()
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)

const int p(31);
int pwr[1000001], mp[1000001][2], hashx[1000001];

void solve() {
    int n, m, x, y;
    cin >> n >> m;
    pwr[0] = 1;
    for (int i = 1; i < n; i++) pwr[i] = pwr[i - 1] * p;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--, y--;
        mp[i][0] = x;
        mp[i][1] = y;
        hashx[x] += pwr[y];
        hashx[y] += pwr[x];
    }
    int res(0);
    for (int i = 0; i < m; i++) {
        x = mp[i][0];
        y = mp[i][1];
        int a = hashx[x] - pwr[y];
        int b = hashx[y] - pwr[x];
        res += (a == b);
    }
    sort(hashx, hashx + n);
    int cnt(1);
    for (int i = 1; i < n; i++) {
        if (hashx[i] == hashx[i - 1]) {
            cnt++;
            continue;
        }
        res += ((cnt * (cnt - 1)) / 2);
        cnt = 1;
    }
    res += ((cnt * (cnt - 1)) / 2);
    cout << res << "\n";
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