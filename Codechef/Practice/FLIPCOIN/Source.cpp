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

int tr[500001], lazy[500001];

void push(int p, int l, int r, int m) {
    if (lazy[p]) {
        lazy[p << 1] ^= 1;
        lazy[(p << 1) | 1] ^= 1;
        lazy[p] = 0;
        tr[p << 1] = m - l + 1 - tr[p << 1];
        tr[(p << 1) | 1] = r - m - tr[(p << 1) | 1];
    }
}

void update(int p, int l, int r, int s, int e) {
    if (l > r or l > e or s > r) return;
    if (s <= l and r <= e) {
        lazy[p] ^= 1;
        tr[p] = r - l + 1 - tr[p];
        return;
    }
    int m = (l + r) >> 1;
    push(p, l, r, m);
    update(p << 1, l, m, s, e);
    update((p << 1) | 1, m + 1, r, s, e);
    tr[p] = tr[p << 1] + tr[(p << 1) | 1];
}

int query(int p, int l, int r, int s, int e) {
    if (l > r or l > e or s > r) return 0;
    if (s <= l and r <= e) 
        return tr[p];
    int m = (l + r) >> 1;
    push(p, l, r, m);
    int res = (query(p << 1, l, m, s, e) + query((p << 1) | 1, m + 1, r, s, e));
    return res;
}

void solve() {
    int n, q;
    cin >> n >> q;
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 0) update(1, 0, n - 1, a, b);
        else cout << query(1, 0, n - 1, a, b) << "\n";
    }
}

signed main() {
    __AcHiLlEs

    i_64 t(1);
    // cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
