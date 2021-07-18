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

int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, 1, -1, -1};

void solve() {
  int n, m;
  cin >> n >> m;
  int a[n][m];
  memset(a, 0, sizeof a);
  for (int i = 0; i < n; i += 2) {
    for (int j = 0; j < m; j++) {
      if (i > 0 and j > 0 and j < m - 1) 
        continue;
      int flag = 1;
      for (int k = 0; k < 8; k++) {
        int tx = i + dx[k];
        int ty = j + dy[k];
        if (tx >= 0 and tx < n and ty >= 0 and ty < m and a[tx][ty]) {
          flag = 0;
          break;
        }
      }
      a[i][j] = flag;
    }
  }

  for (int j = 0; j < m; j++) {
    int i = n - 1;
    int flag = 1;
    for (int k = 0; k < 8; k++) {
      int tx = i + dx[k];
      int ty = j + dy[k];
      if (tx >= 0 and tx < n and ty >= 0 and ty < m and a[tx][ty]) {
        flag = 0;
        break;
      }
    }
    a[i][j] = flag;
  }

  for (auto &i: a) {
    for (auto &j: i) 
      cout << j;
    cout << "\n";
  }
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