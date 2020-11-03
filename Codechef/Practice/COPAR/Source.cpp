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

map<int, int> m;
vector<vector<int>> lst;

void factorize(int idx, int n) {
    if (!(n & 1)) {
        m[2]++;
        lst[idx].push_back(2);
        while (!(n & 1)) n >>= 1ll;
    }
    if (!(n % 3)) {
        m[3]++;
        lst[idx].push_back(3);
        while (!(n % 3)) n /= 3;
    }
    for (int i = 6; i * i <= n; i += 6) {
        if (!(n % (i - 1))) {
            m[i - 1]++;
            lst[idx].push_back(i - 1);
            while (!(n % (i - 1))) n /= (i - 1);
        }
        if (!(n % (i + 1))) {
            m[i + 1]++;
            lst[idx].push_back(i + 1);
            while (!(n % (i + 1))) n /= (i + 1);
        }
    }
    if (n > 1) m[n]++, lst[idx].push_back(n);
}

void solve() {
    int n;
    cin >> n;
    m.clear();
    lst.assign(n, vector<int>());
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    for (int i = 0; i < n; i++) factorize(i, a[i]);
    map<int, bool> mp;
    int cnt1(0), cnt2(0), i;
    for (i = 0; i < n; i++) {
        for (auto &j: lst[i]) {
            if (!mp[j]) cnt1++, mp[j] = 1;
            m[j]--;
            if (!m[j]) cnt2++;
        }
        if (cnt1 == cnt2) break;
    }
    cout << i + 1 << "\n";
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