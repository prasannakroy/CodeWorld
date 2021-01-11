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
    int n, m, sa(0), sb(0), cnt(0);
    cin >> n >> m;
    vc<int> a(n), b(m);
    for (auto &i: a) cin >> i, sa += i;
    for (auto &i: b) cin >> i, sb += i;
    if (sa > sb) return void(cout << cnt << "\n");
    sort(span(a));
    sort(span(b), greater<int>());
    for (int i = 0; i < min(n, m); i++) {
        sa += b[i] - a[i];
        sb -= b[i] - a[i];
        cnt++;
        if (sa > sb) return void(cout << cnt << "\n");
    }
    cout << -1 << "\n";
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