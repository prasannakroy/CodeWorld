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

void solve() {
    int n;
    cin >> n;

    map<int, int> mp;

    vc<int> a(n);
    for (auto &i: a) {
        cin >> i;
        mp[i]++;
    }

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int b = x;
        int c = y;
        int val = (b * b) - (4 * c);
        if (val < 0) {
            cout << 0 << ' ';
            continue;
        }
        int sqrtVal = sqrtl(val);
        // cout << b << ' ' << c << ' ' << val << ' ' << sqrtVal << '\n';
        if (sqrtVal * sqrtVal != val) {
            cout << 0 << ' ';
            continue;
        }
        int r1 = b - sqrtVal;
        int r2 = b + sqrtVal;
        if ((r1 & 1) or (r2 & 1)) {
            cout << 0 << ' ';
            continue;
        }
        r1 /= 2;
        r2 /= 2;
        // cout << r1 << ' ' << r2 << '\n';
        if (r1 == r2) {
            int c = mp[r1];
            cout << (c * (c - 1)) / 2 << ' ';
        } else {
            cout << mp[r1] * mp[r2] << ' ';
        }
    }
    cout << '\n';
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