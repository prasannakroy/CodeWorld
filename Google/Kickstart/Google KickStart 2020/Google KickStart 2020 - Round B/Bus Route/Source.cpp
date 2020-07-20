// Unus Pro Omnibus, Omnus pro Uno - Alexander Dumas
// Authored by Prasanna Kumar alias prasanna2425
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define i_64 long long


void solve(int t) {
    i_64 n, d, res(0), x;
    cin >> n >> d;
    i_64 a[n];
    x = d;
    for (i_64 &i: a) cin >> i;
    for (int i = n - 1; i >= 0; i--) {
        x = (x / a[i]) * a[i];
    }
    cout << "Case #" << t << ": " << x << "\n";
}

int main() {
   __AcHiLlEs
    int t(1), i(1);
    cin >> t;
    while (t--) {
        solve(i);
        i++;
    }
    return 0;
}