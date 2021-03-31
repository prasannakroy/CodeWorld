/*****************************
*  Author :: Πρασαννα Κ. Ροι *
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
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

int Ceil(int x, int y) {
	return (x + y - 1) / y;
}

int compute(int val, int x, int t) {
	int d = 1e5;
	if (t == 1) return val + Ceil(x, d);
	else return Ceil(val * x, d);
}

void solve() {
	int n, m, cnt(1);
	cin >> n >> m;
	vc<int> res(m + 1, -1), vis(m + 1, 0);
	vis[0] = 1;
	for (int c = 0; c < n; c++) {
		cnt++;
		int t, x, y;
		cin >> t >> x >> y;
		for (int i = 0; i <= m; i++) {
			if (vis[i] and vis[i] < cnt) {
				vis[i] = cnt;
				int j = compute(i, x, t);
				for (int k = 1; k < y and j <= m; k++) {
					if (vis[j]) break;
					vis[j] = cnt;
					if (res[j] == -1) res[j] = c + 1;
					j = compute(j, x, t);
				}
				if (j <= m and !vis[j]) {
					vis[j] = cnt;
					if (res[j] == -1) res[j] = c + 1;
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) cout << res[i] << " ";
	cout << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}