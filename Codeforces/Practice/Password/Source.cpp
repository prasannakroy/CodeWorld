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
	string s;
	cin >> s;
	int n = s.length();
	vector<int> v(n, 0);
	int len(0), i(1);
	while (i < n) {
		if (s[i] == s[len]) v[i++] = ++len;
		else {
			if (len > 0) len = v[len - 1];
			else v[i++] = 0;
		}
	}
	int flag = 0;
	if (v[n - 1]) for (int i = n - 2; i >= 0; i--) if (v[i] == v[n - 1]) flag++;
	if (flag) for (int i = 0; i < v[n - 1]; i++) cout << s[i];
	else {
		if (v[n - 1]) flag = v[v[n - 1] - 1];
		if (flag) for (int i = 0; i < flag; i++) cout << s[i];
		else cout << "Just a legend";
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