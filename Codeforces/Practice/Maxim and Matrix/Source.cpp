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

const int sz = 50;

int nCr[sz][sz];

void precompute() {
  nCr[0][0] = 1;
  for (int i = 1; i < sz; i++) {
    for (int j = 0; j <= i; j++) {
      nCr[i][j] = nCr[i - 1][j];
      if (j) 
        nCr[i][j] += nCr[i - 1][j - 1];
    }
  }
}

void solve() {
  int n, t;
  cin >> n >> t;
  n++;
  if (t & (t - 1)) 
    return void(cout << "0\n");
  int l = log2(t);
  l++;
  int res(0);
  for (int i = 49; i >= 0; i--) if ((1ll << i) & n) {
    res += nCr[i][l];
    l--;
    if (l < 0) 
      break;
  }
  if (l == 0) 
    res++;
  if (t == 1) 
    res--;
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