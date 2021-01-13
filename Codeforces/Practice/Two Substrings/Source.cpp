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
    int n = s.length();

    function<bool(string)> check = [&](string pat) {
        int i = 0, flag = 0;
        while (i < n and flag < 2) {
            if (i + 1 < n and s[i] == pat[0] and s[i + 1] == pat[1] and !flag) flag++, i++;
            else if (i + 1 < n and s[i] == pat[1] and s[i + 1] == pat[0] and flag) flag++;
            i++;
        }
        return (flag == 2);
    };
    
    if (check("AB") or check("BA")) cout << "YES\n";
    else cout << "NO\n";
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