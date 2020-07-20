#include<bits/stdc++.h>
using namespace std;

void solve(int t) {
    int n, trace(0), r(0), c(0);
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (i == j) {
                trace += a[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        std::map<int, int> m;
        for (int j = 0; j < n; j++) {
            if (m[a[i][j]] == 1) {
                r++;
                break;
            }
            m[a[i][j]] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        std::map<int, int> m;
        for (int j = 0; j < n; j++) {
            if (m[a[j][i]] == 1) {
                c++;
                break;
            }
            m[a[j][i]] = 1;
        }
    }
    cout << "Case #" << t + 1 << ": " << trace << " " << r << " " << c << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    int i(0);
    while (t - i) {
        solve(i);
        i++;
    }
}
