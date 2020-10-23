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
    string s;
    cin >> s;
    stack<char> st;
    for (auto &i: s) {
        if (st.empty()) st.push(i);
        else {
            string x("");
            x += st.top();
            x += i;
            if (x == "AB" or x == "BB") st.pop();
            else st.push(i);
        }
    }
    cout << st.size() << "\n";
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