/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define i_64 long long

void solve() {
    i_64 n, k, sum(0);
    cin >> n >> k;
    std::vector<int> a(n), b(n);
    for (int &i: a)cin >> i, sum += i;
    for (int &i: b)cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    int i = 0;
    while (a[i] < b[i] and i < k) {
        sum -= a[i];
        sum += b[i];
        i++;
    }
    cout << sum << "\n";
}

signed main() {
    __AcHiLlEs

    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
