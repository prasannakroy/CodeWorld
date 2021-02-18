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
    vc<array<int, 3>> a(n);
    vc<int> b(n);
    for (int i = 0; i < n; i++) cin >> a[i][0], a[i][2] = i, b[i] = a[i][0];
    for (auto &i: a) cin >> i[1];
    int res(0);
    sort(span(b));
    int i = 0;
    while (i < n) {
        if (a[i][0] == b[i]) {
            i++;
            continue;
        }
        int j = i;
        while (a[j][0] != b[i]) j++;
        int dif = a[j][2] - a[i][2] + 1;
        int cnt = (dif + a[i][1] - 1) / a[i][1];
        res += cnt;
        a[i][2] += (a[i][1] * cnt);
        j = i + 1;
        while (j < n and (a[j][2] < a[j - 1][2] or (a[j][2] == a[j - 1][2] and a[j][0] > a[j - 1][0]))) swap(a[j], a[j - 1]), j++;
    }
    cout << res << "\n";
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