/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) a.begin(), a.end()
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)

void solve() {
	int n;
	while (cin >> n) {
		string s;
		cin >> s;
		vector<int> lps(n + 1, 0);

		function<void()> preCompute = [&]() {
			int len(0);
			int i(1);
			while (i < n) {
				if (s[i] == s[len]) lps[i++] = ++len;
				else {
					if (len != 0) len = lps[len - 1];
					else lps[i++] = 0;
				}
			}
		};

		preCompute();

		string x;
		cin >> x;
		int len(0), cnt(0), c(0);
		for (auto &j: x) {
			cnt++;
			loc : if (s[len] == j) {
			    len++;
			    if (len == n) {
			        c = 1;
			        cout << cnt - len << "\n";
			        len = lps[len - 1];
			    }
			}
			else if (len != 0) {
			    len = lps[len - 1];
			    goto loc;
			}
		}
		if (c) cout << "\n";
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