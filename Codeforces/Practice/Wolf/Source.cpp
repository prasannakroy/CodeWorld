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

mt19937_64 mersenne {static_cast<mt19937_64::result_type>(time(NULL))};

int randInt(int l, int r) {return uniform_int_distribution<int>(l, r)(mersenne);}

void solve(int t) {
  int n, q;
  cin >> n >> q;

  vector<int> a(n + 1), idx(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    idx[a[i]] = i;
  }

  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;
    if (idx[k] < l or idx[k] > r) {
      cout << -1 << ' ';
      continue;
    }
    int extGt(0), extSm(0), totalGt(0), totalSm(0);

    while (l <= r) {
      int m = (l + r) / 2;
      if (idx[k] < m) {
        if (a[m] < k) 
          extGt += 1;
        totalGt += 1;
        r = m - 1;
      } else if (idx[k] > m) {
        if (a[m] > k) 
          extSm += 1;
        totalSm += 1;
        l = m + 1;
      } else 
        break;
    }
    if (totalSm >= k or totalGt > (n - k))
      cout << -1 << ' ';
    else {
      int dif = abs(extGt - extSm);
      cout << extGt + extSm + dif << ' ';
    }
  }
  cout << '\n';
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1), st(0);
  cin >> t;
  for (int i = st; i < t + st; /*cout << "Case #" << i << ": ",*/ solve(i + 1), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}