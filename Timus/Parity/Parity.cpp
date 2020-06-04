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
int dsu[MX], sze[MX], ch[MX];

void init(int n) {
    dsu[n] = n;
    sze[n] = 1;
    ch[n] = 0;
}

int root(int a) {
    if (dsu[a] != a) {
        int p = dsu[a];
        dsu[a] = root(p);
        ch[a] ^= ch[p];
    }
    return dsu[a];
}

void join(int a, int b, int r) {
    int A = root(a);
    int B = root(b);
    if (A == B) return;
    if (sze[A] < sze[B]) {
        dsu[A] = B;
        ch[A] = ch[a] ^ ch[b] ^ r;
        sze[B] += sze[A];
    }
    else {
        dsu[B] = A;
        ch[B] = ch[a] ^ ch[b] ^ r;
        sze[A] += sze[B];
    }
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    int n;
    while (cin >> n and n != -1) {
        int q, res(0), cnt(0);
        bool flag = 1;
        cin >> q;
        std::map<int, int> m;
        for (int i = 1; i <= q; i++) {
            int x, y;
            string s;
            cin >> x >> y >> s;
            if (flag) {
                if (x <= 0 or y > n or y <= 0 or x > n or x > y) flag = 0;
                else {
                    x--;
                    if (m.find(x) == m.end()) {
                        init(cnt);
                        m[x] = cnt++;
                    }
                    if (m.find(y) == m.end()) {
                        init(cnt);
                        m[y] = cnt++;
                    }
                    x = m[x];
                    y = m[y];
                    int a = root(x);
                    int b = root(y);
                    int r = (s[0] == 'e'? 0: 1);
                    if (a == b and (ch[x] ^ ch[y] ^ r)) flag = 0;
                    else join(x, y, r);
                    if (flag) res++;
                }
            }
        }
        cout << res << "\n";
    }   
    return 0;
}