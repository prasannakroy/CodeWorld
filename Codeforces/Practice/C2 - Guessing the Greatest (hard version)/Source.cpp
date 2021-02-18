/*****************************
*  Author :: Πρασαννα Κ. Ροι  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

int query(int l, int r) {
    int x;
    cout << "? " << l << " " << r << endl; 
    cin >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;
    int l = 1, r = n;
    int idx = query(1, n);
    int idx2 = -1;
    if (idx > 1) idx2 = query(1, idx);
    if (~idx2 and idx2 == idx) {
        int l = 1, r = idx;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (query(m, idx) == idx) l = m;
            else r = m;
        }
        cout << "! " << l << endl;
    }
    else {
        int l = idx, r = n;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (query(idx, m) == idx) r = m;
            else l = m;
        }
        cout << "! " << r << endl;
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