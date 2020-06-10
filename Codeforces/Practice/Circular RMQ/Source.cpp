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

i_64 a[200001], tr[1000001], lazy[1000001];

void push(i_64 p) {
    tr[p << 1] += lazy[p];
    lazy[p << 1] += lazy[p];
    tr[(p << 1) | 1] += lazy[p];
    lazy[(p << 1) | 1] += lazy[p];
    lazy[p] = 0;
}

void build(i_64 p, i_64 l, i_64 r) {
    if (l > r) return;
    if (l == r) {
        tr[p] = a[l];
        return;
    }
    i_64 m = (l + r) >> 1;
    build(p << 1, l, m);
    build((p << 1) | 1, m + 1, r);
    tr[p] = min(tr[p << 1], tr[(p << 1) | 1]);
}

void update(i_64 p, i_64 l, i_64 r, i_64 s, i_64 e, i_64 val) {
    if (s > r or l > e or l > r or s > e) return;
    if (s <= l and e >= r) {
        tr[p] += val;
        lazy[p] += val;
        return;
    } 
    push(p);
    i_64 m = (l + r) >> 1;
    update(p << 1, l, m, s, min(e, m), val);
    update((p << 1) | 1, m + 1, r, max(s, m + 1), e, val);
    tr[p] = min(tr[p << 1], tr[(p << 1) | 1]);
}

i_64 query(i_64 p, i_64 l, i_64 r, i_64 s, i_64 e) {
    if (s > r or l > e or l > r) return LLONG_MAX;
    if (s <= l and r <= e)
        return tr[p];
    push(p);
    i_64 m = (l + r) >> 1;
    return min(query(p << 1, l, m, s, min(e, m)), query((p << 1) | 1, m + 1, r, max(s, m + 1), e));
}

void solve() {
    memset(tr, 0, sizeof tr);
    memset(lazy, 0, sizeof lazy);
    i_64 n;
    cin >> n;
    for (i_64 i = 0; i < n; i++) cin >> a[i];
    build(1, 0, n - 1);
    i_64 q;
    cin >> q;
    string s;
    getline(cin, s);
    while (q--) {
        getline(cin, s);
        istringstream ss(s);
        vector <i_64> v;
        i_64 x;
        while(ss >> x) v.push_back(x);
        if (v.size() == 2) {
            if (v[0] > v[1]) {
                i_64 x = query(1, 0, n - 1, 0, v[1]);
                i_64 y = query(1, 0, n - 1, v[0], n - 1);
                cout << min(x, y) << endl;
            }
            else cout << query(1, 0, n - 1, v[0], v[1]) << endl;
        }
        else {
            if (v[0] > v[1]) {
                update(1, 0, n - 1, 0, v[1], v[2]);
                update(1, 0, n - 1, v[0], n - 1, v[2]);
            }
            else update(1, 0, n - 1, v[0], v[1], v[2]);
        }
    }
}

signed main() {
    __AcHiLlEs

    i_64 t(1);
    // cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
