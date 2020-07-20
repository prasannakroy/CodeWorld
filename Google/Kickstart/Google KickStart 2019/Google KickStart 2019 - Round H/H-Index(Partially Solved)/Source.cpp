#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 5000

/*int solve() {

    return 0;
}*/
        
int main() {
    /*#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif*/

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    int no = 0;
    while (t--) {
        int n;
        cin >> n;
        int a[n], x[n] = {0}, k = 0, aux = 0, i, j;
        std::vector<int> res;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < n; i++) {
            for (j = aux; j <= i; j++) {
                if (x[k] == k + 1) k++;
                if(a[j] > k) {
                    x[k]++;
                }
            }
            if (x[k] == k + 1) {
                res.push_back(x[k]);
                aux = 0;
            }
            else {
                res.push_back(x[k - 1]);
                aux = j;
            }
        }
        cout << "Case #" << ++no << ": ";
        for (int i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}