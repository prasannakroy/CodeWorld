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

const int mod = 998244353;

int root(vector<int> &p, int a) {
    return p[a] == a ? a : p[a] = root(p, p[a]);
}

void solve() {
    int n, k, res(1);
    cin >> n >> k;
    vector<int> a(n + 1, 0), b(k), idx(n + 1);
    vector<int> left(n + 1), right(n + 1);
    vector<bool> vis(n + 1, 0);
    for (int i = 0; i < n; i++) cin >> a[i], idx[a[i]] = i, left[i] = i, right[i] = i;
    left[n] = n;
    right[n] = n;
    for (int i = 0; i < k; i++) cin >> b[i], vis[b[i]] = 1;
    for (int i = 0; i < k; i++) {
        int c(0);
        int r = root(right, idx[b[i]] + 1);
        int l = root(left, idx[b[i]]);
        // cout << i << " " << l << " " << r << ":\n";
        // cout << b[i] << " " << a[l - 1] << " " << a[r] << "\n";
        if (r < n) { 
            right[idx[b[i]]] = r;
            // cout << a[r] << " " << vis[a[r]] << "\n";
            if (!vis[a[r]]) c++;
        }
        if (l) {
            left[idx[b[i]]] = l;
            // cout << a[l - 1] << " " << vis[a[l - 1]] << "\n";
            if (!vis[a[l - 1]]) c++;
        }
        vis[b[i]] = 0;
        // cout << c << "\n";
        (res *= c) %= mod;
        if (!res) break;
    }
    cout << res << "\n";
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case #" << i << ": ",*/ solve(), i++);
    return 0;
}