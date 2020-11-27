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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    multiset<int> l, r;
    int sz(0);
    for (int i = 0; i < n; i++) {
        if (sz == k) {
            cout << *l.rbegin() << " ";
            int val = a[i - k];
            if (val <= *l.rbegin()) l.erase(l.find(val));
            else r.erase(r.find(val));
        }
        while (l.size() < r.size()) l.insert(*r.begin()), r.erase(r.begin());
        if (l.empty() or a[i] < *l.rbegin()) l.insert(a[i]);
        else r.insert(a[i]);
        if (l.size() > r.size() + 1) r.insert(*l.rbegin()), l.erase(--l.end());
        while (l.size() < r.size()) l.insert(*r.begin()), r.erase(r.begin());
        if (sz < k) sz++;
    } 
    cout << *l.rbegin() << "\n";
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