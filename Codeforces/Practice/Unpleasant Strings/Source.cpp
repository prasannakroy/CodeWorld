// Author : Prasanna Kumar
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

template<typename t>
using minpq = priority_queue<t, vc<t>, greater<t>>;

template<typename t>
using maxpq = priority_queue<t>;

mt19937_64 mersenne {static_cast<mt19937_64::result_type>(time(NULL))};

int randInt(int l, int r) {return uniform_int_distribution<int>(l, r)(mersenne);}

void solve(int t) {
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  vector<vector<int>> aux(n, vector<int>(k, n));
  vector<int> res(n + 1, 0);
  vector<int> firstIdx(k, n);

  for (int i = n - 1; i >= 0; i--) {
    firstIdx[s[i] - 'a'] = i;
    if (i + 1 < n) {
      aux[i] = aux[i + 1];
      aux[i][s[i + 1] - 'a'] = i + 1;
    }
    int rs = 0;
    for (auto &j: aux[i]) 
      rs = max(rs, j);
    res[i] = res[rs] + 1;
  }

  int q;
  cin >> q;
  while (q--) {
    string t;
    cin >> t;
    int m = t.length();
    int i = firstIdx[t[0] - 'a'];
    int j = 0;
    while (i < n) {
      if (s[i] != t[j]) 
        break;
      j += 1;
      if (j == m)
        break;
      i = aux[i][t[j] - 'a'];
    }
    if (j != m) 
      cout << 0 << '\n';
    else
      cout << res[i] << '\n';
  }
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1), st(0);
  // cin >> t;
  for (int i = st; i < t + st; /*cout << "Case #" << i << ": ",*/ solve(st + 1), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}