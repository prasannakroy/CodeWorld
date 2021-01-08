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
#define span(a) a.begin(), a.end()

template<typename t>
using vc = vector<t>;

void solve() {
    int n;
    cin >> n;
    int len = (1 << n);
    vc<int> res;
    int i = 0, sz = 1;
    res.push_back(0);
    while (sz < len) {
        for (int i = sz - 1; i >= 0; i--) res.push_back(res[i] + sz);
        sz <<= 1;
    }
    vector<bool> st(n, 0);
    for (int i = 0; i < len; i++) {
        int cnt = 0;
        while ((1 << cnt) <= res[i]) {
            if ((1 << cnt) & res[i]) st[cnt] = 1;
            else st[cnt] = 0;
            cnt++;
        }
        for (int i = n - 1; i >= 0; i--) cout << st[i];
        cout << "\n";
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