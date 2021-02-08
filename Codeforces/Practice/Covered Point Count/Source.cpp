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
    vc<array<int, 2>> a(2 * n);
    map<int, int> m;
    for (int i = 0; i < 2 * n; i += 2){
        cin >> a[i][0] >> a[i + 1][0];
        a[i][1] = 1;
        a[i + 1][1] = -1;
        m[a[i][0]]++;
        if (a[i + 1][0] != a[i][0]) m[a[i + 1][0]]++;
    } 
    sort(span(a), [&](array<int, 2> x, array<int, 2> y) {
        return x[0] == y[0] ? x[1] > y[1] : x[0] < y[0];
    });
    vc<int> cnt(n + 1, 0);
    int l(0), c(0), i(0), flag = 0;
    while (i < n * 2) {
        cnt[c] += a[i][0] - l;
        if (flag) {
            flag = 0;
            cnt[c]--;
        }
        if (a[i][1] == -1) {
            cnt[c]++;
            flag = 1;
            while (i + 1 < 2 * n and a[i][0] == a[i + 1][0]) 
                c += a[i][1], i++;
        }
        c += a[i][1];
        l = a[i][0];
        i++;
    }
    for (int i = 1; i <= n; i++) cout << cnt[i] << " ";
    cout << "\n";
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