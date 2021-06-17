/*****************************
*  Author :: Πρασαννα Κ. Ροι *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

int mx;
vector<int> bit[2];

void update(int idx, int t) {
  for (; idx < mx; idx |= (idx + 1)) bit[t][idx]++;
}

int query(int t, int r, int l = 0) {
  if (l) 
    return query(t, r) - query(t, l - 1);
  int sum(0);
  for (; r >= 0; r = (r & (r + 1)) - 1) sum += bit[t][r];
  return sum;
}

void solve() {
  int n;
  cin >> n;
  vc<array<int, 3>> a(n);
  vector<int> lst;
  for (int i = 0; i < n; a[i - 1][2] = i++) {
    cin >> a[i][0] >> a[i][1];
    lst.push_back(a[i][0]);
    lst.push_back(a[i][1]);
  }

  sort(span(lst));
  
  int cnt(1);
  map<int, int> m;
  for (auto &i: lst) if (!m[i]) 
    m[i] = cnt++;
  bit[0].assign(cnt, 0);
  bit[1].assign(cnt, 0);
  mx = cnt;
  
  for (auto &i: a) i[0] = m[i[0]], i[1] = m[i[1]];
  
  sort(span(a), [&](array<int, 3> x, array<int, 3> y) {
    return x[1] == y[1] ? x[0] < y[0] : x[1] > y[1];
  });
  
  auto b = a;
  vc<int> res1(n, 0), res2(n, 0);
  
  for (int i = n - 1; i >= 0; i--) {
    res1[a[i][2]] = query(0, cnt - 1, a[i][0]);
    update(a[i][0], 0);
  }

  for (int i = 0; i < n; i++) {
    res2[b[i][2]] = query(1, b[i][0]);
    update(b[i][0], 1);
  }
  
  for (int i = 0; i < n; i++) cout << res1[i] << " ";
  cout << "\n";
  for (int i = 0; i < n; i++) cout << res2[i] << " ";
  cout << "\n";
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