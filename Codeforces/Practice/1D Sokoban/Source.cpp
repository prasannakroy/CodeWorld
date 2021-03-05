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
    int n, m, x;
    cin >> n >> m;
    vc<int> a[2], b[2];
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > 0) a[1].push_back(x);
        else a[0].push_back(-x);
    }
    for (int i = 0; i < m; i++) {
        cin >> x;
        if (x > 0) b[1].push_back(x);
        else b[0].push_back(-x);
    }   
    reverse(span(a[0]));
    reverse(span(b[0]));

    auto compute = [&](int t) {
        int sz1 = a[t].size();
        int sz2 = b[t].size();
        if (!sz1 or !sz2) return 0ll;
        vc<int> cnt(sz1 + 1, 0);
        for (int i = sz1 - 1, j = sz2 - 1; i >= 0; i--) {
            cnt[i] = cnt[i + 1];
            while (j >= 0 and b[t][j] > a[t][i]) j--;
            if (j >= 0 and a[t][i] == b[t][j]) cnt[i]++;
        }
        int res(0);
        for (int l = 0, c = 0, r = 0; l < sz2; l++) {
            while (c < sz1 and a[t][c] <= b[t][l] + c) c++;
            while (r < sz2 and b[t][r] < b[t][l] + c) r++;
            res = max(res, r - l + cnt[c]);
        }
        return res;
    };
    cout << compute(0) + compute(1) << "\n";
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