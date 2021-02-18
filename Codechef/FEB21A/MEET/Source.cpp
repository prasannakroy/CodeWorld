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

struct Time {
    string t;
    int hr, mn;

    Time(string s, string t) : t(t) {
        hr = ((s[0] - '0') * 10) + s[1] - '0';
        mn = ((s[3] - '0') * 10) + s[4] - '0';
        if (t == "AM" and hr == 12) hr = 0;
        if (t == "PM" and hr != 12) hr += 12;
    }

    bool operator < (const Time& a) const {
        if (t != a.t) 
            return t == "AM";
        return hr == a.hr ? mn <= a.mn : hr <= a.hr;
    }
    bool operator > (const Time& a) const {
        if (t != a.t) 
            return t == "PM";
        return hr == a.hr ? mn >= a.mn : hr >= a.hr;
    }
};

void solve() {
    string s, t;
    cin >> s >> t;
    Time p(s, t);
    int n, cnt(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        Time l(s, t);
        cin >> s >> t;
        Time r(s, t);
        cout << (l < p and p < r);
    }
    cout << "\n";
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