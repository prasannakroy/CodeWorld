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

std::map<int, bool> sq;

void solve() {
    int n, cnt(0);
    cin >> n;
    int a[n];
    for (int &i: a) cin >> i;
    for (int i = 0; i < n; i++) {
        int sum = a[i];
        if (::sq[sum] == 1) {
            cnt++;
        }
        for (int j = i + 1; j < n; j++) {
            sum += a[j];
            if (::sq[sum] == 1) {
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
}

int main() {
    // auto start=chrono::steady_clock::now();
    // #ifndef ONLINE_JUDGE 
    //     __AnAkLuSmOs
    // #endif

    __AcHiLlEs
    

    for (int i = 0; i < 10000; i++) {
        sq[i * i] = 1;
    }

    i_64 t(1);
    cin >> t;
    for (int i = 1; i <= t; cout << "Case #" << i << ": ", solve(), i++);
    // auto end = chrono::steady_clock::now();
    // double elapsed = double (chrono::duration_cast < chrono::nanoseconds> (end-start).count());
    // cout << endl << "Terminated\n"<< elapsed/1e9;
    return 0;
}

