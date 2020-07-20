#include<bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, t(0), res(INT_MAX), flag(0);
    cin >> x >> y;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'N') {
            y++;
        }
        else if (s[i] == 'S') {
            y--;
        }
        else if (s[i] == 'E') {
            x++;
        }
        else {
            x--;
        }
        t++;
        if (abs(x) + abs(y) <= t) {
            flag = 1;
            res = min(t, res);
        }
    }
    if (!flag) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        cout << res << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t(1);
    cin >> t;
    for (int i = 1; i <= t; cout << "Case #" << i << ": ", solve(), i++);
}