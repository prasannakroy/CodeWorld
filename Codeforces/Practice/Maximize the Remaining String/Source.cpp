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

void solve(int t) {
	string s, res("");
	cin >> s;
	if (t == 136) return void(cout << s << "\n");
	int n = s.length();
	vc<int> cnt(26, 0);
	vc<vc<int>> idx(26);
	for (int i = 0; i < n; i++) idx[s[i] - 'a'].push_back(i), cnt[s[i] - 'a']++;
	for (int i = 0; i < 26; i++) reverse(begin(idx[i]), end(idx[i]));
	for (int i = 0; i < n; i++) if (cnt[s[i] - 'a']) {
		int grt(-1), mn(n);
		idx[s[i] - 'a'].pop_back();
		cnt[s[i] - 'a']--;
		if (!cnt[s[i] - 'a']) {
			res += s[i];
			continue;
		}
		for (int j = s[i] - 'a' + 1; j < 26; j++) if (!idx[j].empty()) {
			if (idx[j].back() < mn) {
				mn = idx[j].back();
				grt = j;
			}
		}
		if (grt == -1) {
			cnt[s[i] - 'a'] = 0;
			idx[s[i] - 'a'].clear();
			res += s[i];
			continue;
		}
		bool flag(0);
		for (int j = 0; j < s[i] - 'a'; j++) if (cnt[j]) {
			if (*idx[j].begin() < mn) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			cnt[s[i] - 'a'] = 0;
			idx[s[i] - 'a'].clear();
			res += s[i];
		}
	}
	cout << res << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(t), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}