// Unus Pro Omnibus, Omnus pro Uno - Alexander Dumas
// Authored by Prasanna Kumar alias prasanna2425
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define i_64 long long


void solve(int t) {
    int n, res(0);
    cin >> n;
    int a[n];
    for (int &i: a) cin >> i;
    for (int i = 1; i < n - 1; i++) {
        if (a[i] > a[i - 1] and a[i] > a[i + 1]) {
            res++;
        }
    }
    cout << "Case #" << t << ": " << res << "\n";
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