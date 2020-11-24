/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) a.begin(), a.end()
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)

void solve() {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first.first >> a[i].first.second, a[i].second = i;
    sort(span(a));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int ,int>>> q;
    vector<int> res(n);
    int cnt(0);
    for (int i = 0; i < n; i++) {
        if (q.empty()) {
            res[a[i].second] = cnt;
            q.push({a[i].first.second, cnt++});
            continue;
        } 
        if (q.top().first >= a[i].first.first) res[a[i].second] = cnt, q.push({a[i].first.second, cnt++});
        else res[a[i].second] = q.top().second, q.pop(), q.push({a[i].first.second, res[a[i].second]});
    }
    cout << cnt << "\n";
    for (auto &i: res) cout << i + 1 << " ";
    cout << "\n";
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