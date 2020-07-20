#include <bits/stdc++.h>
using namespace std;

int dp[1505][31][51];
int maxCost(vector<vector<int>> &v, int p, int i, int j, int k){
    if(p <= 0) {
        return 0;
    }
    if(i >= v.size()) {
        return 0;
    }
    if(dp[p][j][i] != -1) {
        return dp[p][j][i];
    }
    if(j < v[0].size() - 1) {
        dp[p][j][i] = max(dp[p][j][i], maxCost(v, p, i, j + 1, k));
    } 
    if(j + 1 <= p) {
        dp[p][j][i] = max(dp[p][j][i], maxCost(v, p - j - 1, i + 1, 0, 0) + v[i][j]);
    }
    dp[p][j][i] = max(dp[p][j][i], maxCost(v, p, i + 1, 0, k));
    return dp[p][j][i];
}
void solve(int t){
    int n, k, p; 
    cin >> n >> k >> p;
    memset(dp, -1, sizeof(dp));
    vector<vector<int>> v(n);
    for(int i(0); i < n; i++) {
        std::vector<int> r(k);
        for(int j(0); j < k ; j++){
            cin >> r[j];
            if(j > 0) {
                r[j] += r[j-1];
            }
        }
        v[i] = r;
    }
    cout << "Case #" << t + 1 << ": " << maxCost(v, p, 0, 0, 0) << "\n";

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