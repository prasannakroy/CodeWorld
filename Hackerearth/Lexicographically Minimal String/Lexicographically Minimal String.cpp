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

const int MX = 1000005;
int dsu[MX];

void init(int n) {
    for (int i = 0; i <= n; i++) { 
        dsu[i] = i;
    }
}

int root(int a) {
    if (dsu[a] != a) 
        dsu[a] = root(dsu[a]);
    return dsu[a];
}

void join(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    dsu[max(a, b)] = min(a, b);
}

void solve() {
    init(26);
    string A, B, C;
    cin >> A >> B >> C;
    for (int i = 0; i < A.length(); i++) 
        join(A[i] - 'a', B[i] - 'a');
    for (int i = 0; i < C.length(); i++) {
        C[i] = root(C[i] - 'a') + 'a';
    }
    cout << C << "\n";
}

signed main() {
    // auto start=chrono::steady_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    i_64 t(1);
    // cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto end = chrono::steady_clock::now();
    // double elapsed = double (chrono::duration_cast < chrono::nanoseconds> (end-start).count());
    // cout << endl << "Terminated\n"<< elapsed/1e9;
    return 0;
}
