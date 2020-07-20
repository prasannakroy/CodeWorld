// Unus Pro Omnibus, Omnus pro Uno - Alexander Dumas
// Authored by Prasanna Kumar alias prasanna2425
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define i_64 long long

struct bot {
    char x;
    i_64 n, s, e, w;
    bot() {
        n = s = e = w = 0;
    }
};

void solve(int t) {
    string S;
    cin >> S;
    i_64 N = S.length();
    bot a[N];
    for (int i = 0; i < N; i++) {
        a[i].x = S[i];
        if (S[i] == 'N') {
            a[i].n++;
        }
        else if (S[i] == 'S') {
            a[i].s++;
        }
        else if (S[i] == 'E') {
            a[i].e++;
        }
        else if (S[i] == 'W') {
            a[i].w++;
        }
    }
    i_64 i = 0;
    std::stack<bot> st;
    while (i < N) {
        if (a[i].x != ')') {
            st.push(a[i]);
        }
        else {
            std::map<char, int> m;
            bot r;
            while (st.top().x != '(') {
                r.n += st.top().n;
                r.s += st.top().s;
                r.e += st.top().e;
                r.w += st.top().w;
                st.pop();
            }
            st.pop();
            i_64 x = st.top().x - '0';
            st.pop();
            (r.n = x * r.n) %= 1000000000;
            (r.s = x * r.s) %= 1000000000;
            (r.e = x * r.e) %= 1000000000;
            (r.w = x * r.w) %= 1000000000;
            st.push(r);
        }
        i++;
    }
    bot res;
    while (!st.empty()) {
        (res.n += st.top().n) %= 1000000000;
        (res.s += st.top().s) %= 1000000000;
        (res.e += st.top().e) %= 1000000000;
        (res.w += st.top().w) %= 1000000000;
        st.pop();
    }
    res.e -= res.w;
    res.s -= res.n;
    i_64 X, Y;
    if (res.e < 0) {
        X = (i_64)1000000001 + res.e;
    }
    else {
        X = res.e + 1;
    }
    if (res.s < 0) {
        Y = (i_64)1000000001 + res.s;
    }
    else {
        Y = res.s + 1;
    }
    cout << "Case #" << t << ": " << X << " " << Y << "\n";
}

int main() {
   __AcHiLlEs
    int t(1), i(1);
    cin >> t;
    while (t--) {
        solve(i);
        i++;
    }
    return 0;
}