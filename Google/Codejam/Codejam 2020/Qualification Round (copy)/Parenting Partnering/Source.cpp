#include<bits/stdc++.h>
using namespace std;

bool sortp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.first.first == b.first.first? a.first.second < b.first.second: a.first.first < b.first.first;
}

int solve(int t) {
    int n, cf(0), jf(0), x, y;
    cin >> n;
    std::vector<pair<pair<int, int>, int>> v;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({{x, y}, i});
    }
    sort(v.begin(), v.end(), sortp);
    char res[n];
    bool flag(0);
    for (int i = 0; i < n; i++) {
        if (v[i].first.first >= cf) {
            res[v[i].second] = 'C';
            cf = v[i].first.second;
        }
        else if (v[i].first.first >= jf) {
            res[v[i].second] = 'J';
            jf = v[i].first.second;
        }
        else {
            flag = 1;
            break;
        }
    }
    if (flag) {
        cout << "Case #" << t + 1 << ": IMPOSSIBLE\n";
        return 0;
    }
    cout << "Case #" << t + 1 << ": ";
    for (int i = 0; i < n; i++) {
        cout << res[i];
    }
    cout << "\n";
    return 0;
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
    return 0;
}