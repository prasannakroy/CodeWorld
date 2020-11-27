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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n);
    for (auto &i: v) cin >> i;

    multiset<int> s;
    for (int i = 1; i < n; i++) v[i] += v[i - 1];
    int res = v[a - 1];
    s.insert(0);
    bool flag(1);
    for (int i = a; i < n; i++) {
        if (i >= b) if (flag) s.erase(s.find(0)), flag = 0;
        if (i - a >= 0) s.insert(v[i - a]);
        res = max(res, v[i] - *s.begin());
        if (i >= b) s.erase(s.find(v[i - b]));
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