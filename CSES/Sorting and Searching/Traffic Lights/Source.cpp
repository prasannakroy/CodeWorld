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
    int len, n, x;
    cin >> len >> n;
    multiset<int> m;
    set<int> s;
    s.insert(0);
    s.insert(len);
    while(n--) {
        cin >> x;
        auto l = s.lower_bound(x), r = --s.upper_bound(x);
        if(*l > x) --l;
        if(*r < x) ++r;
        auto f = m.find(*r - *l);
        if(f != m.end()) m.erase(f);
        m.insert(x - *l);
        m.insert(*r - x);
        s.insert(x);
        cout << *m.rbegin() << " ";
    }
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