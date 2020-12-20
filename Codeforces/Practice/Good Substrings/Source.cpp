/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) a.begin(), a.end()
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)

int p1 = 27, p2 = 33;
int mod = (int)1e9 + 7;

void solve() {
    int k;
    string s, t;
    cin >> s >> t >> k;
    int n = s.length();
    vector<int> pw1(n), pw2(n);
    pw1[0] = 1;
    pw2[0] = 1;
    int res(0);
    for (int i = 1; i < n; i++) pw1[i] = (pw1[i - 1] * p1) % mod, pw2[i] = (pw2[i - 1] * p2) % mod;
    for (int m = 1; m <= n; m++) {
        set<array<int, 3>> st;
        array<int, 3> hs{0, 0, 0};
        for (int i = 0; i < n; i++) {
            int x = s[i] - 'a' + 1;
            if (i < m) {
                hs[0] = (((hs[0] * p1) % mod) + x) % mod;
                hs[1] = (((hs[1] * p2) % mod) + x) % mod;
                hs[2] += (t[x - 1] - '0');
                if (i == m - 1) st.insert(hs);
                continue;
            }
            int y = s[i - m] - 'a' + 1;
            hs[0] = hs[0] - (y * pw1[m - 1]) % mod;
            hs[1] = hs[1] - (y * pw2[m - 1]) % mod;
            hs[2] -= (t[y - 1] - '0');
            if (hs[0] < 0) hs[0] += mod;
            if (hs[1] < 0) hs[1] += mod;
            hs[0] = (((hs[0] * p1) % mod) + x) % mod;
            hs[1] = (((hs[1] * p2) % mod) + x) % mod;
            hs[2] += (t[x - 1] - '0');
            st.insert(hs);
        }
        for (auto &i : st) if (m - i[2] <= k) res++;
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