/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) a.begin(), a.end()
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)

void solve() {
	int n, m, x;
	cin >> n >> m;
	multiset<int> a;
	for (int i = 0; i < n; i++) cin >> x, a.insert(x);
	vector<int> res(m, -1);
	int i = 0;
	while (m - i) {
		cin >> x;
		if (a.empty()) {
			i++;
			continue;
		}
		auto idx = a.upper_bound(x);
		if (idx == a.begin()) {
			i++;
			continue;
		}
		idx--;
		res[i++] = *idx;
		a.erase(idx);
	}
	for (auto &i: res) cout << i << "\n";
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