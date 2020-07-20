#include <bits/stdc++.h>
using namespace std;

int dp[1505][31][51];

void solve(int t){
    int n, k, mx(0), mx2(0), x(0);
    cin >> n >> k;
    int a[n];
    for (int &i: a) {
        cin >> i;
    }
    std::vector<int> dif;
    dif.push_back(0);
    for (int i = 1; i < n; i++) {
        dif.push_back(a[i] - a[i - 1]);
    }
    sort(dif.begin(), dif.end());
    cout << "Case #" << t + 1 << ": " << max((dif[n - 1] + 1)/ 2, dif[n - 2]) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, i(0);
    cin >> t;
    while (t - i) {
        solve(i);
        i++;
    }
    return 0;
}