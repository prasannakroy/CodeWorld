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

struct Trie {
    bool ed;
    Trie *next[2];
    Trie() {
        ed = 0;
        next[0] = next[1] = NULL;
    } 

    void insert(string s) {
        int n = s.length();
        Trie *t = this;
        for (int i = 0; i < n; i++) {
            int idx = s[i] - '0';
            if (!t->next[idx]) t->next[idx] = new Trie();
            t = t->next[idx];
        }
    }
    int find(string s) {
        int n = s.length();
        Trie *t = this;
        int res(0);
        for (int i = 0; i < n; i++) {
            int idx = s[i] - '0';
            if (t->next[idx ^ 1]) res |= (1 << (31 - i)), t = t->next[idx ^ 1];
            else t = t->next[idx];
        }
        return res;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vc<int> a(n);
    for (auto &i: a) cin >> i;
    Trie *tr = new Trie();
    bitset<32> x(0);
    tr->insert(x.to_string());
    int sum(0), res(0);
    for (int i = 0; i < n; i++) {
        sum ^= (a[i] ^ k);
        bitset<32> val(sum);
        bitset<32> val2(sum ^ k);
        res = max({res, sum, tr->find(val.to_string())});
        tr->insert(val2.to_string());
        sum ^= k;
    }
    cout << (res ^ k) << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}