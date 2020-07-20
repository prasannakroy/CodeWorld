/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define i_64 long long

void countn(int a[], int sz, int n, map<int, int> &mp) {
    int cnt(0), res(1), root = n;
    mp[n] = 1;
    while (root != 1) {
        root = a[root];
        cnt++;
        if (cnt == sz) mp[root] = 1, cnt = 0;
    }
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int dsu[n + 1];
    for (int i = 2; i <= n; i++) cin >> dsu[i];
    int cnta(0);
    int cntb(0);
    double res = 0;
    for (int i = 1; i <= n; i++) {
        std::map<int, int> m;
        countn(dsu, a, i, m);
        cnta = m.size();
        for (int j = 1; j <= n; j++) {
            int cnt(0);
            std::map<int, int> mp;
            countn(dsu, b, j, mp);
            for (auto &i: mp) {
                if (m[i.first]) continue;
                cnt++;
            }
            res = res + (double)(cnta + cnt);
        }
    }
    cout << fixed << setprecision(6) << res / (n * n) << "\n";
}

signed main() {
    __AcHiLlEs
  
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; cout << "Case #" << i << ": ", solve(), i++);
    return 0;
}
