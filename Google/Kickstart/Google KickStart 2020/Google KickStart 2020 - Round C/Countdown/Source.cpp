/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define i_64 long long

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int &i: a)cin >> i;
    int i = 0, count(0);
    while (i < n) {
        if (a[i] == k) {
            bool flag = 0;
            int m = k;
            while (i < n and a[i] == m) {
                i++;
                m--;
            }
            if (m == 0) {
                count++;
            }
        }
        else {
            i++;
        }
    }
    cout << count << "\n";
}

int main() {
    // auto start=chrono::steady_clock::now();
    // #ifndef ONLINE_JUDGE 
    //     __AnAkLuSmOs
    // #endif

    __AcHiLlEs
    
    i_64 t(1);
    cin >> t;
    for (int i = 1; i <= t; cout << "Case #" << i << ": ", solve(), i++);
    // auto end = chrono::steady_clock::now();
    // double elapsed = double (chrono::duration_cast < chrono::nanoseconds> (end-start).count());
    // cout << endl << "Terminated\n"<< elapsed/1e9;
    return 0;
}
