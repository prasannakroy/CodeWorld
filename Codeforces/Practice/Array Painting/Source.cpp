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

void solve() {
    int n;
    cin >> n;
    
    vc<int> a(n);
    for (auto &i: a) 
        cin >> i;
        
    vc<array<int, 2>> lst;
    
    int mx = 0, res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (mx != 0) {
                res++;
                lst.push_back({mx, 1});
            }
            lst.push_back({0, 0});
            mx = 0;
            continue;
        }
        mx = max(mx, a[i]);
        if (i == n - 1) {
            res++;
            lst.push_back({mx, 1});
        }
    }
    n = lst.size();
    
    for (int i = 0; i < n; i++) if (!lst[i][1]) {
        if (i) {
            if (lst[i - 1][0]) 
                continue;
            if (i + 1 < n and lst[i + 1][0]) {
                lst[i + 1][0]--;
            } else {
                res++;
            }
        } else {
            if (i + 1 < n and lst[i + 1][0]) {
                lst[i + 1][0]--;
            } else {
                res++;
            }
        }
    }
    cout << res << '\n';
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1), st(0);
//   cin >> t;
  for (int i = st; i < t + st; /*cout << "Case #" << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}