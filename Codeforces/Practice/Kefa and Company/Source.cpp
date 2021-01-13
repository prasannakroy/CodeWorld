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
    int n, d;
    cin >> n >> d;
    vc<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
    sort(span(a));
    int res(0), t(0), i = 0;
    queue<array<int, 2>> q;
    while (i < n) {
        if (q.empty()) {
            q.push(a[i]), t += a[i][1];
            res = max(res, t);
            i++;
            continue;
        }
        while (!q.empty() and q.front()[0] <= a[i][0] - d) t -= q.front()[1], q.pop();
        q.push(a[i]);
        t += a[i][1];
        i++;
        res = max(res, t);
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
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}