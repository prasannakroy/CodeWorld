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


void solve() {
    int w, n, res(LLONG_MAX);
    cin >> w >> n;
    vector<int> a(w);
    for (auto &i: a) cin >> i;
    sort(a.begin(), a.end());
    vector<int> sum(w + 1);
    sum[0] = 0;
    for (int i = 1; i <= w; i++) sum[i] = a[i - 1] + sum[i - 1];
    for (int i = 0; i < w; i++) {
        int cost(0);
        int l = max(a[i] - (n / 2), a[0]);
        int r = min(a[i] + (n / 2), a[w - 1]);
        int il = lower_bound(a.begin(), a.end(), l) - a.begin();
        int ir = upper_bound(a.begin(), a.end(), r) - a.begin() - 1;
        int ll = il;
        int rr = w - ir - 1;
        int sm = sum[i] - sum[il];
        int len = i - il; 
        cost += ((len * a[i]) - sm);
        len = ir - i;
        sm = sum[ir + 1] - sum[i + 1];
        cost += (sm - (len * a[i]));
        if (ll) {
            sm = sum[ll];
            cost += (((n - a[i]) * ll) + sm);
        }
        if (rr) {
            sm = sum[w] - sum[w - rr];
            cost += (((n + a[i]) * rr) - sm);
        }
        res = min(res, cost);
    }
    cout << res << "\n";
}

signed main() {

    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; cout << "Case #" << i << ": ", solve(), i++);
    return 0;
}