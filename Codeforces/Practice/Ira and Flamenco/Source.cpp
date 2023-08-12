// Author : Prasanna Kumar
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

template<typename t>
using minpq = priority_queue<t, vc<t>, greater<t>>;

template<typename t>
using maxpq = priority_queue<t>;

const int mod = 1e9 + 7;

int power(int a, int b) {
    int res(1);
    while (b) {
        if (b & 1) {
            (res *= a) %= mod;
        } 
        (a *= a) %= mod;
        b >>= 1;
    }
    return res;
}

int invMod(int a) {
    return power(a, mod - 2);
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    vc<int> a;
    
    map<int, int> mp;
    
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        mp[x]++;
    }
    
    for (auto &[x, y]: mp) 
        a.push_back(x);
    
    n = a.size();
    int l = 0, r = 0;
    int res(0), prod(1);
    while (l < n and r < n) {
        while (l < n and a[r] - a[l] >= m) {
            (prod *= invMod(mp[a[l]])) %= mod;
            l++;
        }
        (prod *= mp[a[r]]) %= mod;
        if (r + 1 - l == m) 
            (res += prod) %= mod;
        r++;
    }
    cout << res << '\n';
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1), st(0);
  cin >> t;
  for (int i = st; i < t + st; /*cout << "Case #" << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}