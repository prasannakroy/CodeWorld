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

bool sieve[100000];

void solve() {
    int n;
    cin >> n;
    if (!(n & 1)) {
        cout << n  / 2 << " " << n / 2 << "\n";
        return;
    }
    if (n % 3 == 0) {
        cout << n / 3 << " " << 2 * n / 3 << "\n";
        return;
    }
    int res(-1);
    for (int i = 5; i * i <= n; i += 6) {
        if (!sieve[i] and n % i == 0) {
            res = i;
            break;
        }
        if (!sieve[i + 2] and n % (i + 2) == 0) {
            res = i + 2;
            break;
        }
    }
    if (res == -1) 
        cout << 1 << " " << n - 1 << "\n";
    else 
        cout << n / res << " " << (res - 1) * (n / res) << "\n";
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs
    for (int i = 4; i < 100001; i += 2) sieve[i] = 1;
    for (int i = 9; i < 100001; i += 6) sieve[i] = 1;
    for (int i = 5; i * i <= 1000000000; i += 6) {
        if (!sieve[i]) 
            for (int j = i * i; j < 100001; j += (2 * i)) sieve[j] = 1;
        if (!sieve[i + 2]) 
            for (int j = (i + 2) * (i + 2); j < 100001; j += (2 * (i + 2))) sieve[j] = 1;
    }
    
  
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
