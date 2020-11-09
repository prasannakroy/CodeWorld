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

vector<vector<int>> tr;

void update(int x, int y, int val, int n) {
	for (int i = x; i < n; i |= (i + 1)) 
		for (int j = y; j < n; j |= (j + 1)) 
			tr[i][j] += val;
}

int query (int x2, int y2, int x1 = -1, int y1 = -1) {
	if (~x1 and ~y1) return query(x2, y2) + query(x1 - 1, y1 - 1) - query(x1 - 1, y2) - query(x2, y1 - 1);
	int sm(0);
	for (int i = x2; i >= 0; i = (i & (i + 1)) - 1) 
		for (int j = y2; j >= 0; j = (j & (j + 1)) - 1) 
			sm += tr[i][j];
	return sm;
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n, 0));
	tr.assign(n, vector<int>(n, 0));
	string s;
	while (cin >> s and s != "END") {
		if (s == "SET") {
			int x, y, val;
			cin >> x >> y >> val;
			update(x, y, -v[x][y], n);
			v[x][y] = val;
			update(x, y, v[x][y], n); 
		}
		else {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << query(x2, y2, x1, y1) << "\n";
		}
	}
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}