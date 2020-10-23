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


void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int &i: a) cin >> i;
    int r(1), c(1), flag(0), res(1), c3(0);
    vector<pair<int, int>> v;
    vector<bool> check(n, 0);
    stack<int> st2;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;
        if (flag == 2) {
            if (r > n) {
                res = 0;
                break;
            }
            v.push_back({r++, i + 1});
            if (r > n) {
                res = 0;
                break;
            }
            v.push_back({r, i + 1});
            if (a[i] == 3) c3++;
            else if (a[i] == 2) st2.push(r++);
            else r++;
            c3--;
        }
        else if (a[i] == 1) {
            if (!st2.empty()) {
                if (st2.top() > n) {
                    res = 0;
                    break;
                }
                v.push_back({st2.top(), i + 1});
                st2.pop();
            }
            else {
                check[i] = 0;
                if (r > n) {
                    res = 0;
                    break;
                }
                v.push_back({r++, i + 1});
            }
        }
        else if (a[i] == 2) {
            st2.push(r);
            v.push_back({r++, i + 1});
        }
        else 
            c3++, v.push_back({r, i + 1});
        flag = a[i] - 1;
    }
    if (c3 or st2.size()) res = 0;
    if (!res) {
        cout << -1 << "\n";
        return;
    } 
    else {
        cout << v.size() << "\n";
        for (auto &i: v) cout << i.first << " " << i.second << "\n";
    }
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case #" << i << ": ",*/ solve(), i++);
    return 0;
}