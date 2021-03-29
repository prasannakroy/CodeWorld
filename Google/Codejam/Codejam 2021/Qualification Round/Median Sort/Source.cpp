/*****************************
* Author :: Πρασαννα Κ. Ροι  *
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

vc<int> res;

// mt19937_64 mersenne {static_cast<mt19937_64::result_type>(time(NULL))};

// int randInt(int l, int r) {return uniform_int_distribution<int>(l, r)(mersenne);}

bool compute(vc<int> &a, int prev = -1, int nxt = -1, int idx = 0) {
	int n = a.size();
	if (n == 1) {
		res[idx] = a[0];
		return true;
	}
	else if (n == 2) {
		if (~prev) {
			cout << prev << " " << a[0] << " " << a[1] << endl;
			int m;
			cin >> m;
			if (m == -1) return false;
			else if (m == a[0]) res[idx] = a[0], res[idx + 1] = a[1];
			else res[idx] = a[1], res[idx + 1] = a[0];
		}
		else if (~nxt) {
			cout << nxt << " " << a[0] << " " << a[1] << endl;
			int m;
			cin >> m;
			if (m == -1) return false;
			else if (m == a[0]) res[idx] = a[1], res[idx + 1] = a[0];
			else res[idx] = a[0], res[idx + 1] = a[1];
		}
		return true;
	}
	int l = rand() % n;
	int r = l;
	while (r == l) r = rand() % n;
	l = a[l];
	r = a[r];
	if (~prev) {
		int m;
		cout << prev << " " << l << " " << r << endl;
		cin >> m;
		if (m == -1) return false;
		if (m == r) swap(l, r);
	}
	else if (~nxt) {
		int m;
		cout << nxt << " " << l << " " << r << endl;
		cin >> m;
		if (m == -1) return false;
		if (m == l) swap(l, r);
	}
	vector<int> lt, md, rt;
	for (int i = 0; i < n; i++) if (a[i] != l and a[i] != r) {
		cout << l << " " << r << " " << a[i] << endl;
		int m;
		cin >> m;
		if (m == -1) return false;
		if (m == l) lt.push_back(a[i]);
		else if (m == r) rt.push_back(a[i]);
		else md.push_back(a[i]);
	}
	int lidx = idx + lt.size();
	int ridx = idx + lt.size() + md.size() + 1;
	res[lidx] = l;
	res[ridx] = r;
	bool flag = 1;
	if (lt.size()) flag &= compute(lt, -1, l, idx);
	if (!flag) return flag;
	if (md.size()) flag &= compute(md, l, r, lidx + 1);
	if (!flag) return flag;
	if (rt.size()) flag &= compute(rt, r, -1, ridx + 1);
	return flag;
}

void solve() {
	int t, n, q;
	cin >> t >> n >> q;
	res.assign(n, -1);
	while (t--) {
		vc<int> a(n);
		iota(span(a), 1);
		if (!compute(a)) return;
		for (auto &i: res) cout << i << " ";
		cout << endl;
		int r;
		cin >> r;
		if (r != 1) return;
	}
}

signed main() {
    // auto start = high_resolution_clock::now();
    __AcHiLlEs

    srand(time(NULL));

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}
