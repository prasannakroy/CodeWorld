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
#define i_64 unsigned long long

void solve() {
    double h, s;
    cin >> h >> s;
    double h1 = h * 1.0;
    double k = h1 * h1 - (4 * s);
    if(k < 0) {
        cout << -1 << "\n";
        return;
    }
    double k1 = (h * h) + (4 * s);
    double b = (sqrt(k) + sqrt(k1)) / 2.0;
    double p = (2.0 * s) / b;
    if(b > p) 
        cout << fixed << setprecision(4) << p << " " << b << " " << h1 << "\n";
    else
        cout << fixed << setprecision(4) << b << " " << p << " " << h1 << "\n";
}

signed main() {
    // auto start=chrono::steady_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto end = chrono::steady_clock::now();
    // double elapsed = double (chrono::duration_cast < chrono::nanoseconds> (end-start).count());
    // cout << endl << "Terminated\n"<< elapsed/1e9;
    return 0;
}
    