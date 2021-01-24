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
    int n, sol;
    cin >> n;
    n <<= 1;
    vc<int> a(n);
    map<int, vector<int>> m;
    map<int, int> vis;
    vector<pair<int, int>> res;
    for (auto &i: a) cin >> i;
    sort(span(a));
    for (int i = 0; i < n; i++) m[a[i]].push_back(i);
    int val = a[n - 1];
    bool flag = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (vis[a[i]]) continue;
        vis[a[i]] = 1;
        val = a[n - 1];
        map<int, int> mp;
        auto rec = m;
        mp[i] = 1;
        sol = a[n - 1] + a[i];
        res.push_back({a[n - 1], a[i]});
        bool check = 1;
        rec[a[i]].pop_back();
        for (int j = n - 2; j >= 0; j--) {
            if (mp[j]) continue;
            rec[a[j]].pop_back();
            if (!rec[val - a[j]].size()) {
                check = 0;
                break;
            }
            int idx = rec[val - a[j]].back();
            rec[val - a[j]].pop_back();
            mp[idx] = 1;
            res.push_back({a[j], a[idx]});
            val = a[j];
        }
        if (check) {
            flag = 1;
            break;
        }
        res.clear();
    }
    if (!flag) return void(cout << "NO\n");
    cout << "YES\n";
    cout << sol << "\n";
    for (auto &i: res) cout << i.first << " " << i.second << "\n";
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