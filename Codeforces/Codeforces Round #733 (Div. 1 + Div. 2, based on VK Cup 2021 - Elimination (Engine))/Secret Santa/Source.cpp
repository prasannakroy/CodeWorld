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
  int n;
  cin >> n;
  vc<int> a(n);
  map<int, int> m;
  for (auto &i: a) {
    cin >> i;
    m[i]++;
  }
  cout << m.size() << "\n";
  vc<int> vis(n + 1, 0), res(n, 0);
  vc<int> idx;
  for (int i = 0; i < n; i++) {
    if (!vis[a[i]]) {
      res[i] = a[i];
      vis[a[i]] = 1;
    }
    else 
      idx.push_back(i + 1);
  }
  vc<int> rm;
  for (int i = 1; i <= n; i++) if (!vis[i]) 
    rm.push_back(i);
  reverse(span(rm));

  int flag = 0;
  reverse(span(idx));
  while (!rm.empty()) {
    int x = idx.back();
    idx.pop_back();
    int y = rm.back();
    rm.pop_back();
    if (x == y) {
      if (rm.size() == 0) {
        rm.push_back(y);
        idx.push_back(x);
        flag = 1;
        break;
      }
      int z = rm.back();
      rm.pop_back();
      rm.push_back(y);
      y = z;
    }
    res[x - 1] = y;
  }

  if (flag == 1) {
    for (int i = 0; i < n; i++) if (res[i] == a[idx[0] - 1]) {
      res[i] = rm[0];
      res[idx[0] - 1] = a[idx[0] - 1];
      break;
    }
  }

  for (auto &i: res) 
    cout << i << " ";
  cout << "\n";
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t;
  cin >> t;
  for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}