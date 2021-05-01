#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 3e5+5;
const int M = 3e5+5;
const int SQN = sqrt(N) + 1;

struct query{
	int l, r;
	int idx;
	int block;
	query(){}
	query(int _l, int _r, int _id){
		l = _l;
		r = _r;
		block = _l/SQN;
		idx = _id;
	}
	bool operator < (const query &b) const{
		if(block != b.block)
			return block < b.block;
		return r < b.r;
	}

};

query Q[M];
int ans[M];
int n, q;
int arr[N];
int freq[N], counter[N];

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n; i++)
		scanf("%d", arr+i);
	for(int i = 1;i <= q; i++){
		int l, r;
		scanf("%d%d", &l, &r);
		Q[i] = query(l, r, i);
	}
	sort(Q+1, Q+1+q);
	int curl = 1, curr = 0;
	int t_ans = 0;
	for(int i = 1;i <= q; i++){
		int l = Q[i].l;
		int r = Q[i].r;
		int idx = Q[i].idx;
		while(curr < r){
			++curr;
			int val = arr[curr];
			int c = freq[val];
			counter[c]--;
			freq[val]++;
			counter[freq[val]]++;
			t_ans = max(t_ans, freq[val]);
		}
		while(curl > l){
			--curl;
			int val = arr[curl];
			int c = freq[val];
			counter[c]--;
			freq[val]++;
			counter[freq[val]]++;
			t_ans = max(t_ans, freq[val]);
		}
		while(curr > r){
			int val = arr[curr];
			int c = freq[val];
			counter[c]--;
			freq[val]--;
			counter[freq[val]]++;
			while(counter[t_ans] == 0)	t_ans--;	
			--curr;
		}
		while(curl < l){
			int val = arr[curl];
			counter[freq[val]]--;
			freq[val]--;
			counter[freq[val]]++;
			while(counter[t_ans] == 0)	t_ans--;
			++curl;
		}
		int len = (r - l + 1);
		int val = t_ans;
		if (val <= (len + 1) / 2) ans[idx] = 1;
		else {
			int ll = len - val;
			if (!ll) {
				ans[idx] = val;
				continue;
			}
			val -= (ll + 1);
			ans[idx] = val;
			if (ll) ans[idx]++;
		}
	}
	for(int i = 1;i <= q; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}	