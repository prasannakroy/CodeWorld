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
    int l(1), r(n);
    vc<int> a(n + 2, 0);
    while (true) {
        int idx1 = l + (rand() % (r - l + 1));
        cout << "? " << idx1 << endl;
        int val1, val2(INT_MAX), val3(INT_MAX);
        cin >> val1;
        if (idx1 > 1) {
            if (a[idx1 - 1]) val2 = a[idx1 - 1];
            else {
                cout << "? " << idx1 - 1 << endl;
                cin >> val2;
                a[idx1 - 1] = val2;
            }
        }
        if (idx1 < n) {
            if (a[idx1 + 1]) val3 = a[idx1 + 1];
            else {
                cout << "? " << idx1 + 1 << endl;
                cin >> val3;
                a[idx1 + 1] = val3;
            }
        }
        if (val1 < min(val2, val3)) return void(cout << "! " << idx1 << endl);
        else if (val2 < val1 and val1 < val3) 
            r = idx1 - 1;
        else l = idx1 + 1;
    }
}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs
    srand(time(NULL));

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}