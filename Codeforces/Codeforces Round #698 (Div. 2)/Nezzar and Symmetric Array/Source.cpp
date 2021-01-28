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
    int n, x;
    cin >> n;
    int sz = n * 2;
    vector<int> a(sz);
    map<int, int> m;
    for (auto &i: a) 
        cin >> i, m[i]++;
    for (auto &[x, y] : m) if (y > 2 or y == 1 or x == 0) return void(cout << "NO\n");
    sort(span(a), greater<int>());
    set<int> s;
    int val = 0, cnt(0);
    for (int i = 0; i < sz; i += 2) {
        if (val >= a[i]) return void(cout << "NO\n");
        if (((a[i] - val) % (n - cnt)) or (a[i] & 1)) return void(cout << "NO\n");
        x = ((a[i] - val) / (n - cnt)); 
        if (x & 1) return void(cout << "NO\n");
        s.insert(x / 2);
        val += x;
        cnt++;
    }
    if (s.size() == n) cout << "YES\n";
    else cout << "NO\n";
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