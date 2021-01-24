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

int mx = 30000;
vector<int> sieve(mx + 1, 0), prime;

void Sieve() {
    for (int i = 4; i <= mx; i += 2) sieve[i] = 1;
    for (int i = 9; i <= mx; i += 6) sieve[i] = 1;
    for (int i = 5; i * i <= mx; i += 6) {
        if (!sieve[i]) 
            for (int j = i * i; j <= mx; j += (2 * i)) sieve[j] = 1;
        if (!sieve[i + 2]) 
            for (int j = (i + 2) * (i + 2); j <= mx; j += (2 * (i + 2))) sieve[j] = 1;
    }
    for (int i = 2; i <= mx; i++) if (!sieve[i]) prime.push_back(i);
}

void solve() {
    int d;
    cin >> d;
    int idx = lower_bound(span(prime), d + 1) - prime.begin();
    int p1 = prime[idx];
    idx = lower_bound(span(prime), p1 + d) - prime.begin();
    int p2 = prime[idx];
    cout << p1 * p2 << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs
    Sieve();
    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}