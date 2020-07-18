/*
  "Temp not a desperate man."
                    -William Shakespeare
*/

#include <bits/stdc++.h>
#include <chrono>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);
#define accio cin
#define pb push_back
#define endl "\n"
#define i_64 long long
#define d_64 long double
#define u_64 unsigned long long

const int mod = (int)1e9 + 7;
const i_64 MAX = 1000001;

class BigInt {
private:
    string s;
    vector <int> v;
public:
    BigInt(){s = "";}
    BigInt(string x) {
        int l = x.length();
        for (int i = l - 1; i >= 0; i--) {
            int n = int(x[i] - '0');
            v.pb(n);
        }
    } 
    BigInt operator + (BigInt b) {
        int n1 = v.size();
        int n2 = b.v.size();
        int rem(0), i;
        if (n1 < n2) {
            for (i = 0; i < n1; i++) {
                int res = v[i] + b.v[i] + rem;
                b.v[i] = res % 10;
                rem = res / 10;
            }
            for (int j = i; j < n2; j++) {
                int res = b.v[i] + rem;
                b.v[i] = res % 10;
                rem = res / 10;
            }
            while (rem) {
                b.v.pb(rem  % 10);
                rem /= 10;
            }
        }
        else {
            for (i = 0; i < n2; i++) {
                int res = v[i] + b.v[i] + rem;
                b.v[i] = res % 10;
                rem = res / 10;
            }
            for (int j = i; j < n1; j++) {
                int res = v[i] + rem;
                b.v[i] = res % 10;
                rem = res / 10;
            }
            while (rem) {
                b.v.pb(rem  % 10);
                rem /= 10;
            }
        }
        return b;
    }
    friend ostream & operator << (ostream &output, const BigInt &a);
    friend istream & operator >> (istream &input, BigInt &b);
};

istream & operator >> (istream &input, BigInt &b) {
    input >> b.s;
    int l = b.s.length();
    for (int i = l - 1; i >= 0; i--) {
        int n = int(b.s[i] - '0');
        b.v.pb(n);
    }
    return input;
}

ostream & operator << (ostream &output, const BigInt &a) {
    int x = a.v.size();
    for (int i = x - 1; i >= 0; i--) {
        output << a.v[i];
    }
    return output;
}

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

i_64 fact(i_64 x) {
    if (x == 0 or x == 1)
        return 1;
    else 
        return (((x % mod) * (fact(x - 1)) % mod)) % mod;
}

int solve() {
    i_64 n, x, sum(0);
    accio >> n;
    std::vector<i_64> v;
    for (int i = 0; i < 2 * n; i++) 
        accio >> x, sum += x, v.pb(x);
    if (sum % (n + 1) != 0) {
        cout << 0 << endl;
        return 0;
    }
    sum /= (n+1);
    unordered_map<i_64,i_64> mp;
    for(int i=0;i<2*n;i++){
        mp[v[i]]++;
    }
    if (mp[sum] == 0) {
        cout << 0 << endl;
        return 0;
    }
    mp[sum]-=2;
    unordered_map<i_64, i_64> pmp;
    i_64 count(0), count1(0);
    i_64 res(1);
    //int s = sizeof(mp);
    for (auto it : mp) {
        x = it.first;
        if(mp[x]==0)continue;
        if (mp[x] != mp[sum-x] ){
            cout<<0<<endl;
            return 0;
        }
        if (x == sum - x) {
            count = (mp[x]) / 2;
            pmp[x] = count;
            res = ((res % mod) * (fact(pmp[x]) % mod)) % mod;
            mp[x]=0;
            continue;
        }
        pmp[x]=mp[x];
        res = ((res % mod) * (fact(pmp[x]) % mod)) % mod;
        mp[x]=0,mp[sum-x]=0;
    }
    //for (auto it: pmp) 
      //  cout << it.first << ":" << it.second << endl;
    if(pmp.size()==0) {
        cout<<"1\n";
        return 0;
    }
    i_64 res1 = power(2, n - count - 1) % mod;
    res1 = ((res1 % mod) * (fact(n - 1) % mod)) % mod;
    //cout << res << "<<" << res1 << endl;
    i_64 ans = Imod(res);
    //cout << ans << endl;
    ans = ((ans % mod) * (res1 % mod)) % mod;
    cout << ans << endl;
    return 0;
}

int main() {
    //auto start=std::chrono::steady_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs
    #endif

    __AcHiLlEs

    int t(1);
    accio >> t;
    while (t--) {
        solve();
    }
    
    /*auto end = std::chrono::steady_clock::now();
        double elapsed=double (std::chrono::duration_cast < std::chrono::nanoseconds> (end-start).count());
    std::cout << endl << "Terminated\n"<< elapsed/1e9;*/
    return 0;
}