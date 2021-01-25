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

vc<int> dsu, sz, sol;
int res(0);

const int mod = 1e9 + 7;

int root(int a) {
    return a == dsu[a] ? dsu[a] : dsu[a] = root(dsu[a]);
}

void join(int a, int b, char t) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    dsu[b] = a;
    if (t == 'r') {
        res = (res + ((sol[a] * sz[b]) % mod) + ((sol[b] * sz[a]) % mod)) % mod;
        (sol[a] += (sz[a] * sz[b]) % mod) %= mod;
    }
    sz[a] += sz[b];
    (sol[a] += sol[b]) %= mod;
}

void solve() {
    int n, x, y;
    cin >> n;
    dsu.resize(n + 1);
    sz.assign(n + 1, 1);
    sol.assign(n + 1, 0);
    iota(span(dsu), 0);
    char c;
    vc<array<int, 2>> v;
    for (int i = 1; i < n; i++) {
        cin >> x >> y >> c;
        if (c == 'b') join(x, y, c);
        else v.push_back({x, y});
    }
    for (auto &i : v) 
        join(i[0], i[1], 'r');
    cout << res << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    // #ifndef ONLINE_JUDGE 
    //     __AnAkLuSmOs    
    // #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}