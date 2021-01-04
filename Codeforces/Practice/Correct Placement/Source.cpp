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
	int n, x, y;
	cin >> n;
	vc<array<int, 3>> v[2];
	vc<array<int, 2>> w;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v[0].push_back({x, y, i + 1});
		v[1].push_back({y, x, i + 1});
		w.push_back({x, y});
	}

	sort(v[0].begin(), v[0].end(), [&](array<int, 3> a, array<int, 3> b) {
		return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
	});
	sort(v[1].begin(), v[1].end(), [&](array<int, 3> a, array<int, 3> b) {
		return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
	});

	for (int i = 1; i < n; i++) {
		if (v[0][i][1] > v[0][i - 1][1]) {
			v[0][i][1] = v[0][i - 1][1];
			v[0][i][2] = v[0][i - 1][2];
		}
		if (v[1][i][1] > v[1][i - 1][1]) {
			v[1][i][1] = v[1][i - 1][1];
			v[1][i][2] = v[1][i - 1][2];
		}
	}

	function<int(int, int)> lowerBound = [&] (int val, int t) {
		int l = 0, r = n - 1, res(n);
		while (l <= r) {
			int m = (l + r) >> 1;
			if (v[t][m][0] >= val) {
				res = m;
				r = m - 1;
			}
			else l = m + 1;
		}
		return res;
	};


	vector<int> res(n);

	for (int i = 0; i < n; i++) {
		int idx1 = lowerBound(w[i][0], 0);
		int idx2 = lowerBound(w[i][0], 1);
		idx1--;
		idx2--;
		if (idx1 >= 0 and v[0][idx1][1] < w[i][1]) 
			res[i] = v[0][idx1][2];
		else if (idx2 >= 0 and v[1][idx2][1] < w[i][1])
			res[i] = v[1][idx2][2];
		else res[i] = -1;
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