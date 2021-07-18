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
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

const int mx = 2e5 + 1;
const int mod = 998244353;

int fact[mx], invFact[mx];

int power(int a, int b) {
  int res(1);
  while (b) {
    if (b & 1) (res *= a) %= mod;
    (a *= a) %= mod;
    b >>= 1;
  }
  return res;
}

int invMod(int a) {
  return power(a, mod - 2);
}

void precompute() {
  fact[0] = 1;
  invFact[0] = 1;
  for (int i = 1; i < mx; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
    invFact[i] = invMod(fact[i]);
  }
}

int nCr(int n, int r) {
  return (((fact[n] * invFact[r]) % mod) * invFact[n - r]) % mod;
}

void solve() {
  int n, m;
  cin >> n >> m;
  if (n <= 2) return void(cout << "0\n");
  int res(0);
  for (int j = n - 1; j <= m; j++) {
    int r = nCr(j - 1, n - 2);
    (r *= (n - 2)) %= mod;
    (r *= power(2, n - 3)) %= mod;
    (res += r) %= mod;
  }
  cout << res << "\n";
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  precompute();

  int t(1);
  // cin >> t;
  for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}