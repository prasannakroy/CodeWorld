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

template<typename t> 
class DisjointSet {
public:
    vector<t> dsu, SIZE, value;
    DisjointSet(t n) {
        dsu.resize(n + 1);
        SIZE.assign(n + 1, 1);
        value.assign(n + 1, 0);
        iota(dsu.begin(), dsu.end(), 0);
    }

    t root(t a) {
    	if (a == dsu[a]) return a;
		int p = dsu[a];
		if (dsu[a] == dsu[dsu[a]]) return dsu[a] = root(dsu[a]);
		dsu[a] = root(dsu[a]);
		value[a] += value[p];
		return dsu[a];
    }

    t cost(t a) {
        return dsu[a] == a? value[a]: value[a] + cost(dsu[a]);
    }

    void join(t a, t b) {
        a = root(a);
        b = root(b);
        if (a == b) return; 
        if (value[a] < value[b]) dsu[b] = a, value[b] = value[b] - value[a];
        else dsu[a] = b, value[a] = value[a] - value[b];
    }
};

void solve() {
  	int n, m;
  	cin >> n >> m;
  	DisjointSet<int> DSU(n);
  	while (m--) {
	    string s;
	    cin >> s;
	    if (s == "add") {
	      int a, val;
	      cin >> a >> val;
	      a = DSU.root(a);
	      DSU.value[a] += val;
	    }
	    else if (s == "join") {
	      int a, b;
	      cin >> a >> b;
	      DSU.join(a, b);
	    }
	    else {
	      int a;
	      cin >> a;
	      cout << DSU.cost(a) << "\n";
	    }
  	}
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