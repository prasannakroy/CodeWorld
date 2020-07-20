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

i_64 tr1[800001], tr2[800001];
i_64 a[200001];

void build1(int p, int s, int e) {
    if (s > e) {
        return;
    }
    if (s == e) {
        i_64 c = 1;
        if (s & 1) {
            c = -1;
        }
        tr1[p] = c * a[s];
        return;
    }
    i_64 m = (s + e) >> 1;
    build1(p << 1, s, m);
    build1((p << 1) | 1, m + 1, e);
    tr1[p] = tr1[p << 1] + tr1[(p << 1) | 1];
}

void build2(int p, int s, int e) {
    if (s > e) {
        return;
    }
    if (s == e) {
        i_64 c = 1;
        if (s & 1) {
            c = -1;
        }
        tr2[p] = c * a[s] * (s + 1);
        return;
    }
    i_64 m = (s + e) >> 1;
    build2(p << 1, s, m);
    build2((p << 1) | 1, m + 1, e);
    tr2[p] = tr2[p << 1] + tr2[(p << 1) | 1];
}

void update1(int p, int s, int e, int l, i_64 val) {
    if (l > e or l < s or s > e) {
        return;
    }
    if (s == e and l == s) {
        i_64 c = 1;
        if (s & 1) {
            c = -1;
        }
        tr1[p] = c * val;
        return;
    }
    i_64 m = (s + e) >> 1;
    if (l <= m) {
        update1(p << 1, s, m, l, val);
    }
    else {
        update1((p << 1) | 1, m + 1, e, l, val);
    }
    tr1[p] = tr1[p << 1] + tr1[(p << 1) | 1];
}

void update2(int p, int s, int e, int l, i_64 val) {
    if (l > e or l < s or s > e) {
        return;
    }
    if (s == e and l == s) {
        i_64 c = 1;
        if (s & 1) {
            c = -1;
        }
        tr2[p] = c * val * (s + 1);
        return;
    }
    i_64 m = (s + e) >> 1;
    if (l <= m) {
        update2(p << 1, s, m, l, val);
    }
    else {
        update2((p << 1) | 1, m + 1, e, l, val);
    }
    tr2[p] = tr2[p << 1] + tr2[(p << 1) | 1];
}

i_64 query1(int p, int s, int e, int l, int u) {
    if (l > e or s > u) {
        return 0;
    }
    if (l <= s and u >= e) {
        return tr1[p];
    }
    i_64 m = (s + e) >> 1;
    if (e <= m) {
        return query1(p << 1, s, m, l, u);
    }
    if (s > m) {
        return query1((p << 1) | 1, m + 1, e, l, u);
    }
    return (query1(p << 1, s, m, l, u) + query1((p << 1) | 1, m + 1, e, l, u));
}

i_64 query2(int p, int s, int e, int l, int u) {
    if (l > e or s > u) {
        return 0;
    }
    if (l <= s and u >= e) {
        return tr2[p];
    }
    i_64 m = (s + e) >> 1;
    if (e <= m) {
        return query2(p << 1, s, m, l, u);
    }
    if (s > m) {
        return query2((p << 1) | 1, m + 1, e, l, u);
    }
    return (query2(p << 1, s, m, l, u) + query2((p << 1) | 1, m + 1, e, l, u));
}

void solve() {
    memset(tr1, 0 ,sizeof tr1);
    memset(tr2, 0, sizeof tr2);
    i_64 n, q, cnt(0);
    cin >> n >> q;
    for (i_64 i = 0; i < n; i++) {
        cin >> a[i];
    }
    build1(1, 0, n - 1);
    build2(1, 0, n - 1);
    i_64 res(0);
    while (q--) {
        char x;
        cin >> x;
        if (x == 'U') {
            int l;
            i_64 u;
            cin >> l >> u;
            update1(1, 0, n - 1, l - 1, u);
            update2(1, 0, n - 1, l - 1, u);
        }
        else {
            int l, u;
            cin >> l >> u;
            i_64 r1 = query1(1, 0, n - 1, l - 1, u - 1);
            i_64 r2 = query2(1, 0, n - 1, l - 1, u - 1);
            i_64 cc = l - 1, r = -1;
            if (l & 1) {
                r = 1;
            }
            r2 -= (r1 * cc);
            r2 *= r;
            res += r2;
        }
    }
    cout << res << "\n";
}

int main() {
    // auto start=chrono::steady_clock::now();
    // #ifndef ONLINE_JUDGE 
    //     __AnAkLuSmOs
    // #endif

    __AcHiLlEs

    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; cout << "Case #" << i << ": ", solve(), i++);
    // auto end = chrono::steady_clock::now();
    // double elapsed = double (chrono::duration_cast < chrono::nanoseconds> (end-start).count());
    // cout << endl << "Terminated\n"<< elapsed/1e9;
    return 0;
}

