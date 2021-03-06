/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) a.begin(), a.end()
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    int cnt(0);
    for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
    sort(span(a));
    for (int i = 0; i < n; i++) {
        int l = 0, h = n - 1;
        while (l < h) {
            if (l == i) l++;
            else if (h == i) h--;
            else if (a[l].first + a[h].first + a[i].first > k) h--;
            else if (a[l].first + a[h].first + a[i].first < k) l++;
            else return void(cout << a[l].second + 1 << " " << a[i].second + 1 << " " << a[h].second + 1 << "\n");
        }
    }
    cout << "IMPOSSIBLE\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}