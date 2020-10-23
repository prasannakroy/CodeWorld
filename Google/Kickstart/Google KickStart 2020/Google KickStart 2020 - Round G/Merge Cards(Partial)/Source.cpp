/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long

long double res, cnt;

void compute(vector<int> &a, int sz, int cost) {
    if (sz == 2) {
        res += a[0] + a[1] + cost;
        cnt++;
        return;
    }
    vector<int> v(sz - 1);
    for (int i = 0; i < sz - 1; i++) {
        int sum = a[i] + a[i + 1];
        v[i] = sum;
        for (int j = 0; j < i; j++) v[j] = a[j];
        for (int j = i + 1; j < sz - 1; j++) v[j] = a[j + 1];
        compute(v, sz - 1, cost + sum);
    }
}

void solve() {
    res = 0;
    cnt = 0;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    compute(a, n, 0);
    cout << fixed << setprecision(7) << res / cnt << "\n";
}

signed main() {

    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; cout << "Case #" << i << ": ", solve(), i++);
    return 0;
}