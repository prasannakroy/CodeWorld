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

void solve() {
    int n;
    cin >> n;
    vc<int> a(n), sum(n + 1, 0);
    for (auto &i: a) cin >> i;
    for (int i = 0; i < n; i++) {
        if (a[i] == n) {
            sum[0] += -1;
            continue;
        }
        int idx = i - a[i] + 1;
        if (idx < 0) {
            sum[0] += -1;
            sum[i + 1] += 1;
            idx += n;
            sum[idx] += -1;
        }
        else {
            sum[idx] += -1;
            sum[i + 1] += 1;
        }
    }
    int mx(sum[0]), res(0);
    for (int i = 1; i < n; i++) {
        sum[i] += sum[i - 1];
        if (sum[i] > mx) mx = sum[i], res = i;
    }
    cout << res + 1 << "\n";
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