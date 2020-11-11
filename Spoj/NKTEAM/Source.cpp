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

struct ranks {
	int a, b, c;

	ranks() : a(0), b(0), c(0) {}
	
	bool operator < (ranks x) {
		return a < x.a;
	}
};

void solve() {
	int n, x;
	cin >> n;
	vector<int> tr(n, INT_MAX);
	vector<ranks> v(n);
	for (int i = 0; i < n; i++) cin >> x, v[x - 1].a = i;
	for (int i = 0; i < n; i++) cin >> x, v[x - 1].b = i;
	for (int i = 0; i < n; i++) cin >> x, v[x - 1].c = i;

	function<void(int, int)> update = [&](int idx, int val) {
		for (int i = idx; i < n; i |= (i + 1)) tr[i] = min(tr[i], val);
	};

	function<int(int)> query = [&] (int idx) {
		int r = INT_MAX;
		for (int i = idx; i >= 0; i = (i & (i + 1)) - 1) r = min(r, tr[i]);
		return r;
	};

	sort(v.begin(), v.end());
	int cnt(0);
	for (int i = 0; i < n; i++) {
		int x = query(v[i].b - 1);
		if (x > v[i].c) cnt++;
		update(v[i].b, v[i].c);
	}

	cout << cnt << '\n';
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}