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
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

const int mx = 5000001;

int cnt[mx], sieve[mx], pr[mx];

int factorize(int val) {
  int cnt = 0;
  for (; val > 1; val /= sieve[val]) 
    cnt += 1;
  return cnt;
}

void preCompute() {
  for (int i = 1; i < mx; i++) 
    sieve[i] = i;
  for (int i = 4; i < mx; i += 2) 
    sieve[i] = 2;
  for (int i = 3; i < mx / i; i += 2) 
    if (sieve[i] == i) 
      for (int j = i * i; j < mx; j += i + i) 
        sieve[j] = i;
  pr[1] = 0;
  cnt[1] = 0;
  for (int i = 2; i < mx; i++) {
    pr[i] = pr[i / sieve[i]] + 1;
    cnt[i] = cnt[i - 1] + pr[i];
  }
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  preCompute();
  int t, a, b;
  cin >> t;
  while (t > 0) {
    cin >> a >> b;
    cout << cnt[a] - cnt[b] << '\n';
    t--;
  }
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}