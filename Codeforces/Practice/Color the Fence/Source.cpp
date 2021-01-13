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
    int n, val(INT_MAX), idx;
    cin >> n;
    vc<int> a(10);
    for (int i = 1; i < 10; i++) {
        cin >> a[i];
        if (a[i] <= val) val = a[i], idx = i;
    }
    int len = n / val;
    if (!len) return void(cout << "-1");
    vc<int> res(len, idx);
    int cost(0);
    for (int i = 0; i < len; i++) {
        int j = 9;
        for (j = 9; j > idx; j--) {
            int cst = (len - i - 1) * val + cost;
            if (cst + a[j] <= n) {
                res[i] = j;
                cost += a[j];
                break;
            }
        }
        if (j == idx) break;
    }
    for (auto &i: res) cout << i;
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