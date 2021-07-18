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
  int x[3], y[3];
  for (int i = 0; i < 3; i++) 
    cin >> x[i] >> y[i];

  int ext(0);
  if (x[1] == x[2] and x[0] == x[1]) {
    if (y[0] > y[1]) swap(y[0], y[1]);
    if (y[0] < y[2] and y[2] < y[1]) 
      ext += 2;
  }
  else if (y[1] == y[2] and y[0] == y[1]) {
    if (x[0] > x[1]) swap(x[0], x[1]);
    if (x[0] < x[2] and x[2] < x[1]) 
      ext += 2;
  }

  cout << abs(x[0] - x[1]) + abs(y[0] - y[1]) + ext << "\n";
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