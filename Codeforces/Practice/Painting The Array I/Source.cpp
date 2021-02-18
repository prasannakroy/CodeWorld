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
    int n;
    cin >> n;
    vc<int> a(n);
    for (auto &i: a) cin >> i;
    int i(0), res(0), preva(0), prevb(0);
    while (i < n) {
        int j(i), cnt(0);
        while (j < n and a[j] == a[i]) j++, cnt++;
        cnt = min(cnt, 2ll);
        if (cnt == 1) {
            if (j == n) return void(cout << res + 1 << "\n");
            int val = a[j];
            if (val == preva) preva = a[i];
            else {
                if (prevb != a[i]) prevb = a[i];
                else preva = a[i];
            }
            res++;
        }
        else {
            if (preva != a[i]) res++, preva = a[i];
            if (prevb != a[i]) res++, prevb = a[i];
        }
        i = j;
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