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
#define i_64 unsigned long long

std::vector<int> v;
int n, k;
string s;

bool check(int m) {
    if (m == 1) {
        int cnt1(0), cnt2(0);
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                cnt1 += (s[i] == '0');
                cnt2 += (s[i] == '1');
            }
            else {
                cnt1 += (s[i] == '1');
                cnt2 += (s[i] == '0');
            }
        }
        return min(cnt1, cnt2) <= k;
    }
    int cnt(0);
    for (int &i: v) 
        cnt += (i / (m + 1));
    return cnt <= k;
}

void solve() {
    cin >> n >> k;
    cin >> s;
    v.clear();
    int cnt(1), res = n;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) v.push_back(cnt), cnt = 0;
        cnt++;
        res = max(res, cnt);
    }
    v.push_back(cnt);
    int l = 1, r = n;
    while (r - l >= 1) {
        int m = (l + r) >> 1;
        if (check(m)) {
            r = m;
            res = m;
        }
        else l = m + 1;
    }
    cout << res << "\n";
}

signed main() {
    // auto start=chrono::steady_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto end = chrono::steady_clock::now();
    // double elapsed = double (chrono::duration_cast < chrono::nanoseconds> (end-start).count());
    // cout << endl << "Terminated\n"<< elapsed/1e9;
    return 0;
}
    