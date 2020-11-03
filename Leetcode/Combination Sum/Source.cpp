class Solution {
public:
    
    void solve(vector<int> &v, vector<vector<int>> &res, int val, vector<int> &a, int idx, int n) {
        if (val == 0) {
            res.push_back(a);
            return;
        }
        if (val < 0 or idx == n) return;
        a.push_back(v[idx]);
        solve(v, res, val - v[idx], a, idx, n);
        a.pop_back();
        solve(v, res, val, a, idx + 1, n);
    }
    
    vector<vector<int>> combinationSum(vector<int>& v, int val) {
        int n = v.size();
        vector<vector<int>> res;
        vector<int> a;
        solve(v, res, val, a, 0, n);
        return res;
    }
};