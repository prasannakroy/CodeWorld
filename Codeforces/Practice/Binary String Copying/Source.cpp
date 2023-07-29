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
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vc<array<int, 2>> a(m);

    for (auto &i: a) {
        cin >> i[0] >> i[1];
        i[0]--;
        i[1]--;
    }

    vc<array<int, 3>> lst;

    int c(1);
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) 
            c++;
        else {
            lst.push_back({i - 1, i - c, s[i - 1] - '0'});
            c = 1;
        }
        if (i == n - 1) 
            lst.push_back({i, n - c, s[i] - '0'});
    }

    if (n == 1) 
        lst.push_back({0, 0, 1});

    map<array<int, 2>, int> mp;

    function<int(int)> lowerBound = [&](int val) {
        int l = -1, r = lst.size() - 1;

        while (r - l > 1) {
            int mid = (r + l) / 2;

            if (lst[mid][0] >= val) 
                r = mid;
            else 
                l = mid;
        }
        return r;

    };

    int res(0), orgStr(0);
    for (int i = 0; i < m; i++) {
        int idx1 = lowerBound(a[i][0]);
        int idx2 = lowerBound(a[i][1]);
        // cout << a[i][0] << ' ' << a[i][1] << ' ' << idx1 << ' ' << idx2 << '\n';
        if (idx1 == idx2) {
            orgStr = 1;
            continue;
        } 
        if (idx2 - idx1 == 1 and lst[idx1][2] == 0 and lst[idx2][2] == 1) {
            orgStr = 1;
            continue;
        }

        int lidx(a[i][0]), ridx(a[i][1]);

        if (lst[idx1][2] == 0) {
            lidx = lst[idx1][1];
        } else if (lst[idx1][2] == 1 and a[i][0] == lst[idx1][1] and a[i][0]) {
            idx1 = lowerBound(a[i][0] - 1);
            lidx = lst[idx1][1];
        }
        if (lst[idx2][2] == 1) {
            ridx = lst[idx2][0];
        } else if (lst[idx2][2] == 0 and a[i][1] == lst[idx2][0] and a[i][1] < n - 1) {
            idx2 = lowerBound(a[i][1] + 1);
            ridx = lst[idx2][0];
        }
        mp[{lidx, ridx}] = 1;

    }

    res += orgStr;
    for (auto &[x, y]: mp) {
        res += y;
    }

    cout << res << '\n';

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