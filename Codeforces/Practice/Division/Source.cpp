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

int power(int a, int b) {
    int res(1);
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve() {
    int p, q;
    cin >> p >> q;
    if (p % q != 0) {
        cout << p << "\n";
        return;
    }
    vector<pair<int, int>> fac;
    map<int, int> m;
    int cnt(0);
    int r = p;
    while (!(r % q)) r /= q, cnt++;
    int d = q;
    int c;
    if (!(d & 1)) {
        c = 0;
        while (!(d & 1)) d /= 2, c++;
        fac.push_back({2, c * cnt});
        m[2] = c;
    }
    if (!(d % 3)) {
        c = 0;
        while (!(d % 3)) d /= 3, c++;
        fac.push_back({3, c * cnt});
        m[3] = c;
    }
    
    for (int i = 5; i * i <= d; i += 6) {
        if (!(d % i)) {
            c = 0;
            while (!(d % i)) d /= i, c++;
            fac.push_back({i, c * cnt});
            m[i] = c;
        }
        if (!(d % (i + 2))) {
            c = 0;
            while (!(d % (i + 2))) d /= (i + 2), c++;
            fac.push_back({i + 2, c * cnt});
            m[i + 2] = c;
        }
    }
    if (d > 2) fac.push_back({d, cnt}), m[d] = 1;
    int val(1);
    for (auto &i: fac) {
        if (!(r % i.first)) {
            c = 0;
            while (!(r % i.first)) r /= i.first, c++;
            i.second += c;
        }
        val *= power(i.first, i.second);
    }
    int res(r);
    for (auto &i: fac) {
        int cnt = i.second - m[i.first] + 1;
        res = max(res, r * (val / power(i.first, cnt)));
    }
    cout << res << "\n";
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case #" << i << ": ",*/ solve(), i++);
    return 0;
}