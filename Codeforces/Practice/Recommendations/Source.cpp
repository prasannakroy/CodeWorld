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
  vc<array<int, 2>> a(n);
  for (auto &i: a) 
    cin >> i[0];
  for (auto &i: a) 
    cin >> i[1];
  sort(span(a));

  vc<int> dif(n, 0);
  for (int i = 1; i < n; i++) 
    dif[i] = a[i][0] - a[i - 1][0];

  vc<int> lst[n + 1];
  for (int i = 0; i < n; i++) {
    int val = a[i][0];
    
    if (i) 
      a[i][0] = min(a[i - 1][0] + dif[i], i + 1);
    else 
      a[i][0] = 1;
    lst[a[i][0]].push_back(a[i][1]);

    while (i + 1 < n and a[i + 1][0] == val) {
      i++;
      a[i][0] = a[i - 1][0];
      lst[a[i][0]].push_back(a[i][1]);
    }
  }

  multiset<int> cur;
  int sum = 0, res = 0;
  for (int i = 1; i <= n; i++) {
    for (auto &j: lst[i]) {
      cur.insert(j);
      sum += j;
    }
    if (!cur.empty()) {
      sum -= (*cur.rbegin());
      cur.erase(--cur.end());
    }
    res += sum;
  }

  cout << res << "\n";
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1);
  for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}