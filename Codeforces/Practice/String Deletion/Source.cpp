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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vc<int> a;
    int c(1);
    for (int i = 1; i < n; i++) {
    	if (s[i] != s[i - 1]) a.push_back(c), c = 1;
    	else c++;
    }
    a.push_back(c);
    n = a.size();
    int res(0);
    for (int i = 0, j = 0; i < n; i++) {
    	if (a[i] > 1) 
    		a[i] = 0;
    	else {
    		while (j < n and a[j] <= 1) j++;
    		if (j == n) a[i] = 0, i++;
    		else {
    			a[j]--;
    			a[i] = 0;
    		}
    	}
    	res++;
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