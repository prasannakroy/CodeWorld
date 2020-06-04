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

const int MX = 100001;
int dsu[MX], sze[MX], tp[MX];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        dsu[i] = i;
        sze[i] = 1;
        tp[i] = 0;
    }
}

int root(int a) {
    if (dsu[a] != a) {
        int p = dsu[a];
        dsu[a] = root(p);
        (tp[a] += tp[p]) %= 3;
    }
    return dsu[a];
}

void solve() {
    int n, k, res(0);
    cin >> n >> k;
    init(n);
    while (k--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (x > n or y > n) {
            res++;
            continue;
        }
        int a = root(x);
        int b = root(y);
        t--;
        if (a == b) {
            int aux = (((tp[x] - tp[y]) % 3) + 3) % 3;
            if (aux != t) res++;
        }
        else {
            dsu[a] = b;
            int aux = (tp[x] - tp[y] - t) % 3;
            if (aux < 0) 
                tp[a] = -aux;
            else 
                tp[a] = -aux + 3;
        }
    }
    cout << res << "\n";
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    i_64 t(1);
    cin >> t;
    for (int i = 1; i <= t; solve(), i++);
    return 0;
}
