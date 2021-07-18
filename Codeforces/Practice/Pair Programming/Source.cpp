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
  int k, n, m;
  cin >> k >> n >> m;
  vc<int> a(n), b(m);
  for (auto &i: a) 
    cin >> i;
  for (auto &i: b) 
    cin >> i;
  reverse(span(a));
  reverse(span(b));
  vc<int> res;
  while (!a.empty() or !b.empty()) {
    if (!a.empty() and a.back() <= k) {
      res.push_back(a.back());
      if (!a.back()) 
        k++;
      a.pop_back();
    }
    else if (!b.empty() and b.back() <= k) {
      res.push_back(b.back());
      if (!b.back()) 
        k++;
      b.pop_back();
    }
    else return void(cout << "-1\n");
  }
  for (auto &i: res) cout << i << " ";
  cout << "\n";
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