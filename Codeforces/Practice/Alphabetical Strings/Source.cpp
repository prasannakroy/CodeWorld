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
  string s;
  cin >> s;
  int n = s.length();
  int idx[26]{};
  for (int i = 0; i < n; i++) {
    if (idx[s[i] - 'a']) 
      return void(cout << "NO\n");
    if (s[i] - 'a' >= n) 
      return void(cout << "NO\n");
    idx[s[i] - 'a'] = i + 1;
  }
  int l = idx[0];
  int r = idx[0];
  sort(span(s));
  int c(0);
  for (int i = 1; i < 26; i++) {
    if (idx[i] == 0) 
      break;
    if (idx[i] == l - 1) 
      l--;
    else if (idx[i] == r + 1) 
      r++;
    else 
      return void(cout << "NO\n");
  }
  cout << "YES\n";
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