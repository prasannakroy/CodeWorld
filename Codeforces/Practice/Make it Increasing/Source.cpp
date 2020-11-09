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

void solve() {
    int n, k, x;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i], a[i] -= i;
    map<int, int> m;
    for (int i = 0; i < k; i++) cin >> x, m[x - 1] = 1;
    vector<int> res;
    
    function<int(int, int)> compute = [&](int lr, int rt) {
        if (res.size() == 0) return 0ll;
        vector<int> v;
        for (int i = 0; i < res.size(); i++) if (lr <= res[i] and res[i] <= rt) {
            if (v.empty()) {
                v.push_back(res[i]);
                continue;
            }
            auto it = upper_bound(v.begin(), v.end(), res[i]);
            if (it == v.end()) v.push_back(res[i]);
            else *it = res[i];
        }
        return (int)v.size();
    };
    
    int r(INT_MIN);
    bool flag(1);
    int sol(0);
    for (int i = 0; i < n; i++) {
        if (m[i] == 1) {
            if (a[i] < r) {
                flag = 0;
                break;
            }
            sol += compute(r, a[i]);
            r = a[i];
            res.clear();
        }
        else res.push_back(a[i]);
    }
    sol += compute(r, (int)INT_MAX);
    if (!flag) cout << -1 << "\n";
    else cout << n - sol - k << "\n";
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case #" << i << ": ",*/ solve(), i++);
    return 0;
}