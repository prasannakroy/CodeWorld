/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include <bits/stdc++.h> 
using namespace std; 

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define i_64 long long

int cnt[26][131075];
string s;

int check(int l, int r, char x) {
    if (l > r) return INT_MAX;
    if (l == r) {
        return (s[l] != x);
    }
    int m = (l + r) >> 1;
    char y = x;
    y++;
    int res1 = check(l, m, y) + r - m - cnt[x - 'a'][r] + cnt[x - 'a'][m + 1] - (s[m + 1] == x);
    int res2 = check(m + 1, r, y) + m - l + 1 - cnt[x - 'a'][m] + cnt[x - 'a'][l] - (s[l] == x);
    return min(res1, res2);
} 

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < 26; j++) cnt[j][i] = 0;
    s.clear();
    cin >> s;
    cnt[s[0] - 'a'][0]++;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 26; j++) cnt[j][i] = cnt[j][i - 1] + (s[i] == 'a' + j);
    }
    int res = check(0, n - 1, 'a');
    cout << res << "\n";
}

signed main() {
    __AcHiLlEs
  
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case #" << i << ": ",*/ solve(), i++);
    return 0;
}
