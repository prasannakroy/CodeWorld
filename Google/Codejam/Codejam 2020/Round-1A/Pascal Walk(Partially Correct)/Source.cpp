#include<bits/stdc++.h>
using namespace std;
#define i_64 long long
const i_64 mod = (i_64)1e9 + 7;

i_64 power(i_64 x, i_64 y) { 
    if (y == 0) 
        return 1; 
    i_64 p = power(x, y / 2) % mod; 
    p = (p * p) % mod; 
    if (!(y & 1)) 
        return p;
    return (p * x) % mod; 
} 

i_64 Imod(i_64 a) { 
    i_64 res = (power(a, mod - 2)) % mod;
    return res;
}

i_64 nCr(i_64 n, i_64 r) { 
    vector<i_64> v(r + 1);
    i_64 c(1);
    v[0] = c;
    for(i_64 j = 1; j <= r; j++){
        i_64 l = Imod(j);
        v[j] = (((c * (n - j + 1)) % mod )* l) % mod;
        c = v[j];
    }
    return v[r]; 
}

void solve(int t) {
    int n;
    cin >> n;
    int r = 1, c = 1;
    vector<pair<int, int>> res;
    res.push_back({r, c});
    n -= 1;
    while (nCr(r, c) <= n) {
        n -= nCr(r, c);
        res.push_back({r + 1, c + 1});
        r++;
    }
    while (n--) {
        res.push_back({r, 1});
        r++;
    }
    cout << "Case #" << t << ": \n";
    for (auto &i: res) {
        cout << i.first << " " << i.second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    int i = 1;
    while (t - i >= 0) {
        solve(i);
        i++;
    }
    return 0;
}