/*****************************
*  Author :: Πρασαννα Κ. Ροι *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

template<typename t>
using minpq = priority_queue<t, vc<t>, greater<t>>;

template<typename t>
using maxpq = priority_queue<t>;

class Trie {
public: 
	vc<Trie*> child;
	int cnt;

	Trie() {
		child.assign(2, NULL);
		cnt = 0;
	}

	void addChild(int idx) {
		this->child[idx] = new Trie();
	}

	void addElement(string s) {
		int n = s.length();
		Trie *temp = this;
		for (int i = 0; i < n; i++) {
			int idx = s[i] - '0';
			if (temp->child[idx] == NULL) 
				temp->addChild(idx);
			temp = temp->child[idx];
		}
		temp->cnt++;
	}

	Trie* removeElement(string &s, int idx, int n) {
		Trie *temp = this;
		if (idx == n) {
		    temp->cnt--;
			if (temp->cnt == 0) 
				return NULL;
			return temp;
		}
		int val = s[idx] - '0';
		temp->child[val] = temp->child[val]->removeElement(s, idx + 1, n);
		if (temp->child[0] == NULL and temp->child[1] == NULL and temp->cnt == 0) 
			return NULL;
		return temp;
	}

	void removeElement(string &s) {
		this->removeElement(s, 0, s.length());
	}

	int getMaxXor(string s) {
		int res(0);
		Trie *temp = this;
		int n = s.length();
		for (int i = 0; i < n; i++) {
			int idx = 1 - s[i] + '0';
			if (temp->child[idx] != NULL) {
				res += (1 << (n - i - 1));
				temp = temp->child[idx];
			} else {
				temp = temp->child[1 - idx];
			}
		}
		return res;
	}

};

void solve() {
	int q;
	cin >> q;
	Trie *trie = new Trie();
	bitset<31> val(0);
	trie->addElement(val.to_string());
	while (q--) {
		char x;
		int n;
		cin >> x >> n;
		bitset<31> num(n);
		string s = num.to_string();
		if (x == '+') {
			trie->addElement(s);
		}
		else if (x == '-') {
			trie->removeElement(s);
		}
		else {
			cout << trie->getMaxXor(s) << '\n';
		}
	}
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1), st(0);
  // cin >> t;
  for (int i = st; i < t + st; /*cout << "Case #" << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}