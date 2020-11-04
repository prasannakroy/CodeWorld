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
#define int long long
#define span(v) v.begin(), v.end()
#define sum(n) (((int)n * (int)(n + 1)) >> 1ll)
#define sumr(l, r) (sum(r) - sum(l))

vector<int> fact(16);

void solve() {
    int n, q, cnt(0);
    cin >> n >> q;
    int len = min(n, 15ll);
    vector<int> v(len), a(n);
    vector<bool> vis;
    iota(span(a), n - len + 1);
    iota(span(v), n - len + 1);

    function<int(int)> kmax = [&] (int k) {
        priority_queue<pair<int, int>> q;
        int sz(0);
        for (int i = 0; i < len; i++) {
            if (vis[i]) continue;
            if (sz < k) q.push({a[i], i}), sz++;
            else q.push({a[i], i}), q.pop();
        }
        return q.top().second;
    };

    function<void(int)> update = [&] (int cnt) {
        vis.assign(len, 0);
        for (int i = len - 1; i >= 0; i--) {
            int q = cnt / fact[i];
            cnt = cnt % fact[i];
            int idx = kmax(q + 1);
            v[len - i - 1] = a[idx];
            vis[idx] = 1;
        }
    };


    while (q--) {
        int t;
        cin >> t;
        if (t - 1) {
            int x;
            cin >> x;
            cnt += x;
            update(cnt);
        }
        else {
            int l, r;
            cin >> l >> r;
            int s1(0), s2(0);
            if (n <= 15) {
                l--, r--;
                for (int i = l; i <= r; i++) s1 += v[i];
            }
            else {
                int s = max(0ll, len - n + l - 1);
                int e = r + len - n;
                r = min(a[0] - 1, r);
                l--;
                if (l < r) s1 = sumr(l, r); 
                for (; s < e; s++) s2 += v[s];
            }
            cout << s1 + s2 << "\n";
        }
    }
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    fact[0] = 1;
    for (int i = 1; i < 16; i++) fact[i] = fact[i - 1] * i;

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}