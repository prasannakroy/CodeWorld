#include<bits/stdc++.h>
using namespace std;

void solve(int t) {
    string s;
    cin >> s;
    int n = s.length();
    string res("");
    int oc(0), op(0);
    for (int i = 0; i < n; i++) {
        int a = s[i] - '0';
        while (op - oc > a) {
            res += ')';
            oc++;
        }
        while (op - oc < a) {
            res += '(';
            op++;
        }
        if (op - oc == 0) {
            op = 0;
            oc = 0;
        }
        res += s[i];
    }
    while (op - oc != 0) {
        res += ')';
        oc++;
    }
    cout << "Case #" << t + 1 << ": " << res << "\n";
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