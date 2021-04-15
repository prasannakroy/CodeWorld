class Solution {
public:
    string longestPalindrome(string &s) {
        int n = s.size();
        int res = 0, st = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 1, l, r;
            for (l = i - 1, r = i + 1; l >= 0 and r < n; --l, ++r) {
                if (s[l] != s[r]) break;
                cnt += 2;
            }
            if (cnt > res) res = cnt, st = l + 1;
            cnt = 0;
            for (l = i, r = i + 1; l >= 0 and r < n; --l, ++r) {
                if (s[l] != s[r]) break;
                cnt += 2;
            }
            if (cnt > res) res = cnt, st = l + 1;
        }
        return s.substr(st, res);
    }
};