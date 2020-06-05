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

const i_64 mod = (i_64)1e9 + 7ll;
i_64 n, p;
std::vector<i_64> a;

i_64 needCount(i_64 cnt, i_64 b) {
    i_64 res(1);
    while (b--) {
        res *= p;
        if (res > n) return -1;
    }
    res *= cnt;
    return res > n ? -1 : res;
}

i_64 power(i_64 a, i_64 b) {
    i_64 res(1);
    while (b) {
        if (b & 1) (res *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    a.clear();
    i_64 x;
    cin >> n >> p;
    std::map<i_64, i_64> m;
    for (i_64 i = 0; i < n; i++) {
        cin >> x;
        if (m[x] == 0) a.push_back(x);
        m[x]++;
    }
    if (p == 1) {
        if(n & 1) 
            cout << 1 << "\n";
        else 
            cout << 0 << "\n";
        return;
    }
    sort(a.begin(), a.end(), greater<i_64>());
    i_64 n2 = a.size();
    i_64 i = 0, res(0);
    while (i < n2) {
        if (!(m[a[i]] & 1)) {
            i++;
            continue;
        }
        i_64 r_cnt = 1, val = a[i];
        bool flag = 0;
        for (i_64 j = i + 1; j < n2; j++) {
            i_64 n_cnt = needCount(r_cnt, val - a[j]);
            if (n_cnt == -1) break;
            if (n_cnt <= m[a[j]]) {
                m[a[j]] -= n_cnt;
                i = j;
                flag = 1;
                break;
            }
            r_cnt = n_cnt - m[a[j]];
            val = a[j];
        }
        if (!flag) {
            res = power(p, a[i]);
            for (i_64 j = i + 1; j < n2; j++) {
                i_64 aux = (m[a[j]] * power(p, a[j])) % mod;
                res -= aux;
                if (res < 0) res += mod;
            }
            break;
        }
    }
    cout << res << "\n";
}

signed main() {
    __AcHiLlEs

    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}

