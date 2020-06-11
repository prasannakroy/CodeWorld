/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define i_64 long long

const i_64 mx = 10000001;
i_64 sieve[mx];

void solve() {
    i_64 n;
    cin >> n;
    vector<i_64> res1, res2;
    while (n--) {
        i_64 a;
        cin >> a;
        i_64 t = a;
        set<i_64> pr;
        while (t > 1) {
            pr.insert(sieve[t]);
            t /= sieve[t];
        }
        // for (i_64 &i: pm) cout << i << " ";
        // cout << "\n";
        vector<i_64> pm;
        for (auto &i: pr) pm.push_back(i);
        if (pm.size() == 1) {
            res1.push_back(-1);
            res2.push_back(-1);
            continue;
        }
        a = 1;
        i_64 b = 1;
        for (i_64 &i: pm) a *= i;
        a /= pm[0];
        b *= pm[0];
        res1.push_back(a);
        res2.push_back(b);
    }
    for (i_64 &i: res1) cout << i << " ";
    cout << "\n";
    for (i_64 &i: res2) cout << i << " ";
}

signed main() {
    __AcHiLlEs
    
    sieve[0] = 1;
    sieve[1] = 1;
    sieve[2] = 2;
    for (i_64 i = 4; i <= mx; i += 2) {
        sieve[i] = 2;
    }
    
    for (i_64 i = 3; i < mx; i += 2) {
        if (!sieve[i]) {
            sieve[i] = i;
            for (i_64 j = i * i; j < mx; j += (2 * i)) 
                sieve[j] = i;
        }
    }
    i_64 t(1);
    // cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
