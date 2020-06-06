#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_dec_float.hpp> 
#include <boost/math/constants/constants.hpp> 
  
using boost::multiprecision::cpp_dec_float_50; 

using namespace std;
#define ll long long
#define MAX 5000


bool isvowel(char c){
    if(c=='a' || c=='e' || c=='o' || c=='i' || c=='u' || c=='A' || c=='E' || c=='O' || c=='I' || c=='U')
        return true;
    return false;
}

bool checkChef(string s){
    for(int i=0;i<s.length()-1;i++){
        if(!isvowel(s[i])){
            if(!isvowel(s[i+1]))return false;
            else{
                if(i+1==s.length()-1)
                    return true;
                else if(!isvowel(s[i+2]))return false;
                else
                    i+=2;
            }
        }
    }
    return true;
}

        
int main(){
    /*#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif*/

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
        std::map<char, int> alice,bob;
        int a1=0,b1=0;
        int a[26]={0},b[26]={0};
        while(n--) {
            cin>>s;
            bool x = checkChef(s);
            if(x==0) {
                b1++;
                int flag[26]={0};
                for(int i=0;i<s.length();i++){
                    if(flag[s[i]-'a']==0){
                        b[s[i]-'a']++;
                        flag[s[i]-'a']=1;
                    }
                    bob[s[i]]++;
                }
            }
            else {
                a1++;
                int flag[26]={0};
                for(int i=0;i<s.length();i++) {
                    if(flag[s[i]-'a']==0) {
                        a[s[i]-'a']++;
                        flag[s[i]-'a']=1;
                    }
                    alice[s[i]]++;
                }
            }
        }
        setprecision(7);
        double r1=1,r2=1;
        for(int i=0;i<26;i++){
            if(a[i]!=0) r1*=(double)a[i];
        }
        for(int i=0;i<26;i++){
            if(b[i]!=0) r2*=(double)b[i];
        }
        cpp_dec_float_50 div1 = r1/r2;
        double p1=1,p2=1;
        for(auto i: alice)
            p1*=(double)i.second;
        for(auto i: bob)
            p2*=(double)i.second;
        cpp_dec_float_50 div2 = p2/p1;
        double mul;
        ll aux;
        if(a1==b1){
            div2=pow(div2,b1);
            mul=1;
            aux=0;
        }
        else if(a1>b1){
            mul = 1/p1;
            aux = a1-b1;
            div2=pow(div2,b1);
        }
        else{
            mul = p2;
            aux = b1-a1;
            div2=pow(div2,a1);
        }
        ll sol=0;
        for(int i=0; i<aux; i++){
            div2*=mul;
            if(div2*div1>(double)1e7){
                sol=1e7;
                exit;
            }
        }
        if(div2*div1>(double)1e7) sol=1e7;
        if(sol==1e7){
            cout<<"Infinity\n";
        }
        else{
            cout<<setprecision(7)<<fixed<<div2*div1<<endl;
        }
    }
    return 0;
}
