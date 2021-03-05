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
int t;

void solve() {
    int n, a(1), val, idx;
    cin >> n;
    vector<int> vis(n + 1, 0);
    int res(n - 2);
    idx = n;
    while (a < n) {
        cout << "? " << a << " " << 1 << endl;
        for (int j = 1; j <= a; j++) cout << j << " ";
        cout << endl;
        cout << a + 1 << endl;
        cin >> val;
        if (val) {
            idx = a + 1;
            vis[idx] = 1;
            break;
        }
        a++;
    }
    int l = 1, r = idx;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        int sz = idx - m;
        cout << "? " << sz << " " << 1 << endl;
        for (int i = 0; i < sz; i++) cout << i + m << " ";
        cout << endl;
        cout << idx << endl;
        cin >> val;
        if (val) l = m;
        else r = m;
    }
    vis[l] = 1;
    for (int i = idx + 1; i <= n; i++) {
        cout << "? " << 1 << " " << 1 << endl;
        cout << idx << endl;
        cout << i << endl;
        cin >> val;
        if (val) vis[i] = 1, res--;
    }
    cout << "! " << res << " ";
    for (int i = 1; i <= n; i++) if (!vis[i]) cout << i << " ";
    cout << endl;
}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    // int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << endl;  
    return 0;
}