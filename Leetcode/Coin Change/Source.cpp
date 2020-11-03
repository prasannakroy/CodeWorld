class Solution {
public:
    int coinChange(vector<int>& coins, int val) {
        int dp[val + 1];
        int m = coins.size();
        dp[0] = 0;  
        for (int i = 1; i <= val; i++) 
            dp[i] = INT_MAX; 
        for (int i = 1; i <= val; i++) {  
            for (int j = 0; j < m; j++) {
                if (coins[j] > i) continue;
                int res = dp[i - coins[j]]; 
                if (res != INT_MAX and res + 1 < dp[i]) 
                    dp[i] = res + 1; 
            }
        } 
        if (dp[val] == INT_MAX) return -1;
        return dp[val]; 
    }
};