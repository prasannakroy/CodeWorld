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

void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    std::vector<int> res;
    int flag(0), one(0), two(n - 1);
    for (int i = n - 1; i >= 0; i--) {
        if (flag) {
            int x = s1[two] - '0';
            x = (x + flag) % 2;
            int y = s2[i] - '0';
            int z = s1[one] - '0';
            z = (z + flag) % 2;
            if (z == y) {
                one++;
                continue;
            }
            if (x == y) res.push_back(1);
            res.push_back(i + 1);
            two--;
            flag = 1 - flag;
        }
        else {
            if (s1[two] == s2[i]) {
                two--;
                continue;
            }
            if (s1[one] == s2[i]) res.push_back(1);
            res.push_back(i + 1);
            one++;
            flag = 1 - flag;
        }
    }
    cout << res.size() << " ";
    for (int &i: res) cout << i << " ";
    cout << "\n";
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs
  
    i_64 t(1);
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}