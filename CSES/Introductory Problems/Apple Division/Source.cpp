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
    int n, sm(0);
    cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i, sm += i;
    int mn(sm);

    function<void(int, int)> compute = [&](int idx, int smm) {
        if (idx == n) return void(mn = min(mn, abs(smm - sm + smm)));
        compute(idx + 1, smm);
        compute(idx + 1, smm + a[idx]);
    };

    compute(0, 0);
    cout << mn << "\n";
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