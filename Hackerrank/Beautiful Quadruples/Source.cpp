#include<bits/stdc++.h>
using namespace std;
#define int long long

int beautifulQuadruples(int a, int b, int c, int d) {
    long long res = 0;
    vector<int> lst = {a, b, c, d};
    sort(begin(lst), end(lst));
    
    vector<array<int, 2>> xr1, xr2;
    for (int i = 1; i <= lst[0]; i += 1) {
        for (int j = i; j <= lst[1]; j += 1) {
            xr1.push_back({j, i ^ j});
        }
    }
    map<int, int> mp;
    for (int i = 1; i <= lst[2]; i += 1) {
        for (int j = i; j <= lst[3]; j += 1) {
            xr2.push_back({i, i ^ j});
            mp[i ^ j] += 1;
        }
    }
    
    sort(begin(xr1), end(xr1));
    sort(begin(xr2), end(xr2));
    
    int n = xr1.size();
    int m = xr2.size();
    for (int i = 0, j = 0; i < n; i += 1) {
        while (j < m and xr2[j][0] < xr1[i][0])
            j += 1;
        res += (m - j);
    }
    
    for (int i = 0, j = 0; i < n; i += 1) {
        while (j < m and xr2[j][0] < xr1[i][0]) {
            mp[xr2[j][1]] -= 1;
            j += 1;
        }
        res -= mp[xr1[i][1]];
    }
    
    return res;
}

void solve(int t) {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  cout << beautifulQuadruples(a, b, c, d) << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t(1), cnt(1);
  // cin >> t;
  while (t--) solve(cnt++);
    return 0;
}