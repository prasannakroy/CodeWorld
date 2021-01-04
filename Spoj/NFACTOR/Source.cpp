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

const int mx = 1000001;
vc<int> vis(mx, 0), cnt(mx, 0), prime;
vc<vc<int>> rcnt(mx, vc<int>(11, 0));

void sieve(int n) {
	vis[0] = 1;
	vis[1] = 1;
	if (n >= 2) 
		for (int i = 4; i <= n; i += 2) vis[i] = 1;
	if (n >= 3) 
		for (int i = 9; i <= n; i += 6) vis[i] = 1;
	for (int i = 5; i * i <= n; i += 6) {
		if (!vis[i]) 
			for (int j = i * i; j <= n; j += (2 * i)) vis[j] = 1;
		if (!vis[i + 2]) 
			for (int j = (i + 2) * (i + 2); j <= n; j += (2 * (i + 2))) vis[j] = 1;
	}
	for (int i = 2; i <= n; i++) if (!vis[i]) prime.push_back(i);
	for (auto &i: prime) for (int j = i; j <= n; j += i) cnt[j]++;
	for (int i = 1; i <= n; i++) 
		rcnt[i] = rcnt[i - 1], rcnt[i][cnt[i]]++;
}

void solve() {
	int l, r, cnt;
	cin >> l >> r >> cnt;
	cout << rcnt[r][cnt] - rcnt[l - 1][cnt] << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    sieve(mx - 1);

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}