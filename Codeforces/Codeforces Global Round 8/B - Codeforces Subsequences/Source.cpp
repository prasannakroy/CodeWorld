#include<bits/stdc++.h>
using namespace std;

#define i_64 long long

void solve() {
    i_64 k;
    cin >> k;
    if (k == 1) {
        cout << "codeforces\n";
        return;
    }
    string r = "codeforces";
    i_64 val = 1;
    i_64 i = 0;
    std::vector<i_64> a(10, 1);
    while(val < k){
        i %= 10;
        val /= a[i];
        a[i] += 1;
        val *= a[i];
        i++;
    }
    for(i_64 i = 0; i < 10; i++){
        for(i_64 j = 0; j < a[i]; j++){
            cout << r[i];
        }
    }
    cout << "\n";
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    i_64 t(1);
    
    // cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}