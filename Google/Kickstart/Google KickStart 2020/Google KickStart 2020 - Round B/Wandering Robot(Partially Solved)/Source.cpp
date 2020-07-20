// Unus Pro Omnibus, Omnus pro Uno - Alexander Dumas
// Authored by Prasanna Kumar alias prasanna2425
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define i_64 long long

void solve(int t) {
    int w, h, l, u, r, d;
    cin >> w >> h >> l >> u >> r >> d;
    double a[w + 1][h + 1];
    memset(a, 0, sizeof a);
    a[1][1] = 1.0;
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= h; j++) {
            if ((i >= l and i <= r and j >= u and j <= d) or (i == 1 and j == 1)) {
                continue;
            }
            else {
                if (i == 1) {
                    a[i][j] = a[i][j - 1] / 2;
                }
                else if (j == 1) {
                    a[i][j] = a[i - 1][j] / 2;
                }
                else if (i == w and j == h) {
                    a[i][j] = a[i - 1][j] + a[i][j - 1];
                }
                else if (i == w) {
                    a[i][j] = a[i][j - 1] + a[i - 1][j] / 2;
                }
                else if (j == h) {
                    a[i][j] = a[i - 1][j] + a[i][j - 1] / 2;
                }
                else {
                    a[i][j] = (a[i][j - 1] / 2) + (a[i - 1][j] / 2);
                }
            }
        }
    }
    /*for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= h; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }*/
    cout << setprecision(6) << fixed << "Case #" << t << ": " << (double)a[w][h] << "\n";
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