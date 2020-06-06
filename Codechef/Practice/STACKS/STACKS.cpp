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

const i_64 MX = 1000005;

void solve() {
    int n;
    cin >> n;
    int a[n], sol[n];
    for (int &i: a) cin >> i;
    int mx(INT_MIN), sz = 0;
    for (int i = 0; i < n; i++) {
        if (sz == 0) {
            sol[sz++] = a[i];
            mx = a[i];
        }
        else {
            if (a[i] >= mx) {
                sol[sz++] = a[i];
                mx = a[i];
                continue;
            }
            int l = 0, r = sz - 1, ind = -1;
            while (l < r) {
                int m = (l + r) >> 1;
                if (sol[m] <= a[i]) 
                    l = m + 1;
                else 
                    r = m, ind = m;
            }
            if (l < sz and sol[l] > a[i]) ind = l;
            if (ind == -1) 
                sol[sz++] = a[i];
            else 
                sol[ind] = a[i];
        }
    }
    cout << sz << " ";
    for (int i = 0; i < sz; i++) 
        cout << sol[i] << " ";
    cout << "\n";
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
    