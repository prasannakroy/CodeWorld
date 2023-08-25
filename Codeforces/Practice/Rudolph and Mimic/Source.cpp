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
    map<int, vc<int>> prevMp, curMp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        prevMp[a[i]].push_back(i);
    }
    
    int res = -1, cnt(0);
    while (true) {
        if (cnt == 5) 
            break;
        cnt++;
        vc<int> lst;
        curMp.clear();
        for (int i = 0; i < a.size(); i++) 
            curMp[a[i]].push_back(i);

        int val = -1;
        for (auto &[x, y]: curMp) {
            if (y.size() > prevMp[x].size()) {
                val = x;
                break;
            }
        }
        if (val != -1) {
            if (prevMp[val].size() == 0) {
                cout << "! " << curMp[val][0] + 1 << endl;
                break;
            }
            for (auto &[x, y]: curMp) if (x != val) {
                for (auto &i: y) 
                    lst.push_back(i + 1);
            }
        }
        if (lst.size() == a.size()) 
            lst.clear();
        for (auto &i: lst) if (curMp.count(a[i - 1]))
            curMp.erase(a[i - 1]);
        prevMp = curMp;
        cout << "- " << lst.size() << ' ';
        for (auto &i: lst) 
            cout << i << ' ';
        cout << endl;
        n -= lst.size();
        a.resize(n);
        for (auto &i: a) 
            cin >> i;
    }
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1), st(0);
  cin >> t;
  for (int i = st; i < t + st; /*cout << "Case #" << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}