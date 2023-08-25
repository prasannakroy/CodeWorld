// Author : Prasanna Kumar
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

void solve() {
    int n;
    cin >> n;
        
    multiset<int> st;
    multiset<int> mt;
    unordered_map<int, int> mp;
    vc<int> a(n);

    for (auto &i: a) {
        cin >> i;
        st.insert(i);
        mp[i]++;
    }

    int prev = -1;
    for (auto &i: st) {
        if (~prev and i - prev != 0)
            mt.insert(i - prev);
        prev = i;
    }

    int q;
    cin >> q;

    while (q--) {
        int idx, val;
        cin >> idx >> val;
        idx--;
        if (mp[a[idx]] == 1) {
        	auto lptr = st.lower_bound(a[idx]);
        	auto rptr = st.upper_bound(a[idx]);
        	int x(-1), y(-1);
		    if (lptr != st.begin()) {
		        --lptr;
		        x = *lptr;
		        auto loc = mt.find(a[idx] - x);
		        if (loc != mt.end())
		            mt.erase(loc);
		    } 
		    if (rptr != st.end()) {
		        y = *rptr;
		        auto loc = mt.find(y - a[idx]);
		        if (loc != mt.end()) 
		            mt.erase(loc);
		        if (x != -1) 
		            mt.insert(y - x);
		    }
        }
        st.erase(st.find(a[idx]));
        mp[a[idx]]--;
        a[idx] = val;
        if (!mp[a[idx]]) {
        	auto lptr = st.upper_bound(a[idx]);
	        auto rptr = st.upper_bound(a[idx]);
	        int x(-1), y(-1);
	        if (lptr != st.begin()) {
	            --lptr;
	            x = *lptr;
	        	mt.insert(a[idx] - x);
	        } 
	        if (rptr != st.end()) {
	            int y = *rptr;
	            mt.insert(y - a[idx]);
	            if (x != -1) {
	                auto loc = mt.find(y - x);
	                if (loc != mt.end())
	                    mt.erase(loc);
	            }
	        }
        }
        st.insert(a[idx]);
        mp[a[idx]]++;
        int res = *st.rbegin();
        if (!mt.empty())
            res += *mt.rbegin();
        cout << res << ' ';
    }
    cout << '\n';

}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1), st(0);
  cin >> t;
  for (int i = st; i < t + st; /*cout << "Case #" << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
  return 0;
}