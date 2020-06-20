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
int a[100001];
 
int gcd(int a, int b) {
    while(b) tie(a, b) = make_tuple(b, a % b);
    return a;
}
 
struct node {
    int d, cnt;
    node() : d(1), cnt(0) {}
    void join(node a, node b) {
        d = gcd(a.d, b.d);
        if (d == a.d) cnt += a.cnt;
        if (d == b.d) cnt += b.cnt;
    }
}tr[400001];
 
void build(int p, int l, int r) {
    if (l > r) return;
    if (l == r) {
        tr[p].d = a[l];
        tr[p].cnt = 1;
        return;
    }
    int m = (l + r) >> 1;
    build(p << 1, l, m);
    build((p << 1) | 1, m + 1, r);
    tr[p].join(tr[p << 1], tr[(p << 1) | 1]);
}
 
node query(int p, int l, int r, int s, int e) {
    node res;
    if (l > e or s > r or l > r) return res;
    if (s <= l and e >= r) return tr[p];
    int m = (l + r) >> 1;
    if (e <= m) return query(p << 1, l, m, s, e);
    else if (s > m) return query((p << 1) | 1, m + 1, r, s, e);
    res.join(query(p << 1, l, m, s, e), query((p << 1) | 1, m + 1, r, s, e));
    return res;
}
 
void solve() {
    int n, q, l, r;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    build(1, 0, n - 1);
    cin >> q;
    while (q--) {
        cin >> l >> r;
        cout << r - l + 1 - query(1, 0, n - 1, l - 1, r - 1).cnt << "\n";
    }
}

signed main() {
    __AcHiLlEs
  
    i_64 t(1);
    // cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
