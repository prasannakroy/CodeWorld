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

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  sort(span(s));
  int cnt[26]{};
  int mx = 1;
  for (auto &i: s) 
    cnt[i - 'a']++;
  string res("");
  for (int i = 0; i < 26; i++) {
    if (cnt[i] == 1) {
      cnt[i]--;
      res += (char)(i + 'a');
      mx = 0;
      break;
    }
  }
  if (mx == 0) {
    for (int i = 0; i < 26; i++) {
      while (cnt[i] != 0) {
        res += (char)(i + 'a');
        cnt[i]--;
      }
    }
    return void(cout << res << "\n");
  }
  int len = n - cnt[s[0] - 'a'];
  if (len == 0) 
    return void(cout << s << "\n");
  int rm = cnt[s[0] - 'a'] % (len + 1);
  mx = cnt[s[0] - 'a'] / (len + 1);
  if (rm > 1) mx++;
  if (mx > 1) {
    res += s[0];
    cnt[s[0] - 'a']--;
    for (int i = 0; i < 26; i++) if (cnt[i] and i != s[0] - 'a') {
      cnt[i]--;
      res += (char)(i + 'a');
      break;
    }

    bool f = 0;

    char rs;
    for (int i = 0; i < 26; i++) if (cnt[i] and res[1] - 'a' < i) {
      rs = (char)(i + 'a');
      cnt[i]--;
      f = 1;
      break;
    }

    if (f == 0 and cnt[res[1] - 'a'] > 0) { 
      while (cnt[res[1] - 'a'] > 0) {
        res += res[1];
        cnt[res[1] - 'a']--;
      }
    }
    
    while (cnt[s[0] - 'a'] > 0) {
      res += s[0]; 
      cnt[s[0] - 'a']--;
    }
    if (f == 1) res += rs;

    for (int i = 0; i < 26; i++) if (cnt[i]) {
      char x = i + 'a';
      while (cnt[i]--) 
        res += x;
    }
  }
  else {
    minpq<array<int, 2>> q;
    for (int i = 0; i < 26; i++) if (cnt[i] and i != s[0] - 'a') 
      q.push({i, cnt[i]});
    for (int i = 0; i <= mx; i++) {
      res += s[0];
      cnt[s[0] - 'a']--;
      if (cnt[s[0] - 'a'] == 0) 
        break;
    }
    while (cnt[s[0] - 'a'] != 0) {
      if (!q.empty()) {
        auto t = q.top();
        q.pop();
        char x = t[0] + 'a';
        t[1]--;
        if (t[1] > 0) q.push(t);
        res += x;
      }
      for (int i = 0; i < mx; i++) {
        res += s[0];
        cnt[s[0] - 'a']--;
        if (cnt[s[0] - 'a'] == 0) break;
      }
    }
    while (!q.empty()) {
      auto t = q.top();
      q.pop();
      char x = t[0] + 'a';
      for (int i = 0; i < t[1]; i++) 
        res += x;
    }
  }
  cout << res << "\n";
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