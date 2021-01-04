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
	int n, x, y, sum(0);
	cin >> n;
	vc<int> a(n), deg(n, 0), res;
	for (auto &i: a) cin >> i, sum += i;
	for (int i = 1; i < n; i++) cin >> x >> y, deg[x - 1]++, deg[y - 1]++;
	priority_queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) q.push({a[i], deg[i] - 1});
	res.push_back(sum);
	for (int i = 2; i < n; i++) {
		while (!q.empty() and !q.top().second) q.pop();
		sum = res.back();
		auto tp = q.top();
		q.pop();
		tp.second -= 1;
		q.push(tp);
		res.push_back(sum + tp.first);
	}
	for (auto &i: res) cout << i << " ";
	cout << "\n";
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