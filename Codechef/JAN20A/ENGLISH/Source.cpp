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

int solve() {
    int n, m, a, r, b, c;
    accio >> n >> m >> a >> r;
    map<pair<int, int>, int> mp;
    vector<pair<int, int>> v;
    for(int i = 0; i < m; i++) {
        accio >> b >> c;
        v.pb({b, c});
        mp[{b, c}] = 1;
        mp[{c, b}] = 1;
    }
    vector<pair<pair<int, int>, int>> x;
    vector<pair<tuple<int, int, int>, int>> z;
    vector<pair<int, int>> y;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k  = 0; k < n; k++) {
                bool ver = false;
                if(mp[{i + 1, j + 1}] && mp[{j + 1, k + 1}] && mp[{i + 1, k + 1}]) {
                    for (int l = max(j, k) + 1; l < n; l++) {
                        if (mp[{j + 1, l + 1}] && mp[{k + 1, l + 1}] && mp[{i + 1, l + 1}]) {
                            ver = true;
                            mp[{i + 1, j + 1}] = 0, mp[{j + 1, i + 1}] = 0, mp[{i + 1, k + 1}] = 0, mp[{k + 1, i + 1}] = 0, mp[{j + 1, k + 1}] = 0, mp[{k + 1, j + 1}] = 0, mp[{k + 1, l + 1}] = 0, mp[{l + 1, k + 1}] = 0, mp[{j + 1, l + 1}] = 0, mp[{l + 1, j + 1}] = 0,  mp[{l + 1, i + 1}] = 0,  mp[{i + 1, l + 1}] = 0;
                            tuple <int, int, int> tt;
                            tt = make_tuple(j + 1, k + 1, l + 1);
                            z.pb({tt, i + 1});
                        }
                    }
                    if (ver == true)
                        continue;
                    mp[{i + 1, j + 1}] = 0, mp[{j + 1, i + 1}] = 0, mp[{i + 1, k + 1}] = 0, mp[{k + 1, i + 1}] = 0, mp[{j + 1, k + 1}] = 0, mp[{k + 1, j + 1}] = 0;
                    x.pb({{j + 1, k + 1}, i + 1});
                }
            }
        }
    }
    //tuple <int, int, int> tt;
    //tt = make_tuple(5, 5, 7);
    //z.pb({tt, 55});
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(mp[{i + 1, j + 1}] == 1) {
                mp[{i + 1, j + 1}] = 0;
                mp[{j + 1, i + 1}] = 0;
                y.pb({i + 1, j + 1});
            }
        }
    }
    int s(0);
    s = z.size() + x.size() + y.size();
    /*for (int i = 0; i < y.size(); i++) { 
        //cout << 1 << " ";
        //cout << 1 << " ";
        if (y[i + 1].second != y[i].second && y[i + 1].second != y[i].first && y[i + 1].first != y[i].second && y[i + 1].first != y[i].first )
        //cout << y[i].second << " ";
        //cout << y[i].first << endl;
            i++;
        s++;
    }*/
    cout << s << endl;
    int nnn = z.size();
    for (int i = 0; i < nnn; i++) {
        cout << 1 << " " << 3 << " ";
        cout << z[i].second << " " << get<0>(z[i].first) << " ";
        cout << z[i].second << " " << get<1>(z[i].first) << " ";
        cout << z[i].second << " " << get<2>(z[i].first) << endl;
    }
    //s = x.size();
    int xxx = x.size();
    /*for (int i = 0; i < xxx; i++) {
        std::map<int, int> cnt;
        cnt[x[i].first.second]++;
        cnt[x[i].first.first]++;
        cnt[x[i].first.second]++;
        cnt[x[i].second]++;
        int j = i + 1;
        if (cnt[x[j].first.second] == 0 && cnt[x[j].first.first] == 0 && cnt[x[j].first.second] == 0 && cnt[x[j].second] == 0 && j < xxx - 1) 
            i++;
        s++;
        /*cout << x[i].second << " ";
        cout << x[i].first.first << " ";
        cout << x[i].first.second << " ";
        cout << x[i].second << " ";
        int j = i;
        cout << x[i].first.first << " ";
        cout << x[i].second << endl;
    }*/   
    //int s = x.size() + y.size();
    //vector <vector <pair <int, int>> final;
    std::map<pair<int, int>, int> check;
    //int xxx = x.size();
    for (int i = 0; i < xxx; i++) {
        /*std::map<int, int> cnt;
        int count(2);
        std::vector<pair<int, int>> result;
        result.pb({x[i].first.second, x[i].first.first});
        result.pb({x[i].first.second, x[i].second});
        check[{x[i].first.second, x[i].first.first}] = 1;
        check[{x[i].first.second, x[i].second}] = 1;
        cnt[x[i].first.second]++;
        cnt[x[i].first.first]++;
        cnt[x[i].first.second]++;
        cnt[x[i].second]++;
        int j = i + 1;
        if (cnt[x[j].first.second] == 0 && cnt[x[j].first.first] == 0 && cnt[x[j].first.second] == 0 && cnt[x[j].second] == 0 && j < xxx - 1) {
            result.pb({x[j].first.second, x[j].first.first});
            result.pb({x[j].first.second, x[j].second});
            check[{x[j].first.second, x[j].first.first}] = 1; 
            check[{x[j].first.second, x[j].second}] = 1;
            count += 2;
            i++;
        }*/
        cout << 1 << " " << 2 << " ";
        /*for (int k = 0; k < count; k++) {
            cout << result[k].first << " " << result[k].second << " ";
        }*/
        cout << x[i].second << " ";
        cout << x[i].first.first << " ";
        cout << x[i].first.second << " ";
        cout << x[i].second << endl;
    }    
    int lll = y.size();
    for (int i = 0; i < lll; i++) { 
        cout << 1 << " ";
        cout << 1 << " ";
        cout << y[i].second << " ";
        cout << y[i].first << endl;
    }
    return 0;
}

int main() {
    //auto start=std::chrono::steady_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs
    #endif

    __AcHiLlEs

    int t(1);
    //accio >> t;
    while (t--) {
        solve();
    }
    
    /*auto end = std::chrono::steady_clock::now();
        double elapsed=double (std::chrono::duration_cast < std::chrono::nanoseconds> (end-start).count());
    std::cout << endl << "Terminated\n"<< elapsed/1e9;*/
    return 0;
}