/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define i_64 long long

const int MX = 10000001;
bool sieve[10000001];

signed main() {
    // auto start=chrono::steady_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    std::set<int> res;
    sieve[0] = true;
    sieve[1] = true;
    for (int i = 4; i < 10000001; i += 2)  sieve[i] = true;
    for (int i = 9; i < 10000001; i += 6)  sieve[i] = true;
    for (int i = 5; i * i < 10000001; i += 6) {
        if (!sieve[i])
            for (int j = i * i; j < 10000001; j += 2 * i)  sieve[j] = true;
        if (!sieve[i + 2]) 
            for (int j = (i + 2) * (i + 2); j < 10000001; j += 2 * (i + 2))  sieve[j] = true;
    }
    for (int i = 1; i * i < 10000001; i++) {
        for (int j = 1; j < 57; j++) {
            int x = (i * i) + (j * j * j * j);
            if (x < 10000001 and sieve[x] == false) res.insert(x);
        }
    }
    int len = res.size();
    std::vector<int> v;
    for (auto &i: res) v.push_back(i);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x = upper_bound(v.begin(), v.end(), n) - v.begin();
        cout << x << "\n";
    }
    // auto end = chrono::steady_clock::now();
    // double elapsed = double (chrono::duration_cast < chrono::nanoseconds> (end-start).count());
    // cout << endl << "Terminated\n"<< elapsed/1e9;
    return 0;
}
