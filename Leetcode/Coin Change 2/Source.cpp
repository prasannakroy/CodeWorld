class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (!amount) return 1;
        if (coins.empty()) return 0;
        int n = coins.size();
        vector<vector<int>> dp(amount + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; i++) dp[0][i] = 1;
        
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] += (coins[j] <= i ? dp[i - coins[j]][j] : 0);
                dp[i][j] += (j >= 1 ? dp[i][j - 1] : 0);
            }
        }
        return dp[amount][n - 1];
    }
};