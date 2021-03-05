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
    string s;
    cin >> s;
    int c[3] = {0}, sum(0);
    for (auto &i: s) c[i - 'A']++;
    if (c[0] + c[1] != c[2] and c[0] + c[2] != c[1] and c[1] + c[2] != c[0]) return void(cout << "NO\n");
    int n = s.length();
    for (auto &i: s) {
        if (i == s[0]) sum++;
        else if (c[i - 'A'] + c[s[0] - 'A'] == n / 2) sum++;
        else sum--;
        if (sum < 0) return void(cout << "NO\n");
    }
    if (sum) return void(cout << "NO\n");
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