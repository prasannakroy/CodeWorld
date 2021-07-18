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

template<typename t>
using minpq = priority_queue<t, vc<t>, greater<t>>;

int getSize(int a) {
  return (a - (a / 4));
}

int adjust(minpq<int> &q, int &sz) {
  int sum(0);
  while (q.size() > getSize(sz)) {
    sum += q.top();
    q.pop();
  }
  return sum;
}

void solve() {
  int n;
  cin >> n;
  minpq<int> a;
  int suma(0), sumb(0);
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    a.push(x);
    suma += x;
  }
  vc<int> b(n);
  for (auto &i: b) 
    cin >> i;
  sort(span(b), greater<int>());

  for (int i = 1; i < n; i++) b[i] += b[i - 1];
  int sz = n;
  suma -= adjust(a, sz);
  while (suma < b[getSize(sz) - 1]) {
    a.push(100);
    suma += 100;
    b.push_back(0);
    b[sz] += b[sz - 1];
    sz++;
    suma -= adjust(a, sz);
  }
  cout << sz - n << "\n";
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