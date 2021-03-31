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
	multiset<int> lt;
	multiset<int> rt;

	function<void()> balance = [&] () {
		if (rt.size() > lt.size()) {
			int val = *rt.begin();
			rt.erase(rt.begin());
			lt.insert(val);
		}
		else if (lt.size() > rt.size() + 1) {
			int val = *lt.rbegin();
			lt.erase(--lt.end());
			rt.insert(val);
		}
	};

	function<string()> findMedian = [&]() {
		double x = 0;
		string res = "Wrong!";
		if (!lt.size() and !rt.size()) return res;
		else if (lt.size() == rt.size()) {
			x = *lt.rbegin() + *rt.begin();
			x /= 2;
		}
		else 
			x = *lt.rbegin();
		res = to_string(x);
		int len = res.length();
		int i = 0;
		while (i < len and res[i] != '.') i++;
		if (res[i + 1] == '0') 
			res.erase(res.begin() + i, res.end());
		else {
			i++;
			while (res[i] != '0') i++;
			res.erase(res.begin() + i, res.end());
		}
		return res;
	};

	while (n--) {
		char t;
		int val;
		cin >> t >> val;
		if (t == 'a') {
			if (val >= *rt.begin()) 
				rt.insert(val);
			else 
				lt.insert(val);
			balance();
			cout << findMedian() << "\n";
		}
		else {
			if (lt.find(val) != lt.end()) 
				lt.erase(lt.find(val));
			else if (rt.find(val) != rt.end()) 
				rt.erase(rt.find(val));
			else {
				cout << "Wrong!\n";
				continue;
			}
			balance();
			cout << findMedian() << "\n";
		}
	}
}

signed main() {
    // auto start = high_resolution_clock::now();
    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}