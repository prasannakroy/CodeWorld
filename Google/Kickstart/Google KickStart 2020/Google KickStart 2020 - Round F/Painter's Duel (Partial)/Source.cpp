/*****************************
*  Author :: Prasanna Kumra  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

map<pair<int, int>, int> m;

void solve(){
	int n, ra, pa, rb, pb, c; 
	cin >> n >> ra >> pa >> rb >> pb >> c;
	map<pair<int, int> , int> m;
	for(int i = 0; i < c; i++){
		int x, y; 
		cin >> x >> y;
		m[{x, y}] = 1;
	}
	if(rb == 1 and pb == 1){
		if(ra == 2 and pa == 1){
			int res = 0;
			if(m[{2, 2}] == 0){
				res++;
				if(m[{2, 3}] == 0)
					res++;
			}
			cout << res << "\n";
		}
		else if(ra == 2 and pa == 2){
			int res = 0;
			if(m[{2, 3}] == 0 or m[{2, 1}] == 0)
				res++;
			cout << res << "\n";
		}
		else{
			int res = 0;
			if(m[{2, 2}] == 0){
				res++;
				if(m[{2, 1}] == 0)
					res++;
			}
			cout << res << "\n";
		}
	}
	else if(rb == 2 and pb == 1){
		if(ra == 1 and pa == 1){
			int res = 0;
			if(m[{2, 2}] == 0){
				res++;
				if(m[{2, 3}] == 0)
					res++;
			}
			cout << res << "\n";
		}
		else if(ra == 2 and pa == 2){
			int res = 0;
			if(m[{2, 3}] == 0 or m[{1, 1}] == 0)
				res++;
			cout << res << "\n";
		}
		else{
			int res = 0;
			if(m[{2, 2}] == 0){
				res++;
				if(m[{1, 1}] == 0)
					res++;
			}
			cout << res << "\n";
		}
	}
	else if(rb == 2 and pb == 2){
		int res = 0;
		m[{ra, pa}] = 1;
		if(m[{1, 1}] == 0 or m[{2, 1}] == 0 or m[{2, 3}] == 0)
			res--;
		cout << res << "\n";
	}
	else{
		if(ra == 1 and pa == 1){
			int res = 0;
			if(m[{2, 2}] == 0){
				res++;
				if(m[{2, 1}] == 0)
					res++;
			}
			cout << res << "\n";
		}
		else if(ra == 2 and pa == 2){
			int res = 0;
			if(m[{2, 1}] == 0 or m[{1, 1}] == 0)
				res++;
			cout << res << "\n";
		}
		else{
			int res = 0;
			if(m[{2, 2}] == 0){
				res++;
				if(m[{1, 1}] == 0)
					res++;
			}
			cout << res << "\n";
		}
	}
}

signed main() {

    __AcHiLlEs

    int t(1);
    cin >> t;
    for (int i = 1; i <= t; cout << "Case #" << i << ": ", solve(), i++);
    return 0;
}
