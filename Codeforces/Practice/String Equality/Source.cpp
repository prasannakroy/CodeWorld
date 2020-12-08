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
	int n, k;
	cin >> n >> k;
	vector<int> cnt1(26, 0), cnt2(26, 0);
	string a, b;
	cin >> a >> b;
	for (auto &i: a) cnt1[i - 'a']++;
	for (auto &i: b) cnt2[i - 'a']++;
	for (int i = 0; i < 26; i++) 
		tie(cnt1[i], cnt2[i]) = make_tuple(cnt1[i] - min(cnt1[i], cnt2[i]), cnt2[i] - min(cnt1[i], cnt2[i]));
	bool flag(1);
	int i(0), j(0);
	while (i < 26 and j < 26) {
		if (cnt1[i]) {
			if (cnt1[i] % k) {
				flag = 0;
				break;
			}
			int c(0);
			while (j < 26 and !cnt2[j]) j++;
			if ((i < 26 and j == 26) or i > j or cnt2[j] % k) {
				flag = 0;
				break;
			}
			tie(cnt1[i], cnt2[j]) = make_tuple(cnt1[i] - min(cnt1[i], cnt2[j]), cnt2[j] - min(cnt1[i], cnt2[j]));
		}
		else i++;
	}
	if (flag) cout << "YES\n";
	else cout << "NO\n";
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