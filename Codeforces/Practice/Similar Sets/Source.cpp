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
// #define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

void solve() {
    int n, m(0), cnt(1);
    cin >> n;
    vc<vc<int>> a(n);
    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int k, x;
        cin >> k;
        set<int> s;
        for (int j = 0; j < k; j++) {
            cin >> x;
            if (!mpp[x]) mpp[x] = cnt++;
            x = mpp[x];
            s.insert(x);
        }
        for (auto &j: s) a[i].push_back(j);
        m += a[i].size();
    }
    int d = sqrt(m);
    for (int i = 0; i < n; i++) if (a[i].size() >= d) {
        bool mp[cnt] = {0};
        for (auto &j: a[i]) mp[j] = 1;
        for (int j = 0; j < n; j++) if (j != i) {
            int cnt(0);
            for (auto &k: a[j]) cnt += mp[k];
            if (cnt >= 2) return void(cout << min(i, j) + 1 << " " << max(i, j) + 1 << "\n");
        }
    }
    vector<int> mp[cnt];
    for (int i = 0; i < n; i++) if (a[i].size() < d) 
        for (auto &j: a[i]) mp[j].push_back(i);

    int vis[cnt] = {0};
    for (int i = 1; i < cnt; i++) {
        for (auto &j: mp[i]) {
            for (auto &k: a[j]) {
                if (i == k) continue;
                if (vis[k]) return void(cout << vis[k] << " " << j + 1 << "\n");
                vis[k] = j + 1;
            }
        }
        for (auto &j: mp[i]) 
            for (auto &k: a[j]) vis[k] = 0;
    }
    cout << -1 << "\n";
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