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
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

void solve() {
	int n, cnt(0), x, y;
	cin >> n;
	auto cmp = [](array<int, 2> x, array<int, 2> y) {return x[1] == y[1] ? x[0] < y[0] : x[1] > y[1];};
	set<array<int, 2>, decltype(cmp)> a(cmp);
	set<array<int, 2>> b;
	while (n--) {
		cin >> x;
		if (x == 1) {
		    cin >> y;
			cnt++;
			a.insert({cnt, y});
			b.insert({cnt, y});
		}
		else if (x == 2) {
			auto r = *b.begin();
			a.erase(a.find(r));
			b.erase(b.begin());
			cout << r[0] << " ";
		}
		else {
			auto r = *a.begin();
			a.erase(a.begin());
			b.erase(b.find(r));
			cout << r[0] << " ";
		}
	}
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