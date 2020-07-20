#include<bits/stdc++.h>
using namespace std;
#define i_64 long long

void solve(int t) {int n;
	cin >> n;
	vector<string> v(n);
	int mx = 0;
    string res = "";
    bool flag = 1;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		reverse(v[i].begin(),v[i].end());
		if(v[i].size() > v[mx].size()) {
			mx = i;
		}
	}
	for(int i = 0; i < v[mx].size(); i++){
		char c = v[mx][i];
		for(int j = 0; j < n; j++) {
			if(i < v[j].size() and (v[j][i] != c and v[j][i] != '*')) {
				flag = 0;
				break;
			}
		}
		if(!flag) {
			break;
		}
	}
	if(flag == 0)
		cout << "Case #" << t << ": *" << endl;
	else{
		res = v[mx].substr(0, v[mx].size() - 1);
		reverse(res.begin(), res.end());
		cout << "Case #" << t << ": " << res << "\n";
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    int i = 1;
    while (t - i >= 0) {
        solve(i);
        i++;
    }
    return 0;
}