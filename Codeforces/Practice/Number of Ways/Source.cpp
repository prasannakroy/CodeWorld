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
    int n, res(0), sum(0), t(0);
    cin >> n;
    vc<int> a(n), c1(n, 0);
    for (auto &i: a) cin >> i, sum += i;
    if (sum % 3) return void(cout << "0\n");
    for (int i = 0; i < n - 2; i++) {
        t += a[i];
        if (i > 0) c1[i] = c1[i - 1];
        if (t == sum / 3) c1[i]++;
    }
    t = 0;
    for (int i = n - 1; i > 1; i--) {
        t += a[i];
        if (t == sum / 3) 
            res += c1[i - 2];
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