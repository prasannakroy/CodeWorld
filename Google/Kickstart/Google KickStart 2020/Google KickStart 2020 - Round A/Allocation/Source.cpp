#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    int n, k, sum(0), count(0);
    cin >> n >> k;
    int a[n];
    for (int &i : a) cin >> i;
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        sum += a[i];
        count++;
        if (sum > k) {
            count--;
            break;
        }
    }
    cout << "Case #" << t + 1 << ": " << count << endl;
}

int main() {
    int t, i(0);
    cin >> t;
    while (t - i) {
        solve(i);
        i++;
    }
    return 0;
}