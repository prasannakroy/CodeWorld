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
    int n;
    cin >> n;
    vc<int> fact, prime;
    int val = n;
    for (int i = 2; i * i <= val; i++) {
        if (val % i == 0) {
            while (val % i == 0) val /= i;
            prime.push_back(i);
        }
    }
    if (val > 2) prime.push_back(val);
    for (int i = 2; i * i <= n; i++) if (n % i == 0) {
        fact.push_back(i);
        if (n / i != i) fact.push_back(n / i);
    }
    fact.push_back(n);
    if (fact.size() == 3 and prime.size() == 2) {
        for (auto &i: fact) cout << i << " ";
        cout << "\n1\n";
        return;
    }
    map<int, int> vis;
    vc<int> res;
    int sz = prime.size();
    for (int i = 0; i < sz; i++) {
        res.push_back(prime[i]);
        vis[prime[i]] = 1;
        if (!vis[prime[i] * prime[(i + 1) % sz]]) {
            res.push_back(prime[i] * prime[(i + 1) % sz]);
            vis[prime[i] * prime[(i + 1) % sz]] = 1;
        }
        else res.push_back(n), vis[n] = 1;
    }
    for (int i = 0; i < res.size(); i += 2) {
        cout << res[i] << " ";
        for (auto &j: fact) if (!vis[j] and j % res[i] == 0) cout << j << " ", vis[j] = 1;
        cout << res[i + 1] << " ";
    }
    cout << "\n";
    cout << 0 << "\n";
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