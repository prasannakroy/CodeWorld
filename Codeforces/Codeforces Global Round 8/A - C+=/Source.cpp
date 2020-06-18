#include<bits/stdc++.h>
using namespace std;

#define i_64 long long

void solve() {
    i_64 a, b, n, cnt(0);
    cin >> a >> b >> n;
    while (max(a, b) <= n) {
        tie(a, b) = make_tuple(min(a, b), max(a, b));
        a += b;
        cnt++;
    }
    cout << cnt << "\n";
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    i_64 t(1);
    
    cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}