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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int res(0);
	for (int i = 0; i < n; i++) if (s[i] == '*') {
		s[i] = 'x';
		res++;
		break;
	}
	for (int i = n - 1; i >= 0; i--) if (s[i] == '*') {
		s[i] = 'x';
		res++;
		break;
	}
	for (int i = 0; i < n; i++) if (s[i] == 'x') {
		if (i + k < n) for (int j = i + k; j > i; j--) {
			if (s[j] == '*') {
				s[j] = 'x';
				res++;
				break;
			}
			else if (s[j] == 'x') break;
		}
	}
	cout << res << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}