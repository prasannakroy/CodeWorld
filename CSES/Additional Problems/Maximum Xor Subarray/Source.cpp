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
 
struct node {
    bool end = 0;
    node* next[2];
};
 
node* getNode() {
    node *t = new node;
    t->end = 0;
    t->next[0] = NULL;
    t->next[1] = NULL;
    return t;
}
 
void insert(node *root, string val) {
    node *t = root;
    for (int i = 0; i < 32; i++) {
        int index = val[i] - '0';
        if (!t->next[index]) t->next[index] = getNode();
        t = t->next[index];
    }
    t->end = 1;
}
 
int search(node *root, string &s) {
    node *t = root;
    int res = 0;
    for (int i = 0; i < 32; i++) {
        int index = s[i] - '0';
        if (t->next[index ^ 1]) {
            t = t->next[index ^ 1];
            res |= (1ll << (31 - i));
        }
        else 
            t = t->next[index];
    }
    return res;
}
 
void solve() {
    int n, x;
    cin >> n;
    vector<int> a(n);
    node *tr = new node();
    for (auto &i: a) 
        cin >> i;
    bitset<32> v(0);
    insert(tr, v.to_string());
    int res(0), sum(0);
    for (int i = 0; i < n; i++) {
        sum ^= a[i];
        bitset<32> val(sum);
        string s = val.to_string();
        res = max({res, sum, search(tr, s)});
        insert(tr, s);
    }
    cout << res << "\n";
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