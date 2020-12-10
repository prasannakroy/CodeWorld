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

int count_unique_substrings(string &s, int l, int n) {
    const int p1(31), p2(37);
    const int m = (1e9) + 7;
    vector<int> p1_pow(n), p2_pow(n);
    p1_pow[0] = 1;
    p2_pow[0] = 1;
    for (int i = 1; i < n; i++) {
        p1_pow[i] = (p1_pow[i - 1] * p1) % m;
        p2_pow[i] = (p2_pow[i - 1] * p2) % m;
    }

    vector<pair<int, int>> h(n + 1);
    for (int i = 0; i < n; i++) {
        h[i + 1].first = (h[i].first + (s[i] - 'a' + 1) * p1_pow[i]) % m;
        h[i + 1].second = (h[i].second + (s[i] - 'a' + 1) * p2_pow[i]) % m;
    }
    set<pair<int, int>> hs;
    for (int i = 0; i <= n - l; i++) {
        int cur_h1 = (h[i + l].first + m - h[i].first) % m;
        int cur_h2 = (h[i + l].second + m - h[i].second) % m;
        cur_h1 = (cur_h1 * p1_pow[n - i - 1]) % m;
        cur_h2 = (cur_h2 * p2_pow[n - i - 1]) % m;
        hs.insert({cur_h1, cur_h2});
    }
    return hs.size();
}

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	cout << count_unique_substrings(s, k, n) << "\n";
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