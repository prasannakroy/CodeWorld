/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define i_64 long long

i_64 h[200005], rec[2][200005];
i_64 tr[3][800005], avd[3][200005];
std::vector<i_64> ign[2][200005];

void make(i_64 n, i_64 t) {
    for (i_64 i = 0; i < n; i++) {
        if (ign[t][i].empty()) avd[t][i] = 0;
        else 
            for (i_64 &j: ign[t][i]) avd[t][i] += avd[2][j];
    }
}

void build(i_64 p, i_64 l, i_64 r, i_64 t) {
    if (l > r) return;
    if (l == r) {
        tr[t][p] = avd[t][l];
        return;
    }
    i_64 m = (l + r) >> 1;
    build(p << 1, l, m, t);
    build((p << 1) | 1, m + 1, r, t);
    tr[t][p] = tr[t][p << 1] + tr[t][(p << 1) | 1];
}

void update(i_64 p, i_64 l, i_64 r, i_64 ind, i_64 val, i_64 t) {
    if (l > r or ind < l or ind > r) return;
    if (l == r and l == ind) {
        tr[t][p] = val;
        return;
    }
    i_64 m = (l + r) >> 1;
    if (ind <= m) update(p << 1, l, m, ind, val, t);
    else update((p << 1) | 1, m + 1, r, ind, val, t);
    tr[t][p] = tr[t][p << 1] + tr[t][(p << 1) | 1];
}

i_64 query(i_64 p, i_64 l, i_64 r, i_64 s, i_64 e, i_64 t) {
    if (l > e or s > r or l > r) return 0;
    if (s <= l and e >= r) return tr[t][p];
    i_64 m = (l + r) >> 1;
    if (e <= m) return query(p << 1, l, m, s, e, t);
    else if (l > m) return query((p << 1) | 1, m + 1, r, s, e, t);
    else return (query(p << 1, l, m, s, e, t) + query((p << 1) | 1, m + 1, r, s, e, t));
}

void solve() {
    i_64 n, q;
    cin >> n >> q;
    for (i_64 i = 0; i <= n; i++) rec[0][i] = 200001, rec[1][i] = -1;
    for (i_64 i = 0; i < n; i++) cin >> h[i];
    for (i_64 i = 0; i < n; i++) cin >> avd[2][i];
    i_64 prev = 0;
    stack<i_64> s;
    for (i_64 i = 1; i < n; i++) {
        s.push(i - 1);
        if (h[i] < h[i - 1]) 
            continue;
        while (!s.empty() and h[s.top()] <= h[i]) {
            ign[0][i].push_back(s.top());
            rec[0][s.top()] = i;
            s.pop();
        }
    }
    while (!s.empty()) s.pop();
    for (i_64 i = n - 2; i >= 0; i--) {
        s.push(i + 1);
        if (h[i] < h[i + 1]) 
            continue;
        while (!s.empty() and h[s.top()] <= h[i]) ign[1][i].push_back(s.top()), rec[1][s.top()] = i, s.pop();
    }
    make(n, 0);
    make(n, 1);
    build(1, 0, n - 1, 0);
    build(1, 0, n - 1, 1);
    build(1, 0, n - 1, 2);
    while (q--) {
        i_64 t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            x--;
            i_64 m1 = rec[0][x], m2 = rec[1][x], val;
            if (m1 != -1) {
                val = avd[0][m1] - avd[2][x] + y;
                avd[0][m1] = val;
                update(1, 0, n - 1, m1, val, 0);
            }
            if (m2 != 200001) {
                val = avd[1][m2] - avd[2][x] + y;
                avd[1][m2] = val;
                update(1, 0, n - 1, m2, val, 1);
            }
            avd[2][x] = y;
            update(1, 0, n - 1, x, y, 2);
        }
        else {
            x--, y--;
            if (x < y) {
                if (rec[0][x] <= y) cout << -1 << "\n";
                else {
                    i_64 s1 = query(1, 0, n - 1, x, y, 2);
                    i_64 s2 = query(1, 0, n - 1, x + 1, y, 0);
                    cout << s1 - s2 << "\n";
                }
            }
            else if (x > y) {
                if (rec[1][x] >= y) cout << -1 << "\n";
                else {
                    i_64 s1 = query(1, 0, n - 1, y, x, 2);
                    i_64 s2 = query(1, 0, n - 1, y, x - 1, 1);
                    cout << s1 - s2 << "\n";
                }
            }
            else cout << avd[2][x] << "\n";
        }
    }
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs
  
    i_64 t(1);
    // cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
