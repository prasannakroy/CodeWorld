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

vector<int> bit;

void add(int idx, int n, int val) {
    for (; idx < n; idx |= (idx + 1)) 
        bit[idx] += val;
}

void update(int s, int e, int n, int val) {
    add(s, n, val);
    add(e, n, -val);
}

int query(int idx) {
    int res(0);
    for (; idx >= 0; idx = (idx & (idx + 1)) - 1)
        res += bit[idx];
    return res;
}

void solve() {
    int n, m, c;
    cin >> n >> m >> c;
    bit.assign(n, 0);
    for (int i = 0; i < n; i++) 
        update(i, i + 1, n, c);
    while (m--) {
        string t;
        cin >> t;
        if (t == "Q") {
            int idx;
            cin >> idx;
            cout << query(idx - 1) << "\n";
        }
        else {
            int s, e, val;
            cin >> s >> e >> val;
            update(s - 1, e, n, val);
        }
    }
}

signed main() {
    __AcHiLlEs
  
    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
