/****************************************
  "Temp not a desperate man."
                    -William Shakespeare
 ****************************************/

/*****************************
 PRASANNA_K_ROY (prasanna2425)
 *****************************/

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

i_64 isPerfectSquare(i_64 num) {
    if (num < 1) { 
        return false;
    }
    if (num == 1) {
        return true;
    }
    i_64 t = num / 2;
    while (t * t > num) {
        t = (t + num / t) / 2;
    }
    return t * t == num; 
}

i_64 primeFact(i_64 n) {
    int count(0);
    i_64 res(1);
    while (n % 2 == 0) {
        n /= 2;
        count++;
    }
    if (count & 1) {
        res *= 2;
    }
    count = 0;
    while (n % 3 == 0) {
        n /= 3;
        count++;
    }
    if (count & 1) {
        res *= 3;
    }
    for (i_64 i = 5; i * i <= n; i += 6) {
        count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }
        if (count & 1) {
            res *= i;
        }
        count = 0;
        while (n % (i + 2) == 0) {
            n /= (i + 2);
            count++;
        }
        if (count & 1) {
            res *= (i + 2);
        }
    }
    if (n > 2) {
        res *= n;
    }
    return res;
}

int solve() {
    i_64 n, m, flag0(0), countxp(0), countxn(0), countyp(0), countyn(0), res(0), mxx(0), mxy(0);
    accio >> n >> m;
    std::vector<i_64> xn, xp, yn, yp;
    std::unordered_map<i_64, i_64> mx, my, xmpp, xmpn, ympp, ympn;
    for (i_64 i = 0; i < n; ++i) {
        i_64 x;
        accio >> x;
        if (x == 0) {
            flag0 = 1;
            continue;
        }
        else if (x < 0) {
            xn.pb(-1 * x);
            xmpn[-1 * x] = primeFact(-1 * x);
            countxn++;
        }
        else {
            xp.pb(x);
            xmpp[x] = primeFact(x);
            countxp++;
        }
        mx[x * x]++;
        if (x * x > mxx) {
            mxx = x * x;
        }
    }
    for (i_64 i = 0; i < m; ++i) {
        i_64 y;
        accio >> y;
        if (y == 0) {
            flag0 = 1;
            continue;
        }
        else if (y < 0) {
            yn.pb(-1 * y);
            ympn[-1 * y] = primeFact(-1 * y);
            countyn++;
        }
        else {
            yp.pb(y);
            ympp[y] = primeFact(y);
            countyp++;
        }
        my[y * y]++;
        if (y * y > mxy) {
            mxy = y * y;
        }
    }
    if (flag0 == 1) {
        res = res + (countxp * countyp) + (countyp * countxn) + (countxn * countyn) + (countyn * countxp);
    }

    if (countxp < countxn) {
        for (i_64 i = 0; i < countxp; i++) {
            i_64 j = 1;
            while (xp[i] * j * j * xmpp[xp[i]] <= mxy) {
                if (xmpn[j * j * xmpp[xp[i]]] != 0 and my[xp[i] * j * j * xmpp[xp[i]]] != 0) {
                    res += my[xp[i] * j * j * xmpp[xp[i]]];
                }
                j++;
            }
        }
    }
    else {
        for (i_64 i = 0; i < countxn; i++) {
            i_64 j = 1;
            while (xn[i] * j * j * xmpn[xn[i]] <= mxy) {
                if (xmpp[j * j * xmpn[xn[i]]] != 0 and my[xn[i] * j * j * xmpn[xn[i]]] != 0) {
                    res += my[xn[i] * j * j * xmpn[xn[i]]];
                }
                j++;
            }
        }
    }

    if (countyp < countyn) {
        for (i_64 i = 0; i < countyp; i++) {
            i_64 j = 1;
            while (yp[i] * j * j * ympp[yp[i]] <= mxx) {
                if (ympn[j * j * ympp[yp[i]]] != 0 and mx[yp[i] * j * j * ympp[yp[i]]] != 0) {
                    res += mx[yp[i] * j * j * ympp[yp[i]]];
                }
                j++;
            }
        }
    }
    else {
        for (i_64 i = 0; i < countyn; i++) {
            i_64 j = 1;
            while (yn[i] * j * j * ympn[yn[i]] <= mxx) {
                if (ympp[j * j * ympn[yn[i]]] != 0 and mx[yn[i] * j * j * ympn[yn[i]]] != 0) {
                    res += mx[yn[i] * j * j * ympn[yn[i]]];
                }
                j++;
            }
        }
    }
    cout << res << endl;
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