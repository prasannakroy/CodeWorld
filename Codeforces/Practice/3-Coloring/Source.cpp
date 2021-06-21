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

void solve() {
  int n, a, b;
  cin >> n;
  int cnt = n * n;
  int c[3]{};
  int row[3] = {0, 1, 1};
  int col[3] = {0, 1, 2};
  vc<vc<int>> mat(n + 1, vc<int>(n + 1));
  while (cnt--) {
    cin >> a;
    if (a == 1) {
      if (c[2] == (n * n) / 2) b = 3;
      else b = 2;
    }
    else if (a == 2) {
      if (c[1] == ((n * n) + 1) / 2) b = 3;
      else b = 1;
    }
    else {
      if (c[2] < c[1]) b = 2;
      else b = 1;
    }
    int idx;
    if (b == 3) {
      if (c[2] < c[1]) idx = 2;
      else idx = 1;
    }
    else idx = b;
    cout << b << " " << row[idx] << " " << col[idx] << endl;
    mat[row[idx]][col[idx]] = b;
    c[idx]++;
    col[idx] += 2;
    if (col[idx] > n) {
      row[idx]++;
      if (row[idx] & 1) col[idx] = idx;
      else col[idx] = 3 - idx;
    }
  }
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1);
  // cin >> t;
  for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}