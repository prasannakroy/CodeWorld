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
    vc<int> a(n);
    map<int, int> mp;
    for (auto &i: a) cin >> i, mp[i]++;
    vc<int> cnt;
    for (auto &[x, y]: mp) cnt.push_back(y);
    sort(span(cnt));
    int res(INT_MAX), sum(0), i(0);
    int sz = cnt.size();
    vc<int> rm(sz + 1, 0);
    for (int i = sz - 1; i >= 0; i--) rm[i] = rm[i + 1] + cnt[i];
    while (i < sz) {
        int idx = sz - i;
        int c = sum + rm[i] - (cnt[i] * idx);
        res = min(res, c);
        while (i + 1 < sz and cnt[i + 1] == cnt[i]) sum += cnt[i], i++;
        sum += cnt[i];
        i++;
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