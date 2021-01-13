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
#define int unsigned long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

vc<int> lst;

void precompute() {
    int cnt(1), val(9);
    while (cnt <= 18) {
        lst.push_back(val * cnt);
        val *= 10;
        cnt++;
    }
}

void solve() {
    int n;
    cin >> n;
    int sum(0), num(0), x(9);
    for (int i = 0; i < 18; i++) {
        if (sum + lst[i] < n) {
            num += x;
            x *= 10;
            sum += lst[i];
            continue;
        }
        int val = n - sum;
        int idx = val % (i + 1);
        val /= (i + 1);
        num += val;
        if (idx == 0) return void(cout << num % 10 << "\n");
        num++;
        int c = i + 1;
        while (c != idx) {
            num /= 10;
            c--;
        }
        cout << num  % 10 << "\n";
        break;
    }
}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    precompute();

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}