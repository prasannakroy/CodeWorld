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
    int n, m;
    cin >> n >> m;
    map<int, deque<int>> mp;
    map<int, int> mmp;
    vc<int> a(n), b(n), c(m);
    for (auto &i: a) cin >> i;
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < m; i++) cin >> c[i], mp[c[i]].push_back(i);
    vc<int> res(m, 0);
    int cnt(0);
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (mp[b[i]].empty()) return void(cout << "NO\n");
            int idx = mp[b[i]].front();
            res[idx] = i + 1;
            mmp[b[i]] = i + 1;
            mp[b[i]].pop_front();
        }
        if (!mmp[b[i]]) mmp[b[i]] = i + 1;
    }
    int flag = 0;
    for (int j = m - 1; j >= 0; j--) {
        if (!mmp[c[j]]) return void(cout << "NO\n");
        flag = mmp[c[j]];
        break;
    }
    for (int i = 0; i < m; i++) if (!res[i]) res[i] = flag;
    cout << "YES\n";
    for (auto &i: res) cout << i << " ";
    cout << "\n";
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