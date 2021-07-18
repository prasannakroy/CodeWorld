/*****************************
*  Author :: Πρασαννα Κ. Ροι *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

const int sz = 1e7 + 1;

vc<int> sieve(sz);

void precompute() {
  iota(span(sieve), 0);

  for (int i = 4; i < sz; i += 2) sieve[i] = 2;
  for (int i = 9; i < sz; i += 6) sieve[i] = 3;
  for (int i = 5; i * i < sz; i += 4) {
    if (sieve[i] == i) 
      for (int j = i * i; j < sz; j += (2 * i)) 
        if (sieve[j] == j) 
          sieve[j] = i;
    i += 2;
    if (sieve[i] == i) 
      for (int j = i * i; j < sz; j += (2 * i)) 
        if (sieve[j] == j) 
          sieve[j] = i;
  }
}

void solve() {
  int n, k;
  cin >> n >> k;

  vc<int> a(n);
  for (auto &i: a) cin >> i;

  for (int i = 0; i < n; i++) {
    int val = a[i];
    a[i] = 1;
    while (val > 1) {
      int c(0);
      int x = sieve[val];
      while (sieve[val] == x) val /= x, c++;
      if (c & 1) a[i] *= x;
    }
  }
  vc<vc<int>> left(n, vc<int>(k + 1));
  for (int j = 0; j <= k; j++) {
    int cnt(0);
    unordered_map<int, int> m;
    for (int l = 0, r = 0; r < n; r++) {
      if (m[a[r]] >= 1) 
        cnt++;
      m[a[r]]++;
      while (cnt > j) {
        m[a[l]]--;
        if (m[a[l]]) cnt--;
        l++;
      }
      left[r][j] = l;
    }
  }
  vc<vc<int>> dp(n + 1, vc<int>(k + 1, INT_MAX));
  for (auto &i: dp[0]) i = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      if (j > 0) dp[i][j] = dp[i][j - 1];
      for (int c = 0; c <= j; c++) 
        dp[i][j] = min(dp[i][j], dp[left[i - 1][c]][j - c] + 1);
    }
  }
  int res(INT_MAX);
  for (auto &i: dp[n]) res = min(res, i);
  cout << res << "\n";
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  precompute();

  int t(1);
  cin >> t;
  for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}