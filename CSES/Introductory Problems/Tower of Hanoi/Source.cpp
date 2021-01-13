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
#define int int64_t
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

void towerOfHanoi(int n, int s, int e, int aux) {
    if (n == 1) return void(cout << s << " " << e << "\n");
    towerOfHanoi(n - 1, s, aux, e);
    cout << s << " " << e << "\n";
    towerOfHanoi(n - 1, aux, e, s);
}

void solve() {
    int n;
    cin >> n;
    cout << (1 << n) - 1 << "\n";
    towerOfHanoi(n, 1, 3, 2);
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