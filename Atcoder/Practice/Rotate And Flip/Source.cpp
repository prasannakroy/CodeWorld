/*****************************
*  Author :: Πρασαννα Κ. Ροι  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

vc<vc<int>> rclock = {{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}};
vc<vc<int>> cclock = {{0, -1, 0}, {1, 0, 0}, {0, 0, 1}};

auto matMultiply(vc<vc<int>> &a, vc<vc<int>> &b, int x, int y, int z) {
    vc<vc<int>> res(x, vc<int>(z, 0));
    for (int i = 0; i < x; i++) 
        for (int j = 0; j < z; j++) 
            for (int k = 0; k < y; k++) 
                res[i][j] += (a[i][k] * b[k][j]);
    return move(res);
}

void solve() {
    int n, x, y;
    cin >> n;
    vc<array<int, 2>> a(n);
    for (auto &i: a) cin >> i[0] >> i[1];
    int m;
    cin >> m;
    vc<vc<vc<int>>> b;
    vc<vc<int>> mat = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    for (int i = 0; i < m; i++) {
        cin >> x;
        if (x == 1) {
            mat = matMultiply(rclock, mat, 3, 3, 3);
            b.push_back(mat);
        }
        else if (x == 2) {
            mat = matMultiply(cclock, mat, 3, 3, 3);
            b.push_back(mat);
        }
        else {
            cin >> y;
            if (x == 3) {
                vc<vc<int>> r = {{-1, 0, 2 * y}, {0, 1, 0}, {0, 0, 1}};
                mat = matMultiply(r, mat, 3, 3, 3);
                b.push_back(mat);
            }
            else {
                vc<vc<int>> r = {{1, 0, 0}, {0, -1, 2 * y}, {0, 0, 1}};
                mat = matMultiply(r, mat, 3, 3, 3);
                b.push_back(mat);
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        cin >> x >> y;
        x--;
        vc<vc<int>> r = {{a[y - 1][0]}, {a[y - 1][1]}, {1}};
        if (~x) r = matMultiply(b[x], r, 3, 3, 1);
        cout << r[0][0] << " " << r[1][0] << "\n";
    }
}

signed main() {
    // auto start = high_resolution_clock::now();

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}