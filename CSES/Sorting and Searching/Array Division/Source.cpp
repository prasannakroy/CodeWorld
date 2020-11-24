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

void solve() {
    int n, k, sm(0);
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i: a) cin >> i, sm += i;
    int l = 0, r = sm, res = -1;
    
    function<bool(int)> check = [&](int t) {
        int sm(0), cnt(1);
        for (int i = 0; i < n; i++) {
            if (a[i] > t) return false;
            if (sm + a[i] <= t) sm += a[i];
            else cnt++, sm = a[i];
        }
        return (cnt <= k);
    };

    while (l <= r) {
        int m = (l + r) >> 1ll;
        if (check(m)) res = m, r = m - 1;
        else l = m + 1;
    }
    cout << res << "\n";
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