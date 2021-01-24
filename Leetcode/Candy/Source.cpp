class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), sum(0);
        int res[n];
        for (int i = 0; i < n; i++) {
            res[i] = 1;
            if (i > 0 and ratings[i - 1] < ratings[i]) res[i] = res[i - 1] + 1;
            sum += res[i];
        }
        for (int i = n - 1; i >= 0; i--) 
            if (i + 1 < n and ratings[i + 1] < ratings[i] and res[i] <= res[i + 1]) {
                sum -= res[i];
                res[i] = res[i + 1] + 1;
                sum += res[i];
            }
        return sum;
    }
};