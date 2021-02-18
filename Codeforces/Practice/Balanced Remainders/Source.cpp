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
    int n, x;
    cin >> n;
    int cnt[3] = {0};
    for (int i = 0; i < n; i++) cin >> x, cnt[x % 3]++;
    int res(0);
    for (int i = 0; i < 3; i++) if (cnt[i] > n / 3){
        for (int j = 0; j < 3; j++) if (cnt[j] < n / 3 and cnt[i] > n / 3) {
            int c = min((n / 3) - cnt[j], cnt[i] - (n / 3));
            cnt[j] += c, cnt[i] -= c;
            if (j < i) res += ((3 - i + j) * c);
            else res += (j - i) * c;
        }
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