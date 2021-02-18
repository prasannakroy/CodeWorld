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

const int mx = 1e6;
vc<bool> sieve(mx + 1);
vc<int> prime(mx + 1);

void generate() {
    sieve[0] = 1;
    sieve[1] = 1;
    for (int i = 4; i <= mx; i += 2) sieve[i] = 1;
    for (int i = 9; i <= mx; i += 6) sieve[i] = 1;
    for (int i = 5; i * i <= mx; i += 4) {
        if (!sieve[i]) 
            for (int j = i * i; j <= mx; j += (i * 2)) sieve[j] = 1;
        i += 2;
        if (!sieve[i]) 
            for (int j = i * i; j <= mx; j += (i * 2)) sieve[j] = 1;
    }
    for (int i = 1; i <= mx; i++) {
        prime[i] = prime[i - 1];
        if (!sieve[i]) prime[i]++;
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (prime[n] <= k) cout << "Chef\n";
    else cout << "Divyam\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    generate();
    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}