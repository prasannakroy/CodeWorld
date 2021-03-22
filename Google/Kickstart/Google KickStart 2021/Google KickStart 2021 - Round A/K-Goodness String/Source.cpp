/*****************************
*  Author :: Πρασαννα Κ. Ροι  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt(0);
    for (int i = 0; i < n / 2; i++) cnt += (s[i] != s[n - i - 1]);
    cout << abs(cnt - k) << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    // #ifndef ONLINE_JUDGE 
    //     __AnAkLuSmOs    
    // #endif

    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; cout << "Case #" << i << ": ", solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}