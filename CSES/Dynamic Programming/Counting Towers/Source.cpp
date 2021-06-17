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

using mat = vc<vc<int>>;

const int mod = 1e9 + 7;

mat id = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

mat matrixMultiply(mat &a, mat &b, int l, int m, int n) {
  mat res = b;
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < n; j++) {
      res[i][j] = 0;
      for (int k = 0; k < m; k++) 
        (res[i][j] += (a[i][k] * b[k][j]) % mod) %= mod;
    }
  }
  return move(res);
}

mat power(mat a, int b) {
  mat res = id;
  while (b) {
    if (b & 1) res = matrixMultiply(res, a, 3, 3, 3);
    a = matrixMultiply(a, a, 3, 3, 3);
    b /= 2;
  }
  return move(res);
}

void solve() {
  int n;
  cin >> n;
  mat a = {{4, 1, 0}, {0, 0, 1}, {4, 1, 2}};
  mat b = {{1}, {1}, {3}};
  a = power(a, n - 1);
  b = matrixMultiply(a, b, 3, 3, 1);
  cout << (b[0][0] + b[1][0]) % mod << "\n";
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1);
  cin >> t;
  for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}