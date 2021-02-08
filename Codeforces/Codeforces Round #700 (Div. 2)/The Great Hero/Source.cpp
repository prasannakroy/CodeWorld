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
    int A, B, n;
    cin >> A >> B >> n;
    vc<array<int, 2>> a(n);
    for (auto &i: a) cin >> i[0];
    for (auto &i: a) cin >> i[1];
    for (int i = 0; i < n; i++) {
        if (B <= 0) return void(cout << "NO\n");
        int cnt = 0;
        if (a[i][1] % A == 0) {
            cnt = (a[i][1] - 1) / A;
            a[i][1] = A;
        }
        else {
            cnt = a[i][1] / A;
            a[i][1] = a[i][1] % A;
        }
        B -= (cnt * a[i][0]);
        if (B < 0 and abs(B) >= a[i][0]) return void(cout << "NO\n");
    }
    sort(span(a), [&](array<int, 2> x, array<int, 2> y) {
        return x[0] < y[0];
    });
    for (int i = 0; i < n; i++) if (a[i][1]){
        if (B <= 0) return void(cout << "NO\n");
        B -= a[i][0];
    }
    cout << "YES\n";
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