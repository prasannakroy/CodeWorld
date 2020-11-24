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
    vector<int> a(n);
    vector<array<int, 3>> v;
    for (auto &i: a) cin >> i;
    for (int i = 0; i < n; i++) 
        for (int j = i + 1; j < n; j++) {
            array<int, 3> x = {a[i] + a[j], i, j};
            v.push_back(x);
        }
    sort(span(v), [&](array<int, 3> x, array<int, 3> y){
        return x[0] < y[0];
    });
    int l = 0, r = v.size() - 1;
    while (l < r) {
        if (v[l][0] + v[r][0] > k) r--;
        else if (v[l][0] + v[r][0] < k) l++;
        else {
            set<int> s;
            s.insert(v[l][1]);
            s.insert(v[l][2]);
            s.insert(v[r][1]);
            s.insert(v[r][2]);
            if (s.size() < 4) l++;
            else return void(cout << v[l][1] + 1 << " " << v[l][2] + 1 << " " << v[r][1] + 1 << " " << v[r][2] + 1 << "\n");
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