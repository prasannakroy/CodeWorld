/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) a.begin(), a.end()
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (auto &i: a) cin >> i.first >> i.second;
    sort(span(a), [&](pair<int, int> x, pair<int, int> y) {
        return x.second == y.second ? x.first < y.first : x.second < y.second;
    });
    
    multiset<int> s;
    s.insert(a[0].second);
    int res(1);
    for (int i = 1; i < n; i++) {
        if (a[i].first < *s.begin()) {
            if (s.size() == k) continue;
            res++;
            s.insert(a[i].second);
            continue;
        }
        auto it = --s.upper_bound(a[i].first);
        if (*it <= a[i].first) res++, s.erase(it), s.insert(a[i].second);
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