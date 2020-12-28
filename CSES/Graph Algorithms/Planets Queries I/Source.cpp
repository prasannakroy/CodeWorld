/*****************************
*  Author :: Prasanna Kumar  *
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

int parent[200001][32];

void solve() {
	int n, q, x, k;
	cin >> n >> q;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i]; 
	int l(32);
	for (int i = 1; i <= n; i++) parent[i][0] = a[i];
	for (int j = 1; j < l; j++) 
		for (int i = 1; i <= n; i++) 
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
	while (q--) {
		cin >> x >> k;
		int c = 0;
		while (k) {
			if (k & 1) x = parent[x][c];
			k >>= 1;
			c++;
		}
		cout << x << "\n";
	}
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