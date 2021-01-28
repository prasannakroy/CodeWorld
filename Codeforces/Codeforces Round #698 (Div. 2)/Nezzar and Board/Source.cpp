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

int gcd(int a, int b) {
    while (b) tie(a, b) = make_tuple(b, a % b);
    return a;
}

void solve() {
    int n, k, flag(0), mn(LLONG_MAX);
    cin >> n >> k;
    vc<int> a(n), dif;
    for (auto &i: a) cin >> i, flag |= (i == k), mn = min(mn, i);
    if (flag) return void(cout << "YES\n");
    sort(span(a));
    int d(0);
    for (int i = 1; i < n; i++) dif.push_back(a[i] - a[i - 1]);
    for (int i = 0; i < n - 1; i++) d = gcd(dif[i], d);
    int dd = abs(mn - k);
    if (dd % d) cout << "NO\n";
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