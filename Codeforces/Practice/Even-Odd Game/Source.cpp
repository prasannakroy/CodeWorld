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
	int n, x;
	cin >> n;
	vc<int> odd, even;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x & 1) odd.push_back(x);
		else even.push_back(x);
	}
	sort(span(odd), greater<int>());
	sort(span(even), greater<int>());
	int i = 0, j = 0, sme(0), smo(0), t(0);
	while (i < odd.size() and j < even.size()) {
		if (t) {
			if (even[j] > odd[i]) j++;
			else smo += odd[i++];
		}
		else {
			if (odd[i] > even[j]) i++;
			else sme += even[j++];
		}
		t ^= 1;
	}
	for (; i < odd.size(); i++) {
		if (t) smo += odd[i];
		t ^= 1;
	}
	for (; j < even.size(); j++) {
		if (!t) sme += even[j];
		t ^= 1;
	}
	if (sme < smo) cout << "Bob\n";
	else if (sme > smo) cout << "Alice\n";
	else cout << "Tie\n";
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