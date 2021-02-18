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
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

void solve() {
	int n;
	cin >> n;
	vc<string> a(n);
	vc<vc<int>> cnt(26, vc<int>(26, 0)), c2(26, vc<int>(26, 0));
	vc<int> freq(26, 0);
	map<string, int> m;
	for (auto &i: a) cin >> i, m[i] = 1, freq[i[0] - 'a']++;
	for (int i = 0; i < 26; i++) 
		for (int j = 0; j < 26; j++) c2[i][j] = freq[j];
	for (int i = 0; i < n; i++) {
		for (char j = 'a'; j <= 'z'; j++) if (j != a[i][0]){
			char x = j;
			swap(x, a[i][0]);
			if (!m[a[i]]) {
				swap(x, a[i][0]);
				continue;
			}
			cnt[x - 'a'][a[i][0] - 'a'] += c2[x - 'a'][a[i][0] - 'a'];
			c2[a[i][0] - 'a'][x - 'a'] -= 1;
			swap(x, a[i][0]);
		}
	}
	int res(0);
	for (int i = 0; i < 26; i++) {
		if (freq[i]) for (int j = i + 1; j < 26; j++) if (freq[j]){
			int r = (freq[i] * freq[j]) - cnt[i][j] - cnt[j][i];
			res += (r * 2);
		}
	}
	cout << res << "\n";
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