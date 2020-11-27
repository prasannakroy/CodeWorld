class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& a) {
        vector<int> gph[n];
        int degree[n];
        memset(degree, 0, sizeof degree);
        for (auto &i: a) gph[i[1]].push_back(i[0]), degree[i[0]]++;
        int sz(0);
        queue<int> q;
        for (int i = 0; i < n; i++) if (!degree[i]) q.push(i);
        if (q.empty()) return 0;
        for (int i = 0; i < n; i++) {
            if (q.empty()) return 0;
            int u = q.front();
            q.pop();
            for (auto &v: gph[u]) {
                degree[v] -= 1;
                if (!degree[v]) q.push(v);
            }
        }
        return 1;
    }
};