/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define i_64 unsigned long long

i_64 lazy[500001], tr[500001];

void update(int p, int l, int r, int s, int e, i_64 val) {
    if (lazy[p]) {
        tr[p] += lazy[p] * (r - l + 1);
        if (l != r) {
            lazy[p << 1] += lazy[p];
            lazy[(p << 1) | 1] += lazy[p];
        }
        lazy[p] = 0;
    }
    if (s > r or l > e or l > r) return;
    if (s <= l and e >= r) {
        tr[p] += val * (r - l + 1);
        if (l != r) {
            lazy[p << 1] += val;
            lazy[(p << 1) | 1] += val;
        }
        return;
    }
    int m = (l + r) >> 1;
    update(p << 1, l, m, s, e, val);
    update((p << 1) | 1, m + 1, r, s, e, val);
    tr[p] = tr[p << 1] + tr[(p << 1) | 1];
}

i_64 query(int p, int l, int r, int s, int e) {
    if (lazy[p]) {
        tr[p] += lazy[p] * (r - l + 1);
        if (l != r) {
            lazy[p << 1] += lazy[p];
            lazy[(p << 1) | 1] += lazy[p];
        }
        lazy[p] = 0;
    }
    if (s > r or l > e or l > r) return 0;
    if (s <= l and e >= r) {
        return tr[p];
    }
    int m = (l + r) >> 1;
    return (query(p << 1, l, m, s, e) + query((p << 1) | 1, m + 1, r, s, e));
}

void solve() {
    memset(tr, 0, sizeof tr);
    memset(lazy, 0, sizeof lazy);
    int n, c;
    cin >> n >> c;
    while (c--) {
        int t;
        cin >> t;
        if (t) {
            int p, q;
            cin >> p >> q;
            cout << query(1, 0, n - 1, p - 1, q - 1) << "\n";
        }
        else {
            int p, q; 
            i_64 k;
            cin >> p >> q >> k;
            update(1, 0, n - 1, p - 1, q - 1, k);
        }
    }
}

signed main() {
    __AcHiLlEs

    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
