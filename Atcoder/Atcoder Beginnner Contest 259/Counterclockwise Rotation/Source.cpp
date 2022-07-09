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

typedef complex<double> point;
#define x real()
#define y imag()

#define PI 3.1415926535897932384626

void solve() {
	point Q(0.0, 0.0);
	double n, m;
	int deg;
	cin >> n >> m >> deg;
	point P(n, m);

	double theta = (deg / 180.0) * PI;
	
	point P_rotated = (P-Q) * polar(1.0, theta) + Q;
	cout << fixed << setprecision(10) << P_rotated.x << " " << P_rotated.y << endl;
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