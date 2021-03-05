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

void solve() {
    int n, u, r, d, l;
    cin >> n >> u >> r >> d >> l;
    for (int i = 0; i < 16; i++) {
        int uu(0), rr(0), ll(0), dd(0);
        if (i & 1) uu++, ll++;
        if (i & 2) uu++, rr++;
        if (i & 4) ll++, dd++;
        if (i & 8) rr++, dd++;
        bool flag = 1;
        if (uu > u or uu + n - 2 < u) flag = 0;
        else if (ll > l or ll + n - 2 < l) flag = 0;
        else if (dd > d or dd + n - 2 < d) flag = 0;
        else if (rr > r or rr + n - 2 < r) flag = 0;
        if (flag) return void(cout << "YES\n");
    }
    cout << "NO\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}