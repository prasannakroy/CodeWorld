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
#define span(a) a.begin(), a.end()

template<typename t>
using vc = vector<t>;

void solve() {
    int n, k, val, idx(1), cnt(1), flag(0);
    cin >> n >> k;
    cout << "? 1" << endl;
    cin >> val;
    vc<bool> vis(n + 1, 0);
    while (true) {
        cout << "? " << idx << endl;
        cin >> val;
        if (val == k) {
            if (idx == 1) vis[n] = 1;
            else vis[idx - cnt] = 1;
            for (int i = 1; i <= cnt; i++) vis[idx + i] = 1;
            cnt += 1;
            idx += cnt;
            if (idx > n) idx -= n;
        }
        else if (val < k) {
            while (val != k) {
                idx++;
                if (idx > n) idx -= n;
                cout << "? " << idx << endl;
                cin >> val;
            }
            return void(cout << "! " << idx << endl);
        }
        else {
            while (val != k) {
                idx -= 1;
                if (idx <= 0) idx += n;
                cout << "? " << idx << endl;
                cin >> val;
            }
            return void(cout << "! " << idx << endl);
        }
    }
}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}