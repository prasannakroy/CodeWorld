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

vc<int> a, tr;

void build(int p, int l, int r) {
  if (l > r) return;
  if (l == r) {
    tr[p] = a[l];
    return;
  }

  int m = (l + r) >> 1;
  build(p << 1, l, m);
  build((p << 1) | 1, m + 1, r);
  tr[p] = gcd(tr[p << 1], tr[(p << 1) | 1]);
}

int query(int p, int l, int r, int s, int e) {
  if (s > r or l > e or l > r) return 0;
  if (s <= l and e >= r) return tr[p];

  int m = (l + r) >> 1;
  return gcd(query(p << 1, l, m, s, e), query((p << 1) | 1, m + 1, r, s, e));
}

void solve() {
  int n;
  cin >> n;
  a.assign(n, 0);
  int d = 0;
  for (auto &i: a) {
    cin >> i;
    d = gcd(d, i);
  }
  for (int i = 0; i < n; i++) 
    a.push_back(a[i]);

  tr.assign(8 * n + 1, 0);
  build(1, 0, (2 * n) - 1);


  int l = 0, r = 0, res = 0;
  for (int i = 0; i < n; i++) {
    int p = query(1, 0, (2 * n) - 1, l, r);
    while (r + 1 < 2 * n and p != d) {
      r++;
      p = gcd(p, a[r]);
    }
    res = max(res, r - l + 1);
    l++;
  }
  cout << res - 1 << "\n";
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