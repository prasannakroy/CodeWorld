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
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

const int mx = 100001;
vc<int> vis(mx, 0);
vc<int> prime;

int closestPrimed(int n) {
  bool flag = 0;
  while (!flag) {
    flag = 1;
    for (int i = 2; i * i <= n; i++) if (n % i == 0) {
      flag = 0;
      break;
    }
    if (flag) break;
    n--;
  }
  return n;
}

int closestPrimeu(int n) {
  bool flag = 0;
  while (!flag) {
    flag = 1;
    for (int i = 2; i * i <= n; i++) if (n % i == 0) {
      flag = 0;
      break;
    }
    if (flag) break;
    n++;
  }
  return n;
}

void solve() {
  int n, res(0);
  cin >> n;
  int val = sqrtl(n);
  int b = closestPrimed(val);
  int a = closestPrimed(b - 1);
  int c = closestPrimeu(val + 1);
  if (b * c <= n) cout << b * c << "\n";
  else cout << a * b << "\n";
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1);
  cin >> t;
  for (int i = 1; i <= t; cout << "Case #" << i << ": ", solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}