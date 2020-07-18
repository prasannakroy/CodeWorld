/****************************************
  "Temp not a desperate man."
                    -William Shakespeare
 ****************************************/

/*****************************
 PRASANNA_K_ROY (prasanna2425)
 *****************************/

#include <bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);
#define pb push_back
#define i_64 unsigned long long
#define d_64 long double

const i_64 mod = 998244353;
const i_64 MAX = 1000001;


bool primeCheck(i_64 n) {
    if (n == 2 || n == 3 || n == 5) return true;
    if (n % 2 == 0 || n % 3 == 0) return false; 
  
    for (i_64 i = 5; i * i <= n; i += 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
           return false; 
    return true; 
}

i_64 power(i_64 x, i_64 y) { 
    if (y == 0) 
        return 1; 
    i_64 p = power(x, y / 2) % mod; 
    p = (p * p) % mod; 
    if (!(y & 1)) 
        return p;
    return (p * x) % mod; 
} 

i_64 Imod(i_64 a) { 
    i_64 res = (power(a, mod - 2)) % mod;
    return res;
}

i_64 nCr(i_64 n, i_64 r) { 
    vector<i_64> v(r + 1);
    i_64 c(1);
    v[0] = c;
    for(i_64 j = 1; j <= r; j++){
        i_64 l = Imod(j);
        v[j] = (((c * (n - j + 1)) % mod )* l) % mod;
        c = v[j];
    }
    return v[r]; 
}

struct operands {
    char x;
    i_64 zero, one, a, A, cnt, total;
    operands() {
        zero = 1;
        one = 1;
        a = 1;
        A = 1;
        cnt = 1;
        total = 4;
    }
};

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    i_64 aux = Imod(4);
    if (n <= 4) {
        cout << aux << " " << aux << " " << aux << " " << aux << "\n";
        return;
    }
    vector<operands> v(n);
    for (int i = 0; i < n; i++) v[i].x = s[i];
    stack<operands> st;
    for (int i = 0; i < n; i++) {
        if (v[i].x != ')') {
            st.push(v[i]);
        }
        else {
            operands first = st.top();
            st.pop();
            operands sign = st.top();
            st.pop();
            operands second = st.top();
            st.pop();
            operands res;
            if (sign.x == '&') {
                res.zero = (first.zero * second.total + second.zero * first.total + first.a * second.A + first.A * second.a - first.zero * second.zero) % mod;
                res.one = (first.one * second.one) % mod;
                res.a = (first.a * (second.one + second.a) + second.a * (first.one + first.a) - first.a * second.a) % mod;
                res.A = res.a;
                res.cnt = first.cnt + second.cnt;
            }
            else if (sign.x == '|') {
                res.one = (first.one * second.total + second.one * first.total + first.a * second.A + first.A * second.a - first.one * second.one) % mod;
                res.zero = (first.zero * second.zero) % mod;
                res.a = (first.a * (second.zero + second.a) + second.a * (first.zero + first.a) - first.a * second.a) % mod;
                res.A = res.a;
                res.cnt = first.cnt + second.cnt;
            }
            else {
                res.zero = ((first.one * second.one) % mod + (first.zero * second.zero) % mod + (first.a * second.a) % mod + (first.A * second.A) % mod) % mod;
                res.one = ((first.zero * second.one) % mod + (first.one * second.zero) % mod + (first.a * second.A) % mod + (first.A * second.a) % mod) % mod;
                res.a = ((first.zero * second.a) % mod + (first.one * second.A) % mod + (first.a * second.zero) % mod + (first.A * second.one) % mod) % mod;
                res.A = res.a;
                res.cnt = first.cnt + second.cnt;
            }
            st.pop();
            res.total = res.zero + res.one + res.a + res.A;
            st.push(res);
        }
    }
    i_64 sol(1);
    i_64 len = st.top().cnt;
    while (len--) {
        (sol *= aux) %= mod;
    }
    cout << (st.top().zero * sol) % mod << " " << (st.top().one * sol) % mod << " " << (st.top().a * sol) % mod << " " << (st.top().A * sol) % mod << "\n";
    return;
}

int main() {
    //auto start=std::chrono::steady_clock::now();
    /*#ifndef ONLINE_JUDGE 
        __AnAkLuSmOs
    #endif*/

    __AcHiLlEs
    
    srand(5);
    int t(1);
    cin >> t;
    while (t--) {
        solve();
    }
    
    /*auto end = std::chrono::steady_clock::now();
        double elapsed=double (std::chrono::duration_cast < std::chrono::nanoseconds> (end-start).count());
    std::cout << endl << "Terminated\n"<< elapsed/1e9;*/
    return 0;
}