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
    int n, m;
    cin >> n >> m;
    vc<array<int, 2>> a(m);
    for (auto &i: a) cin >> i[0] >> i[1];
    sort(span(a), [&](array<int, 2> x, array<int, 2> y) {
        return x[1] == y[1] ? x[0] < y[0] : x[1] < y[1];
    });
    int need = 0;
    int i = 0;
    while (i < m) {
        if (need) {
            if (a[i][0] == a[i - 1][0]) {
                if (!((a[i][1] - a[i - 1][1]) & 1)) return void(cout << "NO\n");
                else if (i + 1 < m and a[i + 1][1] == a[i][1]) return void(cout << "NO\n");
                else need ^= 1;
            }
            else {
                if ((a[i][1] - a[i - 1][1]) & 1) return void(cout << "NO\n");
                else if (i + 1 < m and a[i + 1][1] == a[i][1]) return void(cout << "NO\n");
                else need ^= 1;
            }
        }
        else need ^= 1;
        i++;
    }
    if (need) cout << "NO\n";
    else cout << "YES\n";
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