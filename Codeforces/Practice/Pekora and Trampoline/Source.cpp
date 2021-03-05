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
    int n, res(0), cnt(0);
    cin >> n;
    vc<int> a(n);
    vc<int> dsu(n + 1);
    iota(span(dsu), 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0 and n != 1) 
            if (a[0] >= n) res += a[0] - n + 1, a[0] = n - 1; 
        if (a[i] == 1) cnt++, dsu[i] = i + 1;
    }
    if (n == 1) {
        if (a[0] == 1) return void(cout << 0 << "\n");
        return void(cout << a[0] - 1 << "\n");
    }

    

    function<int(int)> root = [&](int a) {
        return dsu[a] == a? dsu[a] : dsu[a] = root(dsu[a]);
    };

    int i(0);
    while (cnt < n) {
        if (i == 0) {
            i = root(i);
            if (a[i] >= n) 
                res += a[i] - n + 1, a[i] = n - 1;
            if (a[i] == 1) cnt++;
            if (cnt == n) break;
            res++;
        }
        int val = min(i + a[i], n);
        if (a[i] > 1) {
            a[i]--;
            if (a[i] == 1) cnt++;
        }
        if (a[i] == 1 and dsu[i] == i) dsu[i] = root(i + 1);
        i = root(val);
        if (i == n) i = 0;
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
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}