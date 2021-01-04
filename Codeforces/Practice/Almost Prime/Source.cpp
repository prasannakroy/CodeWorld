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
	int n;
	cin >> n;
	vector<int> vis(n + 1, 0);
	vis[0] = vis[1] = 1;
	vector<int> prime;
	vector<int> p;
	for (int i = 2; i * i <= n; i++) if (!vis[i]) 
		for (int j = i * i; j <= n; j += i) vis[j] = 1;
	for (int i = 2; i <= n; i++) if (!vis[i]) prime.push_back(i);
	for (int i = 0; i < prime.size(); i++) {
		int val = prime[i];
		p.push_back(val);
		while (val * prime[i] <= n) p.push_back(val = val * prime[i]);
	}
	set<int> res;
	for(int i = 0; i < p.size(); i++) 
		for (int j = i + 1; j < p.size(); j++) if (p[i] % p[j] != 0 and p[j] % p[i] != 0 and p[i] * p[j] <= n) 
			res.insert(p[i] * p[j]);
	cout << res.size() << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}