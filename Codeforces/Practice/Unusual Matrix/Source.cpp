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

void flip(char &a) {
    if (a == '1') a = '0';
    else a = '1';
}

void solve() {
    int n;
    cin >> n;
    vc<string> a(n), b(n);
    vc<vc<int>> c(n, vc<int>(n));
    for (auto &i: a) cin >> i;
    for (auto &i: b) cin >> i;
    map<int, int> visr, visc;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != b[i][j]) {
                if (!visr[i]) {
                    visr[i] = 1;
                    for (int k = 0; k < n; k++) {
                        flip(a[i][k]);
                        if (a[i][k] == b[i][k]) visc[k] = 1;
                    }
                }
                else if (!visc[j]) {
                    visc[j] = 1;
                    for (int k = 0; k < n; k++) {
                        flip(a[k][j]);
                        if (a[k][j] == b[k][j]) visr[k] = 1;
                    }
                }
                else return void(cout << "NO\n");
            }
            else visr[i] = visc[j] = 1;
        }
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (a[i][j] != b[i][j]) return void(cout << "NO\n");
    cout << "YES\n";
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