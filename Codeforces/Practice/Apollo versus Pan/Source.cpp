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
#define int unsigned long long
#define span(a) a.begin(), a.end()

template<typename t>
using vc = vector<t>;

const int mod = (int)1e9 + 7;

void solve() {
	int n, mx(0);
	cin >> n;
	vc<int> a(n), cnt(64, 0);
	for (auto &i: a) {
		cin >> i;
		mx = max(i, mx);
		int c(0);
		while ((1ll << c) <= i) {
			if ((1ll << c) & i) cnt[c]++;
			c++;
		}
	}
	int sum(0);
	for (auto &j: a) {
		int c = 0;
		int s1(0), s2(0);
		while ((1ll << c) <= j) {
			if ((1ll << c) & j) 
				s1 = (s1 + ((((1ll << c) % mod) * cnt[c]) % mod)) % mod;
			c++;
		}
		c = 0;
		while ((1ll << c) <= mx) {
			if ((1ll << c) & j) 
				s2 = (s2 + ((((1ll << c) % mod) * n) % mod)) % mod;
			else s2 = (s2 + ((((1ll << c) % mod) * cnt[c]) % mod)) % mod;
			c++;
		}
		sum = (sum + ((s1 * s2) % mod)) % mod;
	}
	cout << sum << "\n";
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